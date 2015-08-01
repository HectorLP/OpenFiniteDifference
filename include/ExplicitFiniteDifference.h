#ifndef EXPLICITFINITEDIFFERENCE_H_
#define EXPLICITFINITEDIFFERENCE_H_

#include "BasicFiniteDifference.h"
#include <vector>

class ExplicitFiniteDifference : public BasicFiniteDifference 
{
private:
	double numericalStable;
	std::vector<double>solutionDomain;
	std::vector<double>gridPoint;
public:
	ExplicitFiniteDifference();
	~ExplicitFiniteDifference() {};
	
}

#endif