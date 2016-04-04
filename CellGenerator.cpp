#include "CellGenerator.h"

CellGenerator::CellGenerator(int k, const Payoff & payoff, double* spots):
        k(k),
        payoff(payoff),
        N(payoff.getNumTimeSteps()),
        b(payoff.getNumPath())
{  
    cells = new double[(k-1)*(N-1)];
    payoffs = new double [N*b];
    sortedPayoffs = new double [N*b];
    payoff.evaluate(spots, payoffs);
    for (int p=0; p<N*b; p++) sortedPayoffs[p]=payoffs[p];
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

void CellGenerator::cellsDistribution(int n, int * an, double * cn) const{
    ofstream csv;
    csv.open ("distribution.csv", ios::app);
    int x=0;
    int xm1=0;
    double sum;
    int b=payoff.getNumPath();
    while (sortedPayoffs[x+n*b]==0 && x<b) ++x;
    an[0]=x;
    cn[0]=0;
    csv<<0<<";"<<x<<endl;
    xm1=x;
    if(x==b) return;
    for(int i=1;i<k;i++){
        sum=0;
        while(sortedPayoffs[x+n*b]<=cells[i-1+(n-1)*(k-1)]) {
//            cout<<x<<" "<<sortedPayoffs[x+n*b]<<" < "<<cells[i-1+n]; 
            x++;
            sum+=sortedPayoffs[x+n*b];
            if(x==b) break;
        }
//        cout<<endl;
        cn[i]=sum;
        an[i]=x-xm1;
        csv<<i<<";"<<an[i]<<";"<<cn[i]/(double)an[i]<<endl;
        xm1=x;

    }
    sum=0;
    for(int j=x;j<=b;j++) sum+=sortedPayoffs[j+n*b];
    cn[k]=sum;
    an[k]=b-x;
    csv<<k<<";"<<an[k]<<endl<<endl;
    csv.close();
    return;
}

void CellGenerator::cellsDistribution(int * a, double* c ) const{       
    ofstream clear;
    clear.open("distribution.csv");
    clear<<"distribution des simulations dans les differentes cellules et payoff moyen pour chaque n"<<endl;
    clear.close();
    for (int n=1; n<N ;n++){
        this->cellsDistribution(n, a+(n-1)*(k+1), c+(n-1)*(k+1));
    }    
};

void CellGenerator::countTransition (int * bij) const{                                  //b[j+(k+1)*i+(k+1)*(k+1)*(n-1)] : nombre transitions de cell i au temps n vers j
    for (int m=0 ; m<b ; m++){
        for (int n=0; n<N; n++){
            int i=findCell(payoffs[n*b+m], n);
            int j=findCell(payoffs[(n+1)*b+m], n);
            bij[j+(k+1)*i+(k+1)*(k+1)*(n-1)]+=1;
        }
    }
};

int CellGenerator::findCell(double v, int n) const{
    if (v>cells[n*(k-1)-1]) return k+1;
    if (v==0) return 0;
    if (v<cells[(n-1)*(k-1)]) return 1;
    if (v<cells[(n-1)*(k-1)+(k-1)/2]) return findCell(v, 0, (k-1)/2, n);
    else return findCell(v, (k-1)/2, k-1, n);
}

int CellGenerator::findCell(double v, int a, int b, int n) const{
    if (b==a+1) return b+1;
    if (v<cells[(a+b)/2 + (n-1)*(k-1)]) return findCell(v, a, (a+b)/2, n);
    else return findCell(v, (a+b)/2, b, n);
}

CellGenerator::~CellGenerator(){}

