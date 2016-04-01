#pragma once
#include <algorithm>
#include <math.h>

class Payoff
{
public:
	Payoff(int N, int b, int M);
        Payoff(const Payoff & payoff);
	virtual void evaluate(double* spots, double* payoffs) const = 0;	//Purely virtual function, should be implemented in the derived class
//	static void sort(double* payoffs);
        virtual ~Payoff();
        int getNumAsset() const;
        int getNumPath() const;
        int getNumTimeSteps() const;
protected:
	int N;                                                                          //Number of Time Steps
	int M;										//Number of Assets
	int b;										//NUmber of paths
        double maturity;							//Maturity of the associated contract in year
	bool americanStyle;							//True if american option, false otherwise
};