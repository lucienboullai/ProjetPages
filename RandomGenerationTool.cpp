#include "RandomGenerationTool.h"


RandomGenerationTool::RandomGenerationTool(lognormal& f, normalGen& gGenerator, lognormal& g):
f(f),
gGenerator(gGenerator),
g(g)
{
}


RandomGenerationTool::~RandomGenerationTool()
{
}
