#include "fd_method.h"
#include <iostream>


FiniteDiff::FiniteDiff(int N){
	n = N;
	setH();
}

void FiniteDiff::setH(){
	h = (b - a) / n;
}

void FiniteDiff::setInterval(double xmin, double xmax){
	a = xmin;
	b = xmax;
}

void FiniteDiff::setBoundaryCond(double ymin, double ymax){
	alpha = ymin;
	beta = ymax;
}

void FiniteDiff::setP(double (*function)(double)){
	p = function;
}

void FiniteDiff::setQ(double (*function)(double)){
	q = function;
}

void FiniteDiff::setR(double (*function)(double)){
	r = function;
}

void FiniteDiff::solve(double *x, double *w){
	calcule_EqSys();
	croutFactorization(x, w);
}

void FiniteDiff::calcule_EqSys(){

	/* your code here */

}

void FiniteDiff::croutFactorization(double *x, double *w){

	/* your code here */
	
}