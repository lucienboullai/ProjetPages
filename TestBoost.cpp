#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

#include "BlackScholesPathGenerator.h"
#include "AmericanPutPayoff.h"
#include "Estimator.h"
#include "BlackScholesRate.h"
#include "LogarithmicCellGenerator.h"
#include "SSAPEstimator.h"

int main()
{
	double rate = 0.0;
	double vol = 0.1;
	int N = 10;
	int M = 1;
	int b = 1000;
        int k = 100;
	double maturity = 1.0;
	double initialSpot = 80.0;
	double timeStep = (maturity / (double)N);
	double m = timeStep*(rate - vol*vol / 2.0);
	//std::ofstream fichier("C:\\Users\\Lucien\\Desktop\\e.txt", std::ios::out  | std::ios::trunc);
	for (int i = 0; i < 40; i++)
	{
		double initialSpots[1];
                initialSpots[0]=80 + (double)i;
        
		//False ditribution in the estimator
		lognormal f(m, vol*sqrt(timeStep));
		lognormal g(0.0, 5.0*vol);
		normalGen gGenerator(ENG(time(0)), normalDist(0.0, 5.0*vol));
		RandomGenerationTool kit(f, gGenerator, g);
		BlackScholesPathGenerator paths(rate, vol, N, b, M, maturity, kit);
		BlackScholesRate rates(N, maturity, rate);
		AmericanPutPayoff payoff(100.0, maturity, N, b, M);
		Estimator estimator(paths, payoff, rates);
		std::cout << estimator.computePrice(initialSpots) << "   ";
//                paths.fillSpots( &initialSpot);
//                for (int i=0; i<b;i++){ 
//                    for(int j = 0 ; j<N; j++){
//                        cout<<paths.spots[j*M*b + i*M]<<" ";
//                    }
//                    cout<<endl;
//                }
                SSAPEstimator estimatorSSAP(paths, payoff, rates, k);
		std::cout << estimatorSSAP.computePrice(initialSpots) << std::endl;
	}
	
	//fichier.close();
	system("pause");
}