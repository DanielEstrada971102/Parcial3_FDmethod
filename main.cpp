/*
	Este codigo es una prueba del funcionamiento
	de la clase, aca se testea la correspondencia
	de los valores calculados al resolver la ED

 	y'' = -2/x y' + 2/x^2 y + sin(ln(x))/x^2

	con los numeros que se presentan en la tabla
	11.3 del libro guia.

 */



#include <fd_method.h>  // se define la clase FiniteDiff
#include <iostream>
#include <cmath>

// Prototipos de las funcioens que acompanan las derivadas en la ED
double p(double);
double q(double);
double r(double);

// Funcion principal del programa
int main(){
	
	int N = 9;  // tamano de matriz | N+1 es el numero de intervalos
	double x[N+1]; 
	double w[N+1];  // w_i = y(x_i)
	FiniteDiff EDproblem(N);  // Se crea un elemento de la clase FiniteDiff

	EDproblem.setInterval(1.0, 2.0);  // se establece el intervalo de integracion [a, b]
	EDproblem.setBoundaryCond(1.0, 2.0);  // se establecn las condiciones de frontera y(a), y(b)
	// se pide definir las funcioens que acompanan cada derivada en la ED
	EDproblem.setP(p);
	EDproblem.setQ(q);
	EDproblem.setR(r);

	EDproblem.solve(x, w);	

	for (int i = 0; i <= N+1; i++) cout << x[i] << "    " << w[i] << endl;


	return 0;
}

// Definicion de las funciones que acompanan las derivadas en la ED
double p(double x){
	return -2.0 / x;
}

double q(double x){
	return 2.0 / (x*x);
}

double r(double x){
	return sin(log(x)) / (x*x);	
}
