#pragma once

#include <math.h>
#include "RandomGenerationTool.h"

class PathGenerator
{
public:
	PathGenerator(int N, int b, int M, double maturity, RandomGenerationTool& kit);
	double* spots;										//Spots of the different assets :
														//At time i, for the path j and the asset k : spots[i*M*b + j*M + k]
	double* randomDraws;								//Random number simulations used to fill spots, same order
														//Note that the M*b first fields are set to 0.0
														//(It just corresponds to the initial spots)
	RandomGenerationTool& kit;
	virtual void fillSpots(double* initialSpots) = 0;	//Fills the spots array, see implementation in the derived class
	int getNumberOfSteps() { return N; }
	int getNumberOfAssets(){ return M; }
	int getMeshParameter(){ return b; }

	virtual ~PathGenerator();

protected:
	int N;											//Number of time steps
	int M;											//Number of assets
	int b;											//Mesh parameter ("number of paths")
	double maturity;								//Maturity of the contract in year
	double timeSteps;								//N*timeSteps = maturity
};

