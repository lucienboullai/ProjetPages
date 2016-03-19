#include "rateAndDiscountFactorGenerator.h"


rateAndDiscountFactorGenerator::rateAndDiscountFactorGenerator(int N, double maturity) : 
N(N), 
maturity(maturity), 
timeStep(maturity/(double)N)
{
	rate = new double[N];
	discountFactor = new double[N];
}


rateAndDiscountFactorGenerator::~rateAndDiscountFactorGenerator()
{
}
