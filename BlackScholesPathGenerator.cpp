#include "BlackScholesPathGenerator.h"


BlackScholesPathGenerator::BlackScholesPathGenerator(double rate, double volatility, int N, int b, int M, double maturity, RandomGenerationTool& kit) :
PathGenerator(N, b, M, maturity, kit),
rate(rate),
volatility(volatility)
{
}

void BlackScholesPathGenerator::fillSpots(double* initialSpots)
{
	for (int j = 0; j < b; j++)
		for (int k = 0; k < M; k++)
			spots[j*M + k] = initialSpots[k];

	int subSize = M*b;
	double m = rate - volatility*volatility / 2.0;
	for (int i = 1; i < N; i++)
		for (int j = 0; j < b; j++)
			for (int k = 0; k < M; k++)
				spots[i*subSize + j*M + k] = initialSpots[k] * randomDraws[i*subSize + j*M + k];
}

BlackScholesPathGenerator::~BlackScholesPathGenerator()
{
}
