#include "motor.hpp"

uint8_t Motor::motorID = 0;

Motor::Motor(): enablePin(0), dir1Pin(1), dir2Pin(2), id(motorID++){
    speed = 0;
    dir1 = false;
    dir2 = false;
}

Motor::Motor(uint8_t enablePin_, uint8_t dir1Pin_, uint8_t dir2Pin_): speed(0), enablePin(enablePin_), dir1Pin(dir1Pin_), dir2Pin(dir2Pin_), id(motorID++) {
    speed = 0;
    dir1 = false;
    dir2 = false;
}

void Motor::setSpeed(int speed_) {
    speed = speed_;
}

void Motor::stop() {
    speed = 0;
    dir1 = false;
    dir2 = false;
}

void Motor::turnForward() {
    dir1 = true;
    dir1 = false;
}
void Motor::turnBack() {
    dir1 = false;
    dir1 = true;
}

inline const std::string Motor::boolToString(bool b){
    return b ? "true " : "false";
}

std::string Motor::packDataToSend() {
    std::string steeringData;
    steeringData = " Speed: " + std::to_string(speed) + " dir1: " + boolToString(dir1) + " dir2: " + boolToString(dir2);
    return steeringData;
}


