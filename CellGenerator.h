/* 
 * File:   CellGenerator.h
 * Author: Benjamin
 *
 * Created on 20 mars 2016, 21:23
 */

#ifndef CELLGENERATOR_H
#define	CELLGENERATOR_H



#endif	/* CELLGENERATOR_H */

#include <math.h>
#include <algorithm>
#include "Payoff.h"
#include <iostream>
#include<fstream>

using namespace std;

class CellGenerator{
  protected:
    const Payoff & payoff;
    double* cells;
    int k;
    void fillCell(int i, double v);
    double * sortedPayoffs;
  public: 
    CellGenerator(int k, const Payoff & payoff, double* spots);
    void cellDistribution(int n) const;
    void cellsDistribution() const;
};



