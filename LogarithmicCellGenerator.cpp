/* 
 * File:   LogarithmicCellGenerator.cpp
 * Author: Benjamin
 * 
 * Created on 20 mars 2016, 22:06
 */

#include "LogarithmicCellGenerator.h"

LogarithmicCellGenerator::LogarithmicCellGenerator(const Payoff & payoff, double* spots, int k):
    CellGenerator(k, payoff, spots)  
{
    int N=payoff.getNumTimeSteps();
    int b=payoff.getNumPath();
 //   cells = new double[k*N];
    double* A = new double[N];
    double* B = new double[N];

    for (int n=1; n<N; n++){
        int cn=0;
        while (sortedPayoffs[cn+n*b]==0 && cn<b) ++cn;                             //first cell is payoff=0
        A[n]=sortedPayoffs[cn+n*b+(b-cn)/10/k];                                 //creates A so that the second cell is 0.1% of the remaining values
        B[n]=1./(double)(k-2) * log(sortedPayoffs[(n+1)*b-1-(b-cn)/10/k]/A[n]);         //creates B so that the last cell is 0.1% of the remaining values
//        cout<<cn<<" "<<"A="<<A[n]<<"i "<<cn+n*b+(b-cn)/10/k<<" "<<sortedPayoffs[(n+1)*b-1-(b-cn)/10/k]<<"  B="<<B[n]<<"i "<<(n+1)*b-1-(b-cn)/10/k<<A[n]*exp(B[n]*double(k-2))<<" "<<sortedPayoffs[(n+1)*b-1-(b-cn)/10/k]<<endl;
      
        for (int i=0 ; i<k-1 ; i++){
            this->fillCell(i+(n-1)*(k-1),A[n]*exp(B[n]*(i)));
//            cout<<cells[i+n]<<"  ";
        }
//        cout<<endl;
    }
    
}

LogarithmicCellGenerator::~LogarithmicCellGenerator() {
}

