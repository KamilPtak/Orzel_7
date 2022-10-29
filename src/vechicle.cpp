#include <iostream>

#include "vechicle.hpp"
#include "myExceptions.hpp"

Vechicle::Vechicle(): xPos(0), yPos(0), estimatedXPos(0), estimatedYPos(0) {
    // Motor* motorL1 = new Motor(): enable(), dir1(), dir2() {}
    // Docelowo do uzycia bedzie konstruktor z argumentami, jak zaczniemy podpinac piny
    Motor* motorL1 = new Motor();
    Motor* motorL2 = new Motor();
    Motor* motorR1 = new Motor();
    Motor* motorR2 = new Motor();
 }

 void Vechicle::resetPosition() {
    xPos = 0;
    yPos = 0;
 }

void Vechicle::move(std::string direction) {
    if(direction == "forward") {
        moveForward();
    }
    else if(direction == "back") {
        moveBack();
    }
    else if(direction == "left") {
        moveLeft();
    }
    else if (direction == "right") {
        moveRight();
    }
    else if(direction == "close") {
        moveStop();
    }
    else {
        throw Exception("Vechicle", "Unknown command!");
    }
}

void Vechicle::move(int xTarget, int yTarget) {

    if(xTarget < xPos) {
        moveForward();
        while(xTarget < xPos) {
        // kalmanFilter -> getEstimatedPosition 
        // aktualizujemy pozycje robota
        }
    }
    else {
        moveBack();
        while(xTarget > xPos) {
        // kalmanFilter -> getEstimatedPosition 
        // aktualizujemy pozycje robota
        }
    }

    if(yTarget < yPos) {
    moveRight();
    while(yTarget < yPos) {
    // kalmanFilter -> getEstimatedPosition 
    // aktualizujemy pozycje robota
    }
    }
    else {
        moveLeft();
        while(yTarget > yPos) {
        // kalmanFilter -> getEstimatedPosition 
        // aktualizujemy pozycje robota
        }
    }
}

void Vechicle::moveForward() {
    motorL1->turnForward();
    motorL2->turnForward();
    motorR1->turnForward();
    motorR2->turnForward();
}
void Vechicle::moveBack() {
    motorL1->turnBack();
    motorL2->turnBack();
    motorR1->turnBack();
    motorR2->turnBack();
}
void Vechicle::moveLeft() {
    motorL1->turnBack();
    motorL2->turnForward();
    motorR1->turnForward();
    motorR2->turnBack();
}
void Vechicle::moveRight() {
    motorL1->turnForward();
    motorL2->turnBack();
    motorR1->turnBack();
    motorR2->turnForward();
}
void Vechicle::moveStop() {
    motorL1->stop();
    motorL2->stop();
    motorR1->stop();
    motorR2->stop();
}

void Vechicle::printEsimatedPosition() {
    std::cerr<<"Estimated X position"<<estimatedXPos<<"\n";
    std::cerr<<"Estimated Y position"<<estimatedYPos<<"\n";
}

Vechicle::~Vechicle() {
    moveStop();
    resetPosition();
}