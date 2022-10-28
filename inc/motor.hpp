#include <vector>
#include <string>
#pragma once

class Motor {
    private:
        int speed; // PWM 0-100
        uint8_t enable, dir1, dir2; 
        const uint8_t enablePin, dir1Pin, dir2Pin; // numery pinow do mostka H

    public:
        Motor(): enablePin(0), dir1Pin(0), dir2Pin(2) {}
        Motor(uint8_t enable_, uint8_t dir1_, uint8_t dir2_);

        void setSpeed(int speed_);
        void stop(); // Emergency stop
        void turnForward();
        void turnBack();

};


//TODO - klasa akcelerometru 
// class Accelerometr {
//     private:
//     public:
// };


