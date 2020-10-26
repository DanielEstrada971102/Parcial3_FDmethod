#include "fd_method.h"
#include <iostream>
#include <cmath>


double p(double);
double q(double);
double r(double);

int main(int argc, char const *argv[]){
	
	int N = 9;
	double x[N+1]; 
	double w[N+1];
	FiniteDiff EDproblem(N);

	EDproblem.setInterval(1.0, 2.0);
	EDproblem.setBoundaryCond(1.0, 2.0);
	EDproblem.setP(p);
	EDproblem.setQ(q);
	EDproblem.setR(r);

	EDproblem.solve(x, w);	

	for (int i = 0; i <= N+1; i++) cout << x[i] << "    " << w[i] << endl;


	return 0;
}


double p(double x){
	return -2.0 / x;
}

double q(double x){
	return 2.0 / (x*x);
}

double r(double x){
	return sin(log(x)) / (x*x);	
}
