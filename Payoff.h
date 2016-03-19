#pragma once
#include <algorithm>
#include <math.h>

class Payoff
{
public:
	Payoff(int N, int b, int M);
	virtual void evaluate(double* spots, double* payoffs) = 0;	//Purely virtual function, should be implemented in the derived class
	virtual ~Payoff();
protected:
	int N;
	int M;										//Number of Assets
	int b;										//NUmber of paths
	double maturity;							//Maturity of the associated contract in year
	bool americanStyle;							//True if american option, false otherwise
};