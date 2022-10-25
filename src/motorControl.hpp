#include <vector>
#include <string>
#pragma once

class Vechicle {
    private:
        Motor rightMotor;
        Motor leftMotor;

    public:
        Vechicle();

        //TODO - okreslenie ile ma trwac skecanie kolami 
        void move(std::string direction);  
        void moveForward();
        void moveLeft();
        void moveRight();
};

class Motor {
    private:
        int speed; // PWM 0-100
        uint8_t enable, dir1, dir2; // numery pinow do mostka H

    public:
        Motor(uint8_t enable_, uint8_t dir1_, uint8_t dir2_);

        void setSpeed(int speed_);
        void stop(); // Emergency stop

};


//TODO - klasa akcelerometru 
class Accelerometr {
    private:
    public:
};