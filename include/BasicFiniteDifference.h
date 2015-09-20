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
	virtual ~FiniteDifference();
	
	void setSpaceAndTime();
	double getSpaceDomain() const;
	double getTimeLength() const;
	
	void setVelocityInDomian();
	std::vector<double>& getVelocityInDomain() const;
	
	double getDiffusionCeofficient() const;
	
	void calGridInSpace();
	double getGridWidth() const;
	
	void calTimeStep();
	double getTimeStep() const;
	
	void printGridInfo() const;
	void printTimeInfo() const;
	virtual void printDomainInfo() = 0;
};

#endif
