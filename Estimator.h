#pragma once
#include "PathGenerator.h"
#include "rateAndDiscountFactorGenerator.h"
#include "Payoff.h"
#include <algorithm>


/*
	Deterministic rates for the moment (only N elements in rate and discount Factor of rateAndDiscount)
	/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\
	/!\THE EXECUTION OF COMPUTEPRICE MODIFIES PATHS.SPOTS /!\
	/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\
*/

class Estimator
{
public:
	Estimator(PathGenerator& paths, Payoff& payoff, rateAndDiscountFactorGenerator& rateAndDiscount);
	PathGenerator& paths;
	Payoff& payoff;
	rateAndDiscountFactorGenerator& rateAndDiscount;
	double computePrice(double* initialSpots);
	virtual ~Estimator();
};

