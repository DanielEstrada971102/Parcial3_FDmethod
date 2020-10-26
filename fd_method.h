#ifndef FD_METHOD_H
#define FD_METHOD_H

#include <iostream>
#include <vector>

using namespace std;

class FiniteDiff
{
	public:
		FiniteDiff(int N);
		//~FiniteDiff();

		void setInterval(double, double); //integration interval [a, b]
		void setBoundaryCond(double, double); //boundary conditions
		void setP(double (*)(double));
		void setQ(double (*)(double));
		void setR(double (*)(double));
		void solve(double *, double *);

	private:
		int n=0;
		double h;
		double a = 0, b = 1;
		double alpha, beta;
		double (*p)(double);
		double (*q)(double);
		double (*r)(double);
		vector< double > A; 
		vector< double > C;
		vector< double > D;
		vector< double > B; 

		void setH(void);
		void calcule_EqSys(void);
		void croutFactorization(double *, double *);
};

#endif
 