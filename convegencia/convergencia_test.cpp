#include "fd_method.h"
#include <iostream>
#include <cmath>

/*Se compara la convergencia del metodo con RK4.
Para esto, se resolvera la EDO de segundo orden:

	y'' + 8y' + 16y = 4sin(4x)

cuya solucion teorica con y(0) = y'(0) = 0 con x E [0,pi/2]

	y(x) = 0.25 * exp(-4*x) + x*exp(-4*x) - 0.25 * cos(4*x)
*/

double theoretical_sol(double);
double p(double);
double q(double);
double r(double);

int main(int argc, char const *argv[]){

	int N = 100;
	double xmin = 0, xmax = M_PI_2;
	FiniteDiff FDmethod(N);

	FDmethod.setInterval()

	return 0;
}


double theoretical_sol(double){
	return 0.25 * exp(-4 * x) + x * exp(-4 * x) - 0.25 * cos(4 * x);
}

double p(double){
	return -8;
}

double q(double){
	return -16;
}

double r(double){
	return 4 * sin(4 * x);
}

