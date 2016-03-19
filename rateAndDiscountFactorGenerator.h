#pragma once
#include <math.h>

class rateAndDiscountFactorGenerator
{
public:
	rateAndDiscountFactorGenerator(int N, double maturity);
	double* rate;				//simulation of the rate at the N discretization date
	double* discountFactor;		//simulation of the discount factor at the N discretization dates
	virtual ~rateAndDiscountFactorGenerator();
protected:
	int N;						//Number of discretization dates
	double maturity;			//Maturity of the considered contract, should match the other class' equivalent variables 
	double timeStep;			//N x timeStep = maturity
};

