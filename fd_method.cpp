#include "fd_method.h"
#include <iostream>

FiniteDiff::FiniteDiff(int N){
	n = N;
	setH();

	// Para que coincidan los indices con
	// el algoritmo de croutFactorization()
	A.push_back(0);
	B.push_back(0);
	C.push_back(0);
	D.push_back(0);
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
	//cout << x[0] << endl;
	croutFactorization(w);
	//cout << x[0] << endl;
}

void FiniteDiff::calcule_EqSys(double *x){
	int i;
	x[0] = a;
	// ------ step 1 -----------------
	x[1] = a + h;

	A.push_back( 2  + h*h * q(x[1]));
	B.push_back( -1  + .5 * h * p(x[1]));	
	D.push_back( - h*h * r(x[1]) + ((1 + .5 * h) * p(x[1])) * alpha );
	
	// ------ step 2 -----------------
	for (i = 2; i <= n-1 ; i++){
		x[i] = a + i * h;
		A.push_back( 2  + h*h * q(x[i]));
		B.push_back( -1  + .5 * h * p(x[i]));
		C.push_back( -1  - .5 * h * p(x[i]));	
		D.push_back( - h*h * r(x[i]) );
	}
	
	// ------ step 3 -----------------
	x[n] = b - h;
	A.push_back( 2  + h*h * q(x[n]));
	C.push_back( -1  + .5 * h * p(x[n]));	
	B.push_back( - h*h * r(x[n]) + ((1 - .5 * h) * p(x[n])) * beta );	
	x[n+1] = b;
}


void FiniteDiff::croutFactorization(double *w){
	int i;
	double L[n+1];
	double U[n+1];
	double Z[n+1];
	// ------ step 4 -----------------
	L[1] = A[1];
	U[1] = B[1] / A[1];	
	Z[1] = D[1] / L[1];
	
	// ------ step 5 -----------------
	for (i = 2; i <= n-1 ; i++){
		L[i] =  A[i] - C[i] * U[i-1];
		U[i] =  B[i] / L[i];
		Z[i] = ( D[i] - C[i] * Z[i-1]) / L[i] ;	
	}
	// ------ step 6 -----------------
	L[n] = A[n] - C[n] * U[n-1];
	Z[n] = ( D[n] - C[n] * Z[n-1]) / L[n];
	
	// ------ step 7 -----------------
	w[0] = alpha;
	w[n] = Z[n];
	w[n+1] = beta;
	
	// ------ step 8 -----------------
	for (i = n-1; i >= 1 ; i--){
		w[i] = Z[i] - U[i] * w[i+1];	
	}
}
