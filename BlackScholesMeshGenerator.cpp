#include "BlackScholesMeshGenerator.h"


BlackScholesMeshGenerator::BlackScholesMeshGenerator(int N, int b, double maturity, double rate, double volatility) :
MeshGenerator(N, b, maturity, BlackScholesRate(N, maturity, rate)),
rate(rate), 
volatility(volatility),
generator(ENG(time(0)), DIST(0, 1)),
dist(normal())
{
}

void BlackScholesMeshGenerator::fillSpots(double initialSpot)
{
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < b; j++)
			spots[b*i + j] = generator();
	}

	int size = b*b;
	for (int i = 0; i < N-1; i++)
	{
		for (int j1 = 0; j1 < b; j1++)
		{
			double rand1 = spots[b*i + j1];
			for (int j2 = 0; j2 < b; j2++)
			{
				double rand2 = spots[b*(i+1) + j2];
				weights[i*size + j1 * b + j2] = pdf(dist, rand2 - rand1);
			}
		}
	}

	double m = rate - volatility*volatility / 2.0;
	for (int j = 0; j < b; j++)
		spots[j] = initialSpot;
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < b; j++)
			spots[b*i + j] = spots[b*(i - 1) + j] * exp((m*timeStep + volatility*spots[b*i + j]));
	}
}

BlackScholesMeshGenerator::~BlackScholesMeshGenerator()
{
}
