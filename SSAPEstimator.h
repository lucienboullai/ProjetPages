/* 
 * File:   SSAPEstimator.h
 * Author: Benjamin
 *
 * Created on 3 avril 2016, 17:35
 */

#ifndef SSAPESTIMATOR_H
#define	SSAPESTIMATOR_H
#include "Estimator.h"
#include "LogarithmicCellGenerator.h"


class SSAPEstimator : 
public Estimator
{
public:
    SSAPEstimator();
    SSAPEstimator(PathGenerator& paths, Payoff& payoff, rateAndDiscountFactorGenerator& rateAndDiscount, int k);
    SSAPEstimator(const SSAPEstimator& orig);
    double computePrice(double* initialSpots);
    virtual ~SSAPEstimator();
private:
    int k;
};

#endif	/* SSAPESTIMATOR_H */

