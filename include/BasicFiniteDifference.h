#ifndef BASICFINITEDIFFERENCE_H_
#define BASICFINITEDIFFERENCE_H_

#include <vector>

//structure for define the time and space domain for the simulation
struct SpaceAndTime
{
	double spaceX;
	int numGrid;
	double timeDomain;
	int numTimeStep;
};

class FiniteDifference{
private:
	double diffusionCoefficient;
	std::vector<double> velocityInDomain;
	SpaceAndTime oneDimSpaceAndTime;
	
	double gridWidth;
	double timeStep;
public:
	FiniteDifference();
	~FiniteDifference();
	
	void setSpaceAndTime();
	double getSpaceDomain();
	double getTimeLength();
	
	void setVelocityInDomian();
	std::vector<double>& getVelocityInDomain();
	
	void calGridInSpace();
	void calTimestep();
	
	void printNumSpaceGrids();
	void printNumTimeSteps();
	virtual void printDomainInformation() = 0;
};

#endif