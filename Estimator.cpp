#include "Estimator.h"


Estimator::Estimator(PathGenerator& paths, Payoff& payoff, rateAndDiscountFactorGenerator& rateAndDiscount) : 
paths(paths), 
payoff(payoff),
rateAndDiscount(rateAndDiscount)
{
}

double Estimator::computePrice(double* initialSpots)
{
	paths.fillSpots(initialSpots);							//Initialization of the paths spots
	double* discount = rateAndDiscount.discountFactor;
	int N = paths.getNumberOfSteps();
	int M = paths.getNumberOfAssets();
	int b = paths.getMeshParameter();
	double* currentPayoff = new double[N*b];
	//Initialization of the final nodes of the tree (date equal to the maturity)
	payoff.evaluate(paths.spots, currentPayoff);

	//Backward induction
	//Actual execution of the algorithm
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < b; j++)
		{
			double continuationPayoff = 0.0;
			for (int j2 = 0; j2 < b; j2++)
			{
				double weight = 1.0;
				for (int k = 0; k < M; k++)
				{
					double rand1 = paths.randomDraws[(N - i - 1)*M*b + j*M + k];
					double rand2 = paths.randomDraws[(N - i)*M*b + j2*M + k];
					weight *= pdf(paths.kit.f, rand2 / rand1) / pdf(paths.kit.g, rand2);
				}
				continuationPayoff += weight * currentPayoff[(N - i)*b + j2];
			}
			continuationPayoff /= (double)b;
			currentPayoff[(N - 1 - i)*b + j] = std::max(currentPayoff[(N - 1 - i)*b + j], discount[N - i] * continuationPayoff / discount[N - i - 1]);
		}
	}
	return currentPayoff[0];
}

Estimator::~Estimator()
{
}
