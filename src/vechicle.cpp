#include "vechicle.hpp"

// float integral(float integratedValue, float timeStep);

Vechicle::Vechicle(): xPos(0), yPos(0), estimatedXPos(0), estimatedYPos(0) {
    // Docelowo do uzycia bedzie konstruktor z argumentami, jak zaczniemy podpinac piny
    Motor motorL1;
    Motor motorL2;
    Motor motorR1;
    Motor motorR2;
    TrackController trackController;
    MPU6050* mpu = new MPU6050(0x68);
 }

std::vector<std::string> Vechicle::tokenize(std::string s, std::string del = " ") {
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

    if(splittedMessage.size() == 1)
        move(splittedMessage.pop_back());
        // TODO - dokoczyn podzial wiadomosci dir1 dir2 + speed
    }
// _________TODO_________
// KONIECZNIE  ZAMOISTNEZATRZYMANIE ROBOTA 
void Vechicle::move(std::string direction) {
    if(direction == "forward") {
        moveForward();
    }
    else if(direction == "back") {
        moveBack();
    }
    else if(direction == "left") {
        moveLeft();
    }
    else if (direction == "right") {
        moveRight();
    }
    else if(direction == "stop") {
        moveStop();
    }
    else if(direction == "close") {
        std::cout<<"OK! I will close TCP connection and stop!"<<"\n";
    }
    else {
        moveStop();
        throw Exception("Vechicle", "Unknown command!");
    }
}


void Vechicle::move(int xTarget, int yTarget) {
    bool isFirtIteration = true;
    float deltaT;
    char rotate;
    if(xTarget < xPos) { //zalozenia: x+ do przodu, x- do tylu, y+ w prawo, y- w lewo, ale trzeba to sprawdzic
        moveForward();
        while(xTarget > yPos) {
            moveForward(); //zatrzymanie rotacji i jazda dalej
            if(isFirtIteration) {
                isFirtIteration = false;
                // pid.reset();
                currentPosReference = xPos;
                start_stopwatch = std::chrono::high_resolution_clock::now();
            }
            else
            {
                // stop = std::chrono::high_resolution_clock::now();
                // duration = stop - start;
                getPosition(&deltaT);
                rotate = trackController.ControllerCalculateOutput(currentPosReference-xPos, deltaT, 0);//zalozenie: w X jest 0, jak robot jedzie do przodu to jedzie wzdluz X
                if (rotate == 'r')
                {
                    rotateRight();
                }
                else
                {
                    rotateLeft();
                }
                // getPosition(duration.count(), sensor->getAccelX(), sensor->getAccelY(), sensor->getAngleX());
                // pid->PIDcalculateOutput(WARTOSC_W_TYM_PRZYPADKU - sensor->getAngleX(), duration.count());
                // start = std::chrono::high_resolution_clock::now();
            }
        }
    }
    else {
        moveBack();
        while(xTarget < xPos) {
            moveBack(); //zatrzymanie rotacji i jazda dalej
            if(isFirtIteration) {
                    isFirtIteration = false;
                    // pid.reset();
                    currentPosReference = yPos;
                    start_stopwatch = std::chrono::high_resolution_clock::now();
                }
            else
            {
                // stop = std::chrono::high_resolution_clock::now();
                // duration = stop - start;
                getPosition(&deltaT);
                rotate = trackController.ControllerCalculateOutput(currentPosReference-xPos, deltaT, 2);//zalozenie: w X jest 0, jak robot jedzie do tylu to jedzie wzdluz 180 stopni (-X)
                if (rotate == 'r')
                {
                    rotateRight();
                }
                else
                {
                    rotateLeft();
                }
                //pid->PIDcalculateOutput(WARTOSC_W_TYM_PRZYPADKU - sensor->getAngleX(), duration.count());
                // start = std::chrono::high_resolution_clock::now();
            }
            }
    }

    if(yTarget < yPos) {
        moveRight();
        while(yTarget < yPos) {
            moveRight(); //zatrzymanie rotacji i jazda dalej
            if(isFirtIteration) {
                isFirtIteration = false;
                // pid.reset();
                currentPosReference = xPos;
                start_stopwatch = std::chrono::high_resolution_clock::now();
            }
            else
            {
                // stop = std::chrono::high_resolution_clock::now();
                // duration = stop - start;
                getPosition(&deltaT);
                rotate = trackController.ControllerCalculateOutput(currentPosReference-yPos, deltaT, 3);//zalozenie: w X jest 0, jak robot jedzie w prawo to jedzie wzdluz 270 stopni (Y+)
                if (rotate == 'r')
                    {
                        rotateRight();
                    }
                else
                {
                    rotateLeft();
                }
                //pid->PIDcalculateOutput(WARTOSC_W_TYM_PRZYPADKU - sensor->getAngleX(), duration.count());
                // start = std::chrono::high_resolution_clock::now();
            }
        }
    }
    else {
        moveLeft();
        while(yTarget > yPos) {
            moveLeft(); //zatrzymanie rotacji i jazda dalej
            if(isFirtIteration) {
                isFirtIteration = false;
                // pid.reset();
                currentPosReference = xPos;
                start_stopwatch = std::chrono::high_resolution_clock::now();
            }
            else
            {
                // stop = std::chrono::high_resolution_clock::now();
                // duration = stop - start;
                getPosition(&deltaT);
                rotate = trackController.ControllerCalculateOutput(currentPosReference-yPos, deltaT, 1);//zalozenie: w X jest 0, jak robot jedzie w lewo to jedzie wzdluz 90 stopni (Y-)
                if (rotate == 'r')
                {
                    rotateRight();
                }
                else
                {
                    rotateLeft();
                }
                //pid->PIDcalculateOutput(WARTOSC_W_TYM_PRZYPADKU - sensor->getAngleX(), duration.count());
                // start = std::chrono::high_resolution_clock::now();
            }
        }
    }
    moveStop();
}


void Vechicle::moveForward() {
    motorL1.turnForward();
    motorL2.turnForward();
    motorR1.turnForward();
    motorR2.turnForward();
    sendMoveData();
    //dodac obsluge PID co bedzie korygowala tor jazdy
}
void Vechicle::moveBack() {
    motorL1.turnBack();
    motorL2.turnBack();
    motorR1.turnBack();
    motorR2.turnBack();
    sendMoveData();
    //dodac obsluge PID co bedzie korygowala tor jazdy
}
void Vechicle::moveLeft() {
    motorL1.turnBack();
    motorL2.turnForward();
    motorR1.turnForward();
    motorR2.turnBack();
    sendMoveData();
    //dodac obsluge PID co bedzie korygowala tor jazdy
}
void Vechicle::moveRight() {
    motorL1.turnForward();
    motorL2.turnBack();
    motorR1.turnBack();
    motorR2.turnForward();
    sendMoveData();
    //dodac obsluge PID co bedzie korygowala tor jazdy
}
void Vechicle::rotateLeft(){
    motorL1.turnBack();
    motorL2.turnBack();
    motorR1.turnForward();
    motorR2.turnForward();
    sendMoveData();
}
void Vechicle::rotateRight(){
    motorL1.turnForward();
    motorL2.turnForward();
    motorR1.turnBack();
    motorR2.turnBack();
    sendMoveData();
}
void Vechicle::moveStop() {
    motorL1.stop();
    motorL2.stop();
    motorR1.stop();
    motorR2.stop();
    sendMoveData();
}


void Vechicle::sendMoveData(){
    std::string module = "python3 sender.py ";
    std::string moveBitsToSend;
    moveBitsToSend = "ID0_" + motorL1.packDataToSend() + "\n";
    moveBitsToSend += "ID1_" + motorL2.packDataToSend() + "\n";
    moveBitsToSend += "ID2_" + motorR1.packDataToSend() + "\n";
    moveBitsToSend += "ID3_: " + motorR2.packDataToSend() + "\n";

    std::string command = module + moveBitsToSend;
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

// float integral(float integratedValue, float timeStep)
// {
//     return integratedValue*timeStep;
// }

void Vechicle::resetPosition() {
    xPos = 0;
    yPos = 0;
}

Vechicle::~Vechicle() {
    moveStop();
    resetPosition();
}