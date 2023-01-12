#include <iostream>

#pragma once

class TrackController {
	// private:
	// 	const int k = 1;
	// 	const int Ti = 1;
	// 	const int Td = 1;
	// 	double integral, previousError;
	public:
		// PID();
		// void PIDcalculateOutput(int error, float deltaT, int direction);//jak zaimpelemntowac liczenie sterowania na poszczegolne kola???
		char ControllerCalculateOutput(int error, float deltaT, int direction);
		// void reset();
		// void setPreviousError(double e);
};


