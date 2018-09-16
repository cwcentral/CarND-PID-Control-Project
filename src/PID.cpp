#include "PID.h"

using namespace std;

/*
 * TODO: Complete the PID class.
 */
PID::PID() {
}

PID::~PID() {
}

void PID::Init(double Kp, double Ki, double Kd) {
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;
	this->p_error = 0;
	this->i_error = 0.;
	this->d_error = 0.;
}
void PID::UpdateError(double error) {

	// See lesson 12

	static double last_error = 0;
	static double i_sum = 0;

	// proportional
	p_error = Kp * error;

	// derivative
	d_error = Kd * (error - last_error);
	last_error = error;

	// integral
	i_sum += error;
	i_error = Ki * i_sum;

}

double PID::TotalError() {

	// lesson 11
	return p_error + i_error + d_error;
}

