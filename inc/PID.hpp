#include <iostream>

#pragma once

class PID {
	private:
		const int k;
		const int Ti;
		const int Td;
		double integral, previousError;
	public:
		PID();
		void PIDcalculateOutput(double error, double deltaT);//jak zaimpelemntowac liczenie sterowania na poszczegolne kola???
		void reset();
		void setPreviousError(double e);
};


