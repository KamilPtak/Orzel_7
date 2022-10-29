#include <vector>
#include <string>

#pragma once

class Motor {
    private:
        int speed; // PWM 0-100
        bool dir1, dir2; 
        const uint8_t enablePin, dir1Pin, dir2Pin; // numery pinow do mostka H

        static uint8_t motorID;
        uint8_t id;
    public:
        Motor();
        Motor(uint8_t enable_, uint8_t dir1_, uint8_t dir2_);

        void setSpeed(int speed_);
        void stop(); // Emergency stop
        void turnForward();
        void turnBack();
        uint8_t getMotorID() {return id;}

        inline const std::string boolToString(bool b);
        std::string packDataToSend();
};

