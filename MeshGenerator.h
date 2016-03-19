#pragma once
#include <ctime>
#include <math.h>
#include "rateAndDiscountFactorGenerator.h"

class MeshGenerator
{
public:
	MeshGenerator(int N, int b, double maturity, rateAndDiscountFactorGenerator rateAndDiscount);
	virtual ~MeshGenerator();
	virtual void fillSpots(double initialSpot) = 0;
	int getStepsNumber(){ return N; }
	int getPathsNumber(){ return b; }
	double* spots;
	double* weights;
protected:
	int N;
	int b;
	double maturity;
	double timeStep;
};

