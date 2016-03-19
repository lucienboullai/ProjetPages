#include "MeshGenerator.h"

MeshGenerator::MeshGenerator(int N, int b, double maturity, rateAndDiscountFactorGenerator rateAndDiscount) :
N(N), 
b(b), 
maturity(maturity), 
timeStep(maturity/N),
rateAndDiscount(rateAndDiscount)
{
	spots = new double[N*b];
	weights = new double[(N-1)*b*b];
}


MeshGenerator::~MeshGenerator()
{
}
