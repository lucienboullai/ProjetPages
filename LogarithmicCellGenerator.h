/* 
 * File:   LogarithmicCellGenerator.h
 * Author: Benjamin
 *
 * Created on 20 mars 2016, 22:06
 */

#ifndef LOGARITHMICCELLGENERATOR_H
#define	LOGARITHMICCELLGENERATOR_H

#include "CellGenerator.h"



class LogarithmicCellGenerator :
        public CellGenerator {
            private:
                double* A;
                double* B;
            public:
                LogarithmicCellGenerator(const Payoff & payoff, double* spots, int k);    
                virtual ~LogarithmicCellGenerator();
                    
};

#endif	/* LOGARITHMICCELLGENERATOR_H */

