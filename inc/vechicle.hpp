#include <iostream>
#include <string>
#include <cmath>
#include <chrono>

#include "motor.hpp"
#include "uart.hpp"
#include "PID.hpp"
#include "myExceptions.hpp"
// #include "libSensor.hpp"
#include "MPU6050.h"

#pragma once

class Vechicle {
    private:
        Motor* motorR1;
        Motor* motorR2;
        Motor* motorL1;
        Motor* motorL2;
        UART* uart;
        // Sensor* sensor;
        PID* pid;
        MPU6050* mpu;

        int xPos, yPos;
        int estimatedXPos, estimatedYPos;

    public:
        Vechicle();
        void decodeMessageFromClient(std::string msg);
        void move(std::string direction);  
        void move(int xTarget, int yTarget);

        void moveForward();
        void moveBack();
        void moveLeft();
        void moveRight();
        void moveStop();

        void printEsimatedPosition();
        void resetPosition();
        void getPosition(double deltaT, int accelX, int accelY, float angle);
        void sendMoveData();

        ~Vechicle();
};