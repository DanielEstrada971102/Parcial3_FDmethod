#include "fd_method.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
/*Se compara la convergencia del metodo con RK4.
Para esto, se resolvera la EDO de segundo orden:

	y'' + 8y' + 16y = 4sin(4x)

cuya solucion teorica con y(0) = y(pi/8) = 0 con x E [0,pi/8]

	y(x) = 0.25 * exp(-4*x) - 0.25 * cos(4*x)
*/

double theoretical_sol(double);
double p(double);
double q(double);
double r(double);

int main(int argc, char const *argv[]){

	int N = 100;
	double xmin = 0, xmax = 0.5 * M_PI_4;
	double ymin = 0, ymax = 0;
	FiniteDiff FDmethod(N);
	double x[N+1], y_fdSol[N+1];
	ofstream OutFIle("solutions.txt");

	if (OutFIle.fail()){
		cout << "Error: Archivo" << endl;
		exit(0);
	}


	FDmethod.setInterval(xmin, xmax);
	FDmethod.setBoundaryCond(ymin,ymax);
	FDmethod.setP(p);
	FDmethod.setQ(q);
	FDmethod.setR(r);

	FDmethod.solve(x, y_fdSol);

	OutFIle << left << setw(15) << "#X" << setw(15) << "Y";
	OutFIle << setw(15) << "YFD" << setw(15) << "YRK4" << endl;

	for (int i = 0; i < N+1; i++){
		
		OutFIle << left << setw(15) << x[i] << setw(15) << theoretical_sol(x[i]);
		OutFIle << setw(15) << y_fdSol[i] << setw(15) << 0 << endl;
	}

	OutFIle.close();


	return 0;
}


double theoretical_sol(double x){
	return 0.25 * exp(-4 * x) - 0.25 * cos(4 * x);
}

double p(double x){
	return -8;
}

double q(double x){
	return -16;
}

double r(double x){
	return 4 * sin(4 * x);
}

