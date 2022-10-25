#include "motorControl.hpp"

void Vechicle::move(std::string direction) {
    if(direction == "left") {
        moveForward();
    }
    else if(direction == "right") {
        moveRight();
    }
    else {
        moveForward();
    }
}

void Vechicle::moveForward() {}
void Vechicle::moveLeft() {}
void Vechicle::moveRight() {}

Motor::Motor(uint8_t enable_, uint8_t dir1_, uint8_t dir2_): speed(0), enable(enable_), dir1(dir1_), dir2(dir2_) {}

void Motor::setSpeed(int speed_) {
    speed = speed_;
}
