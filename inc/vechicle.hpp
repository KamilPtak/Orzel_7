#include <iostream>
#include <string>
#include <cmath>
#include <chrono>
#include <vector>
#include <set>
#include <thread>

#include "PID.hpp"
#include "myExceptions.hpp"
#include "MPU6050.h"

#pragma once

#define g 9.81 

class Vechicle {
    private:
        TrackController trackController;
        MPU6050* mpu;

        int xPos, yPos, currentPosReference;
        int estimatedXPos, estimatedYPos;
        float *ax, *ay, *az; //tutaj wpisywane beda dane z accel
        float *gR, *gP, *gY; //tutaj wpisywane beda dane z gyro
        std::chrono::high_resolution_clock::time_point start_stopwatch, stop_stopwatch;
        const std::set<std::string> commandSet;

        std::vector<std::string> tokenize(std::string s, std::string del);
        void runUartScript(std::string);

    public:
        Vechicle();
        void decodeMessageFromClient(std::string msg);
        void move(std::string direction);  
        void createPositionThread();
        void printEsimatedPosition();
        void resetPosition();
        void getPosition(); //gyro daje w stopnie/s

        ~Vechicle();
};