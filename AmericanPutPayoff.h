#pragma once
#include "Payoff.h"

class AmericanPutPayoff :
	public Payoff
{
public:
	AmericanPutPayoff(double strike, double maturity, int N, int b, int M);
	virtual void evaluate(double* spots, double* payoffs);	//Returns max(0, strike - spot)
	virtual ~AmericanPutPayoff();
private:
	double strike;							//Strike of the put
};

