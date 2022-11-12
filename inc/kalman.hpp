#include "userTypeDefs.hpp"
#pragma once

class Kalman {
	private:
		  //   A - System dynamics matrix
  		  //   C - Output matrix
		  //   Q - Process noise covariance
		  //   R - Measurement noise covariance
		  //   P - Estimate error covariance		
		const matrix A, C, Q, R, P;
	public:
		Kalman();
		Kalman(matrix& A_, matrix& C_, matrix& Q_, matrix& R_, matrix& P_);
		// ~Kalman();
};


