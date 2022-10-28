#include "motorControl.hpp"

void Vechicle::move(std::string direction) {
    if(direction == "left") {
        moveForward();
    }
    else if(direction == "right") {
        moveRight();
    }
    else if(direction == "forward") {
        moveForward();
    }
    else {
        moveBack();
    }
}

void Vechicle::moveForward() {
    motorL1.turnForward();
    motorL2.turnForward();
    motorR1.turnForward();
    motorR2.turnForward();
}
void Vechicle::moveLeft() {}
void Vechicle::moveBack() {}
void Vechicle::moveRight() {}

Motor::Motor(uint8_t enable_, uint8_t dir1_, uint8_t dir2_): speed(0), enable(enable_), dir1(dir1_), dir2(dir2_) {}




void Motor::setSpeed(int speed_) {
    speed = speed_;
}

void Motor::turnForward() {}
void Motor::turnBack() {}
