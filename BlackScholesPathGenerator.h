#pragma once
#include "PathGenerator.h"

/*
	Simulation of b paths for a vector of M assets and N discretization steps
	Constant rate and volatility
	Risk neutral probability
	normalGenerator represents a generator N(0,1) : TODO actually not needed
	normalDistribution represents the pdf N(0,1), it is equivalent to the function f in the article
	gDistribution is the pdf of the function g in the article
	g is a random number generator of pdf gDistribution
*/

class BlackScholesPathGenerator :
	public PathGenerator
{
public:
	BlackScholesPathGenerator(double rate, double volatility, int N, int b, int M, double maturity, RandomGenerationTool& kit);
	double rate;								//Constant rate of the Black Scholes model
	double volatility;							//Constant volatility of the Black Scholes model
	void fillSpots(double* intitialSpots);		//Fill the spots array, see the spec in the cpp file
	virtual ~BlackScholesPathGenerator();
};

