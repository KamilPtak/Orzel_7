#include "motor.hpp"

Motor::Motor(uint8_t enablePin_, uint8_t dir1Pin_, uint8_t dir2Pin_): speed(0), enablePin(enablePin_), dir1Pin(dir1Pin_), dir2Pin(dir2Pin_) {}

void Motor::setSpeed(int speed_) {
    speed = speed_;
}

void Motor::stop() {
    enable = 0;
}

void Motor::turnForward() {}
void Motor::turnBack() {}
