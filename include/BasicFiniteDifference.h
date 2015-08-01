#ifndef BASICFINITEDIFFERENCE_H_
#define BASICFINITEDIFFERENCE_H_

#include <vector>

//structure for define the time and space domain for the simulation
struct SpaceAndTime
{
	double spaceX;
	double spaceGrid;
	double timeDomain;
	double timeStep;
};

class FiniteDifference{
private:
	double diffusionCoefficient;
	std::vector<double> velocityInDomain;
	SpaceAndTime 1dSpaceAndTime;
	
	int numSpaceGrids;
	int numTimeSteps;
public:
	FiniteDifference();
	~FiniteDifference();
	
	void setSpaceAndTime();
	double getSpaceDomain();
	double getTimeLength();
	
	void setVelocityInDomian();
	std::vector<double>& getVelocityInDomain();
	
	int calNumOfGridInSpace();
	int calNumTimesteps();
	
	void printNumSpaceGrids();
	void printNumTimeSteps();
	virtual void printDomainInformation() = 0;
};

#endif