#include <vector>
#include <string>
#pragma once

class Motor {
    private:
        int speed; // PWM 0-100
        uint8_t enable, dir1, dir2; // numery pinow do mostka H

    public:
        Motor(uint8_t enable_, uint8_t dir1_, uint8_t dir2_);

        void setSpeed(int speed_);
        void stop(); // Emergency stop
        void turnForward();
        void turnBack();

};


//TODO - klasa akcelerometru 
class Accelerometr {
    private:
    public:
};


class Vechicle {
    private:
        Motor motorR1;
        Motor motorR2;
        Motor motorL1;
        Motor motorL2;

    public:
        Vechicle();

        //TODO - okreslenie ile ma trwac skecanie kolami 
        void move(std::string direction);  
        void moveForward();
        void moveBack();
        void moveLeft();
        void moveRight();
};