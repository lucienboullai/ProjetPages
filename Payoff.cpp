#include "Payoff.h"


Payoff::Payoff(int N, int b, int M):
N(N),
M(M),
b(b)
{
}

Payoff::Payoff(const Payoff & payoff):
N(payoff.N),
b(payoff.b),
M(payoff.M)
{
}

int Payoff::getNumAsset() const {return M;}

int Payoff::getNumPath() const {return b;}

int Payoff::getNumTimeSteps() const {return N;}

//static void Payoff::sort(double* payoffs){
//    
//}

Payoff::~Payoff()
{
}
