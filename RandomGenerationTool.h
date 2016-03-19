#pragma once
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/lognormal_distribution.hpp>
#include <boost/random/variate_generator.hpp>
#include <boost/math/distributions/lognormal.hpp>

using boost::math::lognormal;
using boost::math::normal;
typedef boost::normal_distribution<double> normalDist;
typedef boost::mt19937 ENG;
typedef boost::lognormal_distribution<double> lognormalDist;

//TODO : lognormalGen seems to be bugged for a 0 drift
typedef boost::variate_generator<ENG, lognormalDist> lognormalGen;
typedef boost::variate_generator<ENG, normalDist> normalGen;

class RandomGenerationTool
{
public:
	RandomGenerationTool(lognormal& f, normalGen& gGenerator, lognormal& g);
	lognormal& f;			//distribution logN(0,1)
	normalGen& gGenerator;	//Random number generator with distribution N(0,1)
	lognormal& g;			//Corresponds to the g function of the article
	~RandomGenerationTool();
};

