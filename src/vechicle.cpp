#include "vechicle.hpp"

// float integral(float integratedValue, float timeStep);

Vechicle::Vechicle(): xPos(0), yPos(0), estimatedXPos(0), estimatedYPos(0), commandSet(std::set<std::string> 
    {"forward", "back", "left", "right", "stop", "L", "R"}) {
    TrackController trackController;
    MPU6050* mpu = new MPU6050(0x68);
 }

std::vector<std::string> Vechicle::tokenize(std::string s, std::string del) {
    std::vector<std::string> wordList;
    int start, end = -1*del.size();
    do {
        start = end + del.size();
        end = s.find(del, start);
        wordList.push_back(s.substr(start, end - start));
    } while (end != -1);
    return wordList;
}

void Vechicle::decodeMessageFromClient(std::string msg) {
    std::vector<std::string> splittedMessage;
    splittedMessage = tokenize(msg, "_");

    if(splittedMessage.size() == 1) {
        move(splittedMessage.back());
    }
    else if (splittedMessage.size() == 2) {
        std::string msg1 = splittedMessage[0];
        if(msg1 == "speed") {
            std::string msg2 = splittedMessage[1];
            runUartScript(msg1 + "_" + msg2);
        }
        std::cout<<"Wrong entry"<<"\n";
    }
    else {
        std::cout<<"Wrong entry"<<"\n";
    }
}

void Vechicle::move(std::string msg) {
    if(commandSet.find(msg) !=  commandSet.end()) {
        runUartScript(msg);
    }
    else {
        std::cout<<"Unknown command!"<<"\n";
    }
}

void Vechicle::runUartScript(std::string msg){
    std::string module = "python3 sender.py ";
    std::string command = module + msg + "\n";
    const char* cmd = command.c_str();
    system(cmd);
}


void Vechicle::printEsimatedPosition() {
    std::cerr<<"Estimated X position"<<estimatedXPos<<"\n";
    std::cerr<<"Estimated Y position"<<estimatedYPos<<"\n";
}

void Vechicle::getPosition(float *deltaT)//sprawdzic jednostki !!!!!
{
    mpu->getAccel(ax, ay, az);
    mpu->getGyro(gR, gP, gY);
    float accelX = (*ax)*g;
    float accelY = (*ay)*g;
    stop_stopwatch = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = stop_stopwatch - start_stopwatch;
    // double deltaT = duration.count();
    *deltaT = duration.count();
    float angle = (*gY)*(*deltaT); //yaw
    // *angle = (*gY)*(*deltaT); //yaw
    float tempX = accelX * cos(angle) + accelY * sin(angle);
    float tempY = accelX * cos(angle) - accelY * sin(angle);
    for(int i = 0; i<2; i++)
    {
        // tempX += integral(tempX, *deltaT);
        // tempY += integral(tempY, *deltaT);
        tempX += tempX*(*deltaT);
        tempY += tempY*(*deltaT);
    }
    xPos += tempX;
    yPos += tempY;
    start_stopwatch = std::chrono::high_resolution_clock::now();
}

void Vechicle::resetPosition() {
    xPos = 0;
    yPos = 0;
}

Vechicle::~Vechicle() {
    resetPosition();
}