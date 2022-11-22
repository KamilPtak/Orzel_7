#include "PID.hpp"

PID::PID(): k(1), Ti(1), Td(1), integral(0), previousError(0){};

void PID::PIDcalculateOutput(double error, double deltaT)//jak zaimpelemntowac liczenie sterowania na poszczegolne kola???
{
    double output = k*(error+1/Ti*error*deltaT+(error-previousError)/deltaT);
    //dekodowanie sterowania, czyli jak minus to jakie kolo przyspieszane/spowalniane itp
}