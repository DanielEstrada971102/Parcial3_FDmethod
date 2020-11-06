/*
	Este programa resuelve mediante diferencias finitas 
	la ecuacion difirencial:
		y'' = -8y'- 16y + 4 sin(4x)

	y compara este resultado con su solucion analitica.
	Se presenta ademas el error relativo entre ambas soluciones
	y se calcula el error rms para un intervalo de diferentes 
	N (N+1 es el numero de particiones del intervalo de integracion).
	Se guardan los datos en un archivo y al comparar el error rms con
	h^2 se evidencia la dependencia lineal entre estos.
 */


#include "fd_method.h"  // libreria con la clase
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <vector>

// ruta para guardar losr archivos
#define RMS_PATH "convergencia/archivos/rms_deviation.txt"  
#define SOL_PATH "convergencia/archivos/solutions_"


//----------------------- prototipos de las funciones---------------------------
double theoretical_sol( double );
double p( double );
double q( double );
double r( double );
double rms_deviation(int, double*, double*);
void compare( int, vector<double>& );
double error( double, double );
//------------------------------------------------------------------------------


int main(){

	int j=0;
	vector<double> rms;  // vector para guardar la desviacion rms
	
	//---------------- archivo para guardar la desviacion---------------
	ofstream OutFIle(RMS_PATH);  
	
	if (OutFIle.fail()){
		cout << "Error: Archivo" << endl;
		exit(0);
	}
	//------------------------------------------------------------------



	// encabezado de las columnas del archivo
	OutFIle << left << setw(15) << "N" << setw(15) << "rms_deviation" 
					<< setw(15) << "h^2" <<endl;

	for (int N=9; N<=100; N+=10){  // aqui van el N_min y N_max
		
		double h = 0.5 / double(N);
		// se crea el archivo con la solucion para N y se calcula el respectivo rms
		compare(N, rms); 

		OutFIle << left << setw(15) << N+1 << setw(15) << rms[j] 
					<< h*h << endl;  // se guarda el rms para este N
		j++;
	}

	OutFIle.close();

	return 0;
}


//------------------ definicion de las funciones--------------------------------

double rms_deviation(int N, double* Y_exact, double* Y_num){
	// calcula el error rms para un N dado

	double sum=0;

	for(int i=0; i<=N+1; i++)
		sum += (Y_exact[i] - Y_num[i]) * (Y_exact[i] - Y_num[i]);

	return sqrt(sum / double(N+1));
}


void compare( int N, vector<double>& rms){
	// se guarda en un archivo la solucion teorica, numerica y el error

	//------------------- condiciones de frontera--------------------------
	double xmin = 0, xmax = 0.5 * M_PI_4;
	double ymin = 0, ymax = 0;


	FiniteDiff FDmethod(N);  // se define un elemento de la clase
	
	double x[N+1]; // para guardar los x 
	double y_fdSol[N+1], y_theoretical[N+1]; // para guardar las soluciones
												// numerica y analitica

	//---------- archivo de salida para guardar las soluciones-------------
	// el nombre del archivo se define en funcion de N+1 para distinguirlos
	string file_name = SOL_PATH + to_string(N+1) + ".txt";
	ofstream OutFIle(file_name);  

	if (OutFIle.fail()){
		cout << "Error: Archivo" << endl;
		exit(0);
	}


	//--- se calcula la solucion usando el metodo de diferencias finitas----
	// para esto se llaman los elementos de la clase definida en fd_method.h
	FDmethod.setInterval(xmin, xmax);
	FDmethod.setBoundaryCond(ymin,ymax);
	FDmethod.setP(p);
	FDmethod.setQ(q);
	FDmethod.setR(r);

	FDmethod.solve(x, y_fdSol);
	

	//--------------- Se escirbe el archivo con los datos--------------------

	// encabezado de las columnas del archivo
	OutFIle << left << setw(15) << "#X" << setw(15) << "Y";
	OutFIle << setw(15) << "YFD" << setw(15) << "ERROR" << endl;

	for (int i = 0; i <= N+1; i++){

		y_theoretical[i] = theoretical_sol(x[i]);  // se calcula la solucion teorica

		OutFIle << left << setw(15) << x[i];
		OutFIle << setw(15) << y_theoretical[i];  // solucion analitica
		OutFIle << setw(15) << y_fdSol[i];  // solucion numerica
		OutFIle << setw(15) << error(y_theoretical[i], y_fdSol[i])<< endl;  // error relativo
	}


	// se le calcula el rms a los datos hallados
	rms.push_back( rms_deviation(N, y_theoretical, y_fdSol) );

	OutFIle.close();
}


double theoretical_sol(double x){
	// solucion analitica de la ED

	return (1./8) * exp(-4 * x) - x * exp(-4 * x) / 
					M_PI - (1./8) * cos(4 * x);
}


double error(double theoretical, double numerical){
	// error relativo entre las soluciones

	return abs( theoretical - numerical );
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
