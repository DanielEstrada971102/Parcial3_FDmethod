#include "fd_method.h"
#include <iostream>


double p(double);
double q(double);
double r(double);

int main(int argc, char const *argv[]){
	
	int N = 100;
	double x[N+1], w[N+1];
	FiniteDiff EDproblem(N);

	EDproblem.setInterval(0.0, 5.0);
	EDproblem.setBoundaryCond(1.0, 27.8);
	EDproblem.setP(p);
	EDproblem.setQ(q);
	EDproblem.setR(r);

	EDproblem.solve(x, w);

	return 0;
}


double p(double x){
	/* your code here */ 
	return 0;
}

double q(double x){
	/* your code here */ 
	return 0;
}

double r(double x){
	/* your code here */ 
	return 0;	
}
