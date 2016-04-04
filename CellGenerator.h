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
    int N;
    int b;
    void fillCell(int i, double v);
    double * sortedPayoffs;
    double * payoffs;
  public: 
    CellGenerator(int k, const Payoff & payoff, double* spots);
    void cellsDistribution(int n,int * an, double* cn) const;
    void cellsDistribution(int * a, double* c) const;
    void countTransition (int * b) const;
    int findCell(double v, int n) const;
    int findCell(double v, int a, int b, int n) const;
    virtual ~CellGenerator();
};




