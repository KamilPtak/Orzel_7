#include "vechicle.hpp"
#include "PID.hpp"
#include <cmath>
#include <chrono>

Vechicle::Vechicle(): xPos(0), yPos(0), estimatedXPos(0), estimatedYPos(0) {
    // Motor* motorL1 = new Motor(): enable(), dir1(), dir2() {}
    // Docelowo do uzycia bedzie konstruktor z argumentami, jak zaczniemy podpinac piny
    Motor* motorL1 = new Motor();
    Motor* motorL2 = new Motor();
    Motor* motorR1 = new Motor();
    Motor* motorR2 = new Motor();
    UART * uart = new UART("/dev/ttyS0", 9600);
    Sensor * sensor = new Sensor();
    PID * pid = new PID();
    // Kalman* kalman = new Kalman(); //do odkomentowania po implementacji klas
    // ADXL* adxl = new ADXL();
    // Gyro* gyro = new Gyro();
 }

 void Vechicle::resetPosition() {
    xPos = 0;
    yPos = 0;
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
    else {
        moveStop();
        throw Exception("Vechicle", "Unknown command!");
    }
}

void Vechicle::move(int xTarget, int yTarget) {
    std::chrono::high_resolution_clock::time_point start, stop;
    std::chrono::duration<double> duration;
    bool isFirtIteration = true;
    if(xTarget < xPos) {
        moveForward();
        while(xTarget < xPos) {
            if(isFirtIteration)
            {
                isFirtIteration = false;
                pid->reset();
                //pid->setPreviousError(WARTOSC_W_TYM_PRZYPADKU - sensor->getAngleX());
                start = std::chrono::high_resolution_clock::now();
            }
            else
            {
                stop = std::chrono::high_resolution_clock::now();
                duration = stop - start;
                getPosition(duration.count(), sensor->getAccelX(), sensor->getAccelY(), sensor->getAngleX());
                //pid->PIDcalculateOutput(WARTOSC_W_TYM_PRZYPADKU - sensor->getAngleX(), duration.count());
                start = std::chrono::high_resolution_clock::now();
            }
        // kalmanFilter -> getEstimatedPosition()
        // aktualizujemy pozycje robota
        }
    }
    else {
        moveBack();
        while(xTarget > xPos) {
            if(isFirtIteration)
                {
                    isFirtIteration = false;
                    pid->reset();
                    //pid->setPreviousError(WARTOSC_W_TYM_PRZYPADKU - sensor->getAngleX());
                    start = std::chrono::high_resolution_clock::now();
                }
                else
                {
                    stop = std::chrono::high_resolution_clock::now();
                    duration = stop - start;
                    getPosition(duration.count(), sensor->getAccelX(), sensor->getAccelY(), sensor->getAngleX());
                    //pid->PIDcalculateOutput(WARTOSC_W_TYM_PRZYPADKU - sensor->getAngleX(), duration.count());
                    start = std::chrono::high_resolution_clock::now();
                }
            }
    }

    if(yTarget < yPos) {
        moveRight();
        while(yTarget < yPos) {
            if(isFirtIteration)
            {
                isFirtIteration = false;
                pid->reset();
                //pid->setPreviousError(WARTOSC_W_TYM_PRZYPADKU - sensor->getAngleX());
                start = std::chrono::high_resolution_clock::now();
            }
            else
            {
                stop = std::chrono::high_resolution_clock::now();
                duration = stop - start;
                getPosition(duration.count(), sensor->getAccelX(), sensor->getAccelY(), sensor->getAngleX());
                //pid->PIDcalculateOutput(WARTOSC_W_TYM_PRZYPADKU - sensor->getAngleX(), duration.count());
                start = std::chrono::high_resolution_clock::now();
            }
        // kalmanFilter -> getEstimatedPosition()
        // aktualizujemy pozycje robota
    }
    }
    else {
        moveLeft();
        while(yTarget > yPos) {
            if(isFirtIteration)
            {
                isFirtIteration = false;
                pid->reset();
                //pid->setPreviousError(WARTOSC_W_TYM_PRZYPADKU - sensor->getAngleX());
                start = std::chrono::high_resolution_clock::now();
            }
            else
            {
                stop = std::chrono::high_resolution_clock::now();
                duration = stop - start;
                getPosition(duration.count(), sensor->getAccelX(), sensor->getAccelY(), sensor->getAngleX());
                //pid->PIDcalculateOutput(WARTOSC_W_TYM_PRZYPADKU - sensor->getAngleX(), duration.count());
                start = std::chrono::high_resolution_clock::now();
            }
        // kalmanFilter -> getEstimatedPosition()
        // aktualizujemy pozycje robota
        }
    }
    moveStop();
}

void Vechicle::sendMoveData(){
    std::string moveBitsToSend;
    moveBitsToSend = motorL1->packDataToSend() + motorL2->packDataToSend() + motorR1->packDataToSend() + motorR2->packDataToSend();
    uart->pushData(moveBitsToSend);
}

void Vechicle::moveForward() {
    motorL1->turnForward();
    motorL2->turnForward();
    motorR1->turnForward();
    motorR2->turnForward();
    sendMoveData();
    //dodac obsluge PID co bedzie korygowala tor jazdy
}
void Vechicle::moveBack() {
    motorL1->turnBack();
    motorL2->turnBack();
    motorR1->turnBack();
    motorR2->turnBack();
    sendMoveData();
    //dodac obsluge PID co bedzie korygowala tor jazdy
}
void Vechicle::moveLeft() {
    motorL1->turnBack();
    motorL2->turnForward();
    motorR1->turnForward();
    motorR2->turnBack();
    sendMoveData();
    //dodac obsluge PID co bedzie korygowala tor jazdy
}
void Vechicle::moveRight() {
    motorL1->turnForward();
    motorL2->turnBack();
    motorR1->turnBack();
    motorR2->turnForward();
    sendMoveData();
    //dodac obsluge PID co bedzie korygowala tor jazdy
}
void Vechicle::moveStop() {
    motorL1->stop();
    motorL2->stop();
    motorR1->stop();
    motorR2->stop();
    sendMoveData();
}

void Vechicle::printEsimatedPosition() {
    std::cerr<<"Estimated X position"<<estimatedXPos<<"\n";
    std::cerr<<"Estimated Y position"<<estimatedYPos<<"\n";
}

void Vechicle::getPosition(double deltaT, int accelX, int accelY, float angle)//sprawdzic jednostki !!!!!
{
    float tempX = accelX * cos(angle) + accelY * sin(angle);
    float tempY = accelX * cos(angle) - accelY * sin(angle);
    for(int i = 0; i<2; i++)
    {
        tempX = integral(tempX, deltaT);
        tempY = integral(tempY, deltaT);
    }
    xPos = tempX;
    yPos = tempY;
}

float integral(float integratedValue, float timeStep)
{
    return integratedValue*timeStep;
}

Vechicle::~Vechicle() {
    moveStop();
    resetPosition();
    delete motorL1;
    delete motorL2;
    delete motorR1;
    delete motorR2;
    delete uart;
    delete sensor;
    delete pid;
    // delete kalman; //Do odkodowania po implementacij klas
    // delete adxl;
    // delete gyro;
}