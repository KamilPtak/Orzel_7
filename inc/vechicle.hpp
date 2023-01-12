#include <iostream>
#include <string>
#include <cmath>
#include <chrono>

#include "motor.hpp"
#include "PID.hpp"
#include "myExceptions.hpp"
#include "MPU6050.h"

#pragma once

#define g 9.81 

class Vechicle {
    private:
        Motor motorR1;
        Motor motorR2;
        Motor motorL1;
        Motor motorL2;
        PID pid;
        MPU6050* mpu;

        int xPos, yPos;
        int estimatedXPos, estimatedYPos;

        float *ax, *ay, *az; //tutaj wpisywane beda dane z accel
        float *gR, *gP, *gY; //tutaj wpisywane beda dane z gyro

        std::chrono::high_resolution_clock::time_point start_stopwatch, stop_stopwatch;

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
        void rotateLeft();
        void rotateRight();
        
        void pushData(std::string msg);

        void printEsimatedPosition();
        void resetPosition();
        void getPosition(float *angle, float *deltaT); //gyro daje w stopnie/s
        void sendMoveData();

        ~Vechicle();
};