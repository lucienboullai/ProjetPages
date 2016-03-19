#include "PathGenerator.h"


PathGenerator::PathGenerator(int N, int b, int M, double maturity, RandomGenerationTool& kit) :
N(N),
M(M),
b(b),
timeSteps(maturity/(double) N),
maturity(maturity),
kit(kit)
{
	int size = N*M*b;
	spots = new double[size];
	randomDraws = new double[size];
	for (int i = M*b; i < size; i++)
		randomDraws[i] = exp(kit.gGenerator());
	for (int i = 0; i < M*b; i++)
		randomDraws[i] = 1.0;
}


PathGenerator::~PathGenerator()
{
}
