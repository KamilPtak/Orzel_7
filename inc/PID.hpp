#include <iostream>

#pragma once

class PID {
	private:
		const int k = 1;
		const int Ti = 1;
		const int Td = 1;
		double integral, previousError;
	public:
		PID();
		void PIDcalculateOutput(float error, float deltaT, int direction);//jak zaimpelemntowac liczenie sterowania na poszczegolne kola???
		void reset();
		// void setPreviousError(double e);
};


