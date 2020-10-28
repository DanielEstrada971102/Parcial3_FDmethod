#include <fd_method.h>
#include <iostream>
#include <iomanip>
#include <cmath>

// Este codigo es para corroborar que el sistetama
// de ecuaciones matricual se esta haciendo como debe


void  chequear_matriz();
double p(double);
double q(double);
double r(double);


int main(int argc, char const *argv[])
{
	chequear_matriz();
	return 0;
}


void chequear_matriz(){
	int N = 9;
	double x[N+1];
	int k = 0, i = 0;
	double M[N][N];

	FiniteDiff clase(N);

	clase.setInterval(1.0, 2.0);  // se establece el intervalo de integracion [a, b]
	clase.setBoundaryCond(1.0, 2.0);  // se establecn las condiciones de frontera y(a), y(b)
	// se pide definir las funcioens que acompanan cada derivada en la ED
	clase.setP(p);
	clase.setQ(q);
	clase.setR(r);

	clase.calcule_EqSys(x);

	// aca se imprime los elementos de la matriz que la clase calculo
	cout << "Matriz de la clase" << endl;
	cout << "===========================================================================================" << endl;

	cout << left << setw(10) << clase.A.at(1) << setw(10) << clase.B.at(1); 
	for (k = 0; k < N-2; k++) cout << left << setw(10) << "0";
	cout << endl;

	for (i = 1; i < N-1; i++){
		for (k = 0; k < i-1; k++) cout << left << setw(10) << "0";
		cout << left << setw(10) << clase.C.at(i) << setw(10) << clase.A.at(i+1) << setw(10) << clase.B.at(i+1);
		
		for (int r = 0; r < N-3-k; r++) cout << left << setw(10) << "0";
		cout << endl;	
	}

	for (k = 0; k < N-2; k++) cout << left << setw(10) << "0";
	cout << left << setw(10) << clase.C.at(N-1) << setw(15) << clase.A.at(N) << endl;
	

	// aca se hace el calculo a mano para comparar los valores 
	cout << "===========================================================================================" << endl;
	cout << "Matriz hecha a mano" << endl;
	cout << "===========================================================================================" << endl;
	
	for (i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			
			if (i==j) M[i][j] = 2 + clase.h * clase.h * clase.q(x[i+1]);

			else if(i == j-1) M[i][j] = -1 + clase.h * 0.5  * clase.p(x[i+1]);

			else if(i == j+1) M[i][j] = -1 - clase.h * 0.5  * clase.p(x[i+1]);	
			
			else M[i][j] = 0;
			
			cout << left << setw(10) << M[i][j];
		}

		cout << endl;
	}
	cout << "===========================================================================================" << endl;


	// se comparan tambien el b de Ax=b

	cout << left << setw(15) << "vec D" << setw (15) << "a mano" <<endl;
	cout << "================================" << endl;
	cout << left << setw(15) << clase.D.at(1);
	cout << setw(15) << - clase.h * clase.h * clase.r(x[1]) + (1 + 0.5 *clase.h * clase.p(x[1])) * clase.alpha << endl;
	for (i = 2; i < N; i++){
		cout << left << setw(15) << clase.D.at(i);
		cout << setw(15) << - clase.h * clase.h * clase.r(x[i]) << endl;
	}
	cout << left << setw(15) << clase.D.at(N);
	cout << setw(15) << - clase.h * clase.h * clase.r(x[N]) + (1 - 0.5 *clase.h * clase.p(x[N])) * clase.beta << endl;
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

