#include <iostream>
#include <string>

#include "motor.hpp"
#include "adxl345.hpp"
#include "uart.hpp"
#include "myExceptions.hpp"

#pragma once

class Vechicle {
    private:
        Motor* motorR1;
        Motor* motorR2;
        Motor* motorL1;
        Motor* motorL2;
        UART* uart;
        int xPos, yPos;
        int estimatedXPos, estimatedYPos;

    public:
        Vechicle();
        //TODO - okreslenie ile ma trwac skecanie kolami 
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
        int getPosition();
        void sendMoveData();

        ~Vechicle();
};