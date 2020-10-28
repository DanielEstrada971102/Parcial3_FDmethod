#include "fd_method.h"
#include <iostream>
#include <fstream>
#include <cmath>

void chequear_funciones();
double p(double x);
double q(double x);
double r(double x);

int main(int argc, char const *argv[])
{
	chequear_funciones();
	return 0;
}


void chequear_funciones()
{
	FiniteDiff clase(9);
	ofstream Archivo("funciones_prueba.txt");

  	if ( Archivo.fail() )      
  	//if ( !archivoClientesSalida ) 
    {
      cout << "No se pudo abrir el archivo" << endl;
      exit( 1 );
    }

	double x[10];

	x[0] = 1;

	for (int i = 1; i < 10; i++) x[i] = x[i-1] + 0.1;

	clase.setP(p);
	clase.setQ(q);
	clase.setR(r);

	for (int i = 0; i < 10; i++){
		Archivo << x[i] << "  " << clase.p(x[i]) << "  " << clase.q(x[i]);
		Archivo <<  "  " << clase.r(x[i]) << endl;
	}

	Archivo.close();
}

// Definicion de las funciones que acompanan las derivadas en la ED
double p(double x){
	return -2.0/ x;
}

double q(double x){
	return 2.0 / (x*x);
}

double r(double x){
	return sin(log(x)) / (x*x);	
}
