#include "trackController.hpp"

char TrackController::ControllerCalculateOutput(int error, float deltaT, int direction)
{
    //ODWORTNIE DO WSKAZOWEK ZEGARA JEST MINUS NA ZYROSKOPIE, ZGODNIE JEST PLUS
    switch (direction)
    {
        case 0: //do przodu, error>0 - za bardzo w lewo, error<0 - za bardzo w prawo
            if (error>0) {return 'r';}
            else if (error<0) {return 'l';}
        case 1: //w lewo, error>0 - za bardzo w dol, error<0 - za bardzo w gore
            if (error>0) {return 'r';}
            else if (error<0) {return 'l';}
        case 2: // do tylu, errory na odwrot jak do przodu
            if (error<0) {return 'r';}
            else if (error > 0) {return 'l';}
        case 3: //w prawo. odwrotnie jak w lewo
            if (error>0) {return 'l';}
            else if (error<0) {return 'r';}
        default:
            return 'r';      
    }
}