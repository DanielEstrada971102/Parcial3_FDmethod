#include "fd_method.h"
#include <iostream>

FiniteDiff::FiniteDiff(int N){
	n = N;
	setH();
}

void FiniteDiff::setH(){
	h = (b - a) / (n + 1);
}

void FiniteDiff::setInterval(double xmin, double xmax){
	a = xmin;
	b = xmax;
	setH();
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
	calcule_EqSys(x);
	croutFactorization(w);
}

void FiniteDiff::calcule_EqSys(double *x){
	int i;
	x[0] = a;
	x[1] = a + h;

	A.push_back( 2  + h*h * q(x[1]));
	B.push_back( -1  + .5 * h * p(x[1]));	
	D.push_back( - h*h * r(x[1]) + ((1 + .5 * h) * p(x[1])) * alpha );

	for (i = 2; i <= n-1 ; i++){
		x[i] = a + i * h;
		A.push_back( 2  + h*h * q(x[i]));
		B.push_back( -1  + .5 * h * p(x[i]));
		C.push_back( -1  - .5 * h * p(x[i]));	
		D.push_back( - h*h * r(x[i]) );
	}

	x[n] = b - h;
	A.push_back( 2  + h*h * q(x[n]));
	C.push_back( -1  + .5 * h * p(x[n]));	
	B.push_back( - h*h * r(x[n]) + ((1 - .5 * h) * p(x[n])) * beta );	
	x[n+1] = b;
}

void FiniteDiff::croutFactorization(double *w){
	int i;
	

	L[1] = A[1];
	U[1] = B[1] / A[1];	
	Z[1] = D[1] / L[1];

	for (i = 2; i <= n-1 ; i++){
		L.push_back( A[i] - C[i] * U[i-1]);
		U.push_back( B[i] / L[i]);
		Z.push_back(( D[i] - C[i] * Z[i-1]) / L[i] );	
	}
	
	L.push_back( A[n] - C[n] * U[n-1]);
	Z.push_back(( D[n] - C[n] * Z[n-1]) / L[n]);
	
	w[0] = alpha;
	w[n] = Z[n];
	w[n+1] = beta;
	
	for (i = n-1; i >= 1 ; i--){
		w[i] = Z[i] - U[i] * w[i+1];	
	}
}
