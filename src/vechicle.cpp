#include "vechicle.hpp"

// float integral(float integratedValue, float timeStep);

Vechicle::Vechicle(): xPos(0), yPos(0), estimatedXPos(0), estimatedYPos(0) {
    // Docelowo do uzycia bedzie konstruktor z argumentami, jak zaczniemy podpinac piny
    Motor motorL1;
    Motor motorL2;
    Motor motorR1;
    Motor motorR2;
    UART uart("/dev/ttyS0", 9600);
    PID pid;
    MPU6050* mpu = new MPU6050(0x68);
 }


void Vechicle::decodeMessageFromClient(std::string msg) {
    uint8_t pos = msg.find(" ");
    std::string dir1, dir2;

    if(pos > msg.length()){
        move(msg);
    }
    else {
        for(int i=0; i<msg.length(); i++) {
            if(i < pos) {
                dir1.push_back(msg[i]);
            }
            if(i > pos) {
                dir2.push_back(msg[i]);
            }
        }
        move(std::stoi(dir1), std::stoi(dir2));
    }
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
    float angle, deltaT;
    if(xTarget < xPos) { //zalozenia: y+ do przodu, y- do tylu, x+ w prawo, x- w lewo, ale trzeba to sprawdzic
        moveForward();
        while(xTarget > xPos) {
            if(isFirtIteration) {
                isFirtIteration = false;
                pid.reset();
                start_stopwatch = std::chrono::high_resolution_clock::now();
            }
            else
            {
                // stop = std::chrono::high_resolution_clock::now();
                // duration = stop - start;
                getPosition(&angle, &deltaT);
                pid.PIDcalculateOutput(angle, deltaT, 0);//zalozenie: w X jest 0, jak robot jedzie do przodu to jedzie wzdluz X
                // getPosition(duration.count(), sensor->getAccelX(), sensor->getAccelY(), sensor->getAngleX());
                // pid->PIDcalculateOutput(WARTOSC_W_TYM_PRZYPADKU - sensor->getAngleX(), duration.count());
                // start = std::chrono::high_resolution_clock::now();
            }
        }
    }
    else {
        moveBack();
        while(xTarget < xPos) {
            if(isFirtIteration) {
                    isFirtIteration = false;
                    pid.reset();
                    start_stopwatch = std::chrono::high_resolution_clock::now();
                }
                else
                {
                    // stop = std::chrono::high_resolution_clock::now();
                    // duration = stop - start;
                    getPosition(&angle, &deltaT);
                    pid.PIDcalculateOutput(angle, deltaT, 2);//zalozenie: w X jest 0, jak robot jedzie do tylu to jedzie wzdluz 180 stopni (-X)
                    //pid->PIDcalculateOutput(WARTOSC_W_TYM_PRZYPADKU - sensor->getAngleX(), duration.count());
                    // start = std::chrono::high_resolution_clock::now();
                }
            }
    }

    if(yTarget < yPos) {
        moveRight();
        while(yTarget < yPos) {
            if(isFirtIteration) {
                isFirtIteration = false;
                pid.reset();
                start_stopwatch = std::chrono::high_resolution_clock::now();
            }
            else
            {
                // stop = std::chrono::high_resolution_clock::now();
                // duration = stop - start;
                getPosition(&angle, &deltaT);
                pid.PIDcalculateOutput(angle, deltaT, 3);//zalozenie: w X jest 0, jak robot jedzie w prawo to jedzie wzdluz 270 stopni (Y+)
                //pid->PIDcalculateOutput(WARTOSC_W_TYM_PRZYPADKU - sensor->getAngleX(), duration.count());
                // start = std::chrono::high_resolution_clock::now();
            }
        }
    }
    else {
        moveLeft();
        while(yTarget > yPos) {
            if(isFirtIteration) {
                isFirtIteration = false;
                pid.reset();
                start_stopwatch = std::chrono::high_resolution_clock::now();
            }
            else
            {
                // stop = std::chrono::high_resolution_clock::now();
                // duration = stop - start;
                getPosition(&angle, &deltaT);
                pid.PIDcalculateOutput(angle, deltaT, 1);//zalozenie: w X jest 0, jak robot jedzie w lewo to jedzie wzdluz 90 stopni (Y-)
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
    std::string moveBitsToSend;
    moveBitsToSend = "MotorL1: " + motorL1.packDataToSend() + "\n";
    uart.pushData(moveBitsToSend);

    moveBitsToSend = "MotorL2: " + motorL2.packDataToSend() + "\n";
    uart.pushData(moveBitsToSend);

    moveBitsToSend = "MotorR1: " + motorR1.packDataToSend() + "\n";
    uart.pushData(moveBitsToSend);

    moveBitsToSend = "MotorR2: " + motorR2.packDataToSend() + "\n";
    uart.pushData(moveBitsToSend);
}


void Vechicle::printEsimatedPosition() {
    std::cerr<<"Estimated X position"<<estimatedXPos<<"\n";
    std::cerr<<"Estimated Y position"<<estimatedYPos<<"\n";
}

void Vechicle::getPosition(float *angle, float *deltaT)//sprawdzic jednostki !!!!!
{
    mpu->getAccel(ax, ay, az);
    mpu->getGyro(gR, gP, gY);
    float accelX = (*ax)*g;
    float accelY = (*ay)*g;
    stop_stopwatch = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = stop_stopwatch - start_stopwatch;
    // double deltaT = duration.count();
    *deltaT = duration.count();
    // float angle = (*gY)*deltaT; //yaw
    *angle = (*gY)*(*deltaT); //yaw
    float tempX = accelX * cos(*angle) + accelY * sin(*angle);
    float tempY = accelX * cos(*angle) - accelY * sin(*angle);
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