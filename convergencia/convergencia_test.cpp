#include ".. /fd_method.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <vector>


// prototipos de las funciones
double theoretical_sol( double );
double error( double, double );
double p( double );
double q( double );
double r( double );
double rms_deviation(int, double*, double*);
void compare( int, vector<double>& );

int main(){

	int j=0;
	vector<double> rms;  // vector para guardar la rms deviation
	ofstream OutFIle("rms_deviation1000.txt");  // archivo para guardar la desviacion
	// chequea si se abrio bien el archivo
	if (OutFIle.fail()){
		cout << "Error: Archivo" << endl;
		exit(0);
	}

	// se agrega el nombre de las columnas
	OutFIle << left << setw(15) << "N" << setw(15) << "rms_deviation" 
					<< setw(15) << "h^2" <<endl;

	for (int N=99; N<1000; N+=100){  // aqui van el N_min y N_max
		
		double h = 0.5 / double(N);
		compare(N, rms);  // se crea el archivo con la solucion para N y se calcula el respectivo rms
		OutFIle << left << setw(15) << N+1 << setw(15) << rms[j] 
					<< h*h << endl;  // se guarda el rms para este N
		j++;
	}

	OutFIle.close();

	return 0;
}


// definicion de las funciones
double rms_deviation(int N, double* Y_exact, double* Y_num){
	// calcula el error rms

	double sum=0;

	for(int i=0; i<=N+1; i++)
		sum += (Y_exact[i] - Y_num[i]) * (Y_exact[i] - Y_num[i]);

	return sqrt(sum / double(N+1));
}

void compare( int N, vector<double>& rms){
	// se guarda en un archivo la solucion teorica, numerica y el error
	// se calcula la desviacion rms 

	// condiciones de frontera
	double xmin = 0, xmax = 0.5 * M_PI_4;
	double ymin = 0, ymax = 0;

	FiniteDiff FDmethod(N);  // se define un elemento de la clase
	double x[N+1], y_fdSol[N+1], y_theoretical[N+1];  // para guardar los x y las soluciones

	string file_name = "graficas/solutions_" + to_string(N+1) + ".txt";
	ofstream OutFIle(file_name);  // archivo de salida para guardar a¿las soluciones

	if (OutFIle.fail()){
		cout << "Error: Archivo" << endl;
		exit(0);
	}

	// se calcula la solucion usando el metodo de diferencias finitas
	FDmethod.setInterval(xmin, xmax);
	FDmethod.setBoundaryCond(ymin,ymax);
	FDmethod.setP(p);
	FDmethod.setQ(q);
	FDmethod.setR(r);

	FDmethod.solve(x, y_fdSol);

	// se pone el titulo de las columnas del archivo
	OutFIle << left << setw(15) << "#X" << setw(15) << "Y";
	OutFIle << setw(15) << "YFD" << setw(15) << "ERROR" << endl;

	for (int i = 0; i <= N+1; i++){
		
		y_theoretical[i] = theoretical_sol(x[i]);  // se calcula la solucion teorica

		OutFIle << left << setw(15) << x[i] << setw(15) << y_theoretical[i];
		OutFIle << setw(15) << y_fdSol[i] << setw(15) << error(theoretical_sol(x[i]), y_fdSol[i]) << endl;
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
	// error relativo a la solucion analitica

	return abs( theoretical - numerical);
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