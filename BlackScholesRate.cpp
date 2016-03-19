#include "BlackScholesRate.h"


BlackScholesRate::BlackScholesRate(int N, double maturity, double constantRate) : 
rateAndDiscountFactorGenerator(N, maturity),
constantRate(constantRate)
{
	rate[0] = constantRate;
	discountFactor[0] = 1;
	for (int i = 1; i < N; i++)
	{
		rate[i] = constantRate;
		discountFactor[i] = discountFactor[i - 1] * exp(- constantRate * timeStep);
	} 
}


BlackScholesRate::~BlackScholesRate()
{
}
