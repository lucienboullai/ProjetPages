#include "CellGenerator.h"

CellGenerator::CellGenerator(int k, const Payoff & payoff, double* spots):
        k(k),
        payoff(payoff)
{
    int N=payoff.getNumTimeSteps();
    int b=payoff.getNumPath();  
    cells = new double[(k-1)*(N-1)];
    sortedPayoffs = new double [N*b];
    payoff.evaluate(spots, sortedPayoffs);  
    for(int j = 0 ; j<N; j++){
            std::sort(sortedPayoffs+j*b, sortedPayoffs+(j+1)*b);
            }
    
//    for (int i=0; i<b;i++){ 
//                for(int j = 0 ; j<N; j++){
//                    cout<<sortedPayoffs[j*b + i]<<" ";
//                }
//                cout<<endl;
//            }
}

void CellGenerator::fillCell(int i, double v){
    cells[i]=v;
}

void CellGenerator::cellDistribution(int n) const{
    ofstream csv;
    csv.open ("distribution.csv", ios::app);
    int cn=0;
    int cnm1=0;
    int b=payoff.getNumPath();
    while (sortedPayoffs[cn+n*b]==0 && cn<b) ++cn;
    csv<<0<<","<<cn<<endl;
    cnm1=cn;
    if(cn==b) return;
    for(int i=1;i<k;i++){
        while(sortedPayoffs[cn+n*b]<=cells[i-1+(n-1)*(k-1)]) {
//            cout<<cn<<" "<<sortedPayoffs[cn+n*b]<<" < "<<cells[i-1+n]; 
            cn++;
 
            if(cn==b) break;
        }
//        cout<<endl;
        csv<<i<<";"<<cn-cnm1<<endl;
        cnm1=cn;

    }
    csv<<k<<","<<b-cn<<endl<<endl;
    csv.close();
    return;
}

void CellGenerator::cellsDistribution() const{       
    ofstream clear ("distribution.csv");
    for (int n=1; n<payoff.getNumTimeSteps();n++){
        this->cellDistribution(n);
    }    
};

