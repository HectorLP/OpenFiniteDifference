#ifndef EXPLICITFINITEDIFFERENCE_H_
#define EXPLICITFINITEDIFFERENCE_H_

#include "BasicFiniteDifference.h"
#include <vector>

class ExplicitFiniteDifference : public BasicFiniteDifference 
{
private:
	//double diffusionCoefficient;
	double numericalStable;
	std::vector<double> initialCondition;
	std::vector<double> solutionDomain;
	std::vector<double> gridPoint;
	
	//set up initial condition
	void setInitialCondition();
	
	//private function for calculating the coefficient in the equation
	double calCoeffNextSpace();
	double calCoeffCurrentSpace();
	double calCoeffPreviousSpace();
	
	//output the results at several certain time steps
	void outputDomainResults() const;
	void outputPointResult(const double position) const;
	
	//calculate the numerical convergence
	double calNumericalConvergence();
public:
	ExplicitFiniteDifference();
	//void setDiffusionCoefficient();
	//calculate the concentration in the whole domain
	void calConcentration();
	
	virtual ~ExplicitFiniteDifference() {};
	
}

#endif
