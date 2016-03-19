#pragma once
#include "rateAndDiscountFactorGenerator.h"
class BlackScholesRate :
	public rateAndDiscountFactorGenerator
{
public:
	BlackScholesRate(int N, double maturity, double constantRate);
	virtual ~BlackScholesRate();
private:
	double constantRate;			//Constant rate of the Black Scholes model, should match the paramater of the PathGenerator
};

