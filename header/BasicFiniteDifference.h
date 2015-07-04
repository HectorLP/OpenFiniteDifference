#ifndef BASICFINITEDIFFERENCE_H_
#define BASICFINITEDIFFERENCE_H_

//structure for define the time and space domain for the simulation
struct SpaceAndTime
{
	double spaceX;
	int spaceGrid;
	double timeDomain;
	double deltaTimeStep;
};

class FiniteDifference{
private:
	double diffusionCoefficient;
	double * velocityInDomain;
	SpaceAndTime 1dSpaceAndTime;
public:
	FiniteDifference();
	~FiniteDifference();
	virtual void printDomainInformation() = 0;
};

#endif