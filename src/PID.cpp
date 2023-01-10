#include "PID.hpp"

PID::PID(): integral(0), previousError(0){};

void PID::PIDcalculateOutput(float error, float deltaT, int direction)//jak zaimpelemntowac liczenie sterowania na poszczegolne kola???
{
    double output = k*(error+1/Ti*error*deltaT+(error-previousError)/deltaT);

    switch (direction)
    {
        case 0: //do przodu
    }
    //dekodowanie sterowania, czyli jak minus to jakie kolo przyspieszane/spowalniane itp
}

void PID::reset()
{
    integral = 0;
    previousError = 0;
}