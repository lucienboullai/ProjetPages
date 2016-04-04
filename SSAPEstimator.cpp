/* 
 * File:   SSAPEstimator.cpp
 * Author: Benjamin
 * 
 * Created on 3 avril 2016, 17:35
 */

#include "SSAPEstimator.h"


SSAPEstimator::SSAPEstimator(PathGenerator& paths, Payoff& payoff, rateAndDiscountFactorGenerator& rateAndDiscount, int k):
    Estimator(paths, payoff, rateAndDiscount),
        k(k)
{ 
}

double SSAPEstimator::computePrice(double* initialSpots){    
	paths.fillSpots(initialSpots);							//Initialization of the paths spots
	double* discount = rateAndDiscount.discountFactor;
	int N = paths.getNumberOfSteps();
	int M = paths.getNumberOfAssets();
	int b = paths.getMeshParameter();
        LogarithmicCellGenerator cells (payoff, paths.spots, k);
        int * a = new int [(N-1)*(k+1)];
        int * bij = new int [(N-1)*(k+1)*(k+1)] ;
        double * c = new double [(N-1)*(k+1)];
        cells.cellsDistribution(a,c);
        cells.countTransition(bij);
        double * V = new double [k+1];
        double * Vp1 = new double [k+1];
        double sum;
        
	//Backward induction
	//Actual execution of the algorithm        
        for (int n=N-1 ; n>0 ; n--){
                for (int i=0; i<k+1; i++){
                    sum=0;
                    for (int j=0; j<k+1; j++){
                        if (a[(n-1)*(k+1)+i]!=0){
                                sum+=Vp1[j]*(double)bij[j+(k+1)*i+(k+1)*(k+1)*(n-1)]/(double)a[(n-1)*(k+1)+i];
//                                if(i==1 && bij[j+(k+1)*i+(k+1)*(k+1)*(n-1)]!=0) cout<<j<<" "<<(double)bij[j+(k+1)*i+(k+1)*(k+1)*(n-1)]/(double)a[(n-1)*(k+1)+i]<<"/"<<Vp1[j]<<" ";
                        }
                    }
                    if (a[(n-1)*(k+1)+i]!=0) V[i]=std::max(c[(n-1)*(k+1)+i]/(double)a[(n-1)*(k+1)+i] , sum);
                    else V[i]=0;
                    //cout<<c[(n-1)*(k+1)+i]/a[(n-1)*(k+1)+i]<<" / ";
                    //cout<<V[i]<<" ";
                }
                for (int i=0; i<k+1; i++) Vp1[i]=V[i];
            }
        sum=0;
        for (int j=0; j<k+1; j++)
        {
//        cout<<Vp1[j]<<" "<<a[j]<<" ; ";
        sum+=Vp1[j]*(double)a[j];
        }
        return sum/(double)b;  
}

SSAPEstimator::~SSAPEstimator() {
}

