#pragma once
#include "MeshGenerator.h"
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/variate_generator.hpp>
#include <boost/math/distributions/normal.hpp>

using boost::math::normal;
typedef boost::mt19937 ENG;
typedef boost::normal_distribution<double> DIST;
typedef boost::variate_generator<ENG, DIST> Generator;

class BlackScholesMeshGenerator :
	public MeshGenerator
{
public:
	BlackScholesMeshGenerator(int N, int b, double maturity, double rate, double volatility);
	virtual ~BlackScholesMeshGenerator();
	virtual void fillSpots(double initialSpot);
protected :
	double rate;
	double volatility;
	Generator generator;
	normal dist;
};

