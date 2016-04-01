#include "AmericanPutPayoff.h"


AmericanPutPayoff::AmericanPutPayoff(double strike, double maturity, int N, int b, int M) : 
Payoff(N, b, M),
strike(strike) 
{
	americanStyle = true;
}

void AmericanPutPayoff::evaluate(double* spots, double* payoffs) const
{
	for (int j = 0; j < b*N; j++)
		payoffs[j] = std::max(0.0, strike - spots[j]);
}

AmericanPutPayoff::~AmericanPutPayoff()
{
}
