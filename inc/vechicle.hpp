#include "motor.hpp"

class Vechicle {
    private:
        Motor* motorR1;
        Motor* motorR2;
        Motor* motorL1;
        Motor* motorL2;

        int xPos, yPos;
        int estimatedXPos, estimatedYPos;

    public:
        Vechicle();

        //TODO - okreslenie ile ma trwac skecanie kolami 
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

        ~Vechicle();
};