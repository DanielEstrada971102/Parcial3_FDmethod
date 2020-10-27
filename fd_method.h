#ifndef FD_METHOD_H
#define FD_METHOD_H

#include <iostream>
#include <vector>

using namespace std;

class FiniteDiff
{
	public:
		FiniteDiff(int N);

		void setInterval(double, double); // establece el intervalo de integracion [a, b]
		void setBoundaryCond(double, double);  // establece las condiciones de frontera y(a), y(b)
		// apuntadores a funciones que acompanan cada derivada en la ED
		void setP(double (*)(double));
		void setQ(double (*)(double));
		void setR(double (*)(double));
		void solve(double *, double *);

	private:
		int n=0;  // numero de particiones
		double h;
		double a = 0.0;
		double b = 1.0;
		double alpha;  // y(a)
		double beta;  // y(b)

		// funciones que acompanan cada derivada en la ED
		double (*p)(double);
		double (*q)(double);
		double (*r)(double);

		// Vectores usados para armar el sistema tridiagonal
		vector< double > A; 
		vector< double > C;
		vector< double > D;
		vector< double > B;

		void setH(void);  // define el tamano del paso
		void calcule_EqSys(double *);  // convierte la ED en un sistema matricial
		void croutFactorization(double *);  // resuelve el sistema matricial
};

#endif
 
