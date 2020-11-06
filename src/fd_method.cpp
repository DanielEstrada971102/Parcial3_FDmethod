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
	// Se define el tamano del paso
	h = double ((b - a) / (n + 1));
}


void FiniteDiff::setInterval(double xmin, double xmax){
	// intervalo de integracion
	a = xmin;
	b = xmax;
	setH();
}


void FiniteDiff::setBoundaryCond(double ymin, double ymax){
	// condiciones de frontera
	alpha = ymin;
	beta = ymax;
}


void FiniteDiff::setP(double (*function)(double)){
	// funcion que acompana la primera derivada en la ED
	p = function;
}


void FiniteDiff::setQ(double (*function)(double)){
	// funcion que acompana la derivada de orden cero en la ED
	q = function;
}


void FiniteDiff::setR(double (*function)(double)){
	// funcion que no va a acompanada de y en la ED
	r = function;
}


void FiniteDiff::solve(double *x, double *w){
	/*funcion que aplica las dos parte del algoritmo
	para soluciona la ED, el usuario debe pasar
	los arreglos x y w de tamaño n+1.
	*/

	calcule_EqSys(x);  // linealiza las ecuaciones en un sistema matricial N+1 x N+1
	croutFactorization(x, w);  // resuelve el sistema tridiagonal
}


void FiniteDiff::calcule_EqSys(double *x){
	// funcion que crea los elementos de matriz linealizando el problema
	x[0] = a;

	// ------ step 1 -----------------
	x[1] = a + h;
	A.push_back( 2  + h*h * q(x[1]));  // A[1]
	B.push_back( -1  + 0.5 * h * p(x[1]));	// B[1]
	D.push_back( -1 * h*h * r(x[1]) + (1 + 0.5 * h * p(x[1])) * alpha );  // D[1]
	
	// ------ step 2 -----------------
	for (int i = 2; i <= n-1 ; i++){
		x[i] = a + i * h;
		A.push_back( 2  + h*h * q(x[i]));  // empieza en A[2]
		B.push_back( -1  + 0.5 * h * p(x[i]));  // empieza en B[2]
		C.push_back( -1  - 0.5 * h * p(x[i]));	// empieza en C[1] - termina en C[n-2]
		D.push_back( - h*h * r(x[i]));  // empieza en D[2] - termina en D[n-1]
	}
	
	// ------ step 3 -----------------
	x[n] = b - h;
	A.push_back( 2  + h*h * q(x[n]));  // A[n]
	C.push_back( -1  - 0.5 * h * p(x[n]));  // C[n-1]
	D.push_back( - h*h * r(x[n]) + (1 - 0.5 * h * p(x[n])) * beta );  // D[n]
	x[n+1] = b;
}


void FiniteDiff::croutFactorization(double *x, double *w){
	// resuelve un sistema lineal tridiagonal

	int i;
	double L[n+1];
	double U[n+1];
	double Z[n+1];
	// ------ step 4 -----------------
	L[1] = A.at(1);
	U[1] = B.at(1) / A.at(1);	
	Z[1] = D.at(1) / L[1];
	
	// ------ step 5 -----------------
	for (i = 2; i <= n-1 ; i++){
		L[i] =  A.at(i) - C.at(i-1) * U[i-1];
		U[i] =  B.at(i) / L[i];
		Z[i] = ( D.at(i) - C.at(i-1) * Z[i-1]) / L[i] ;	
	}

	// ------ step 6 -----------------
	L[n] = A.at(n) - C.at(n-1) * U[n-1];
	Z[n] = ( D.at(n) - C.at(n-1) * Z[n-1]) / L[n];
	
	// ------ step 7 -----------------
	w[0] = alpha;
	w[n] = Z[n];
	w[n+1] = beta;

	// ------ step 8 -----------------
	for (i = n-1; i >= 1 ; i--){
		w[i] = Z[i] - U[i] * w[i+1];
	}
}
