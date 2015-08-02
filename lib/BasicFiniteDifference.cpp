#include <iostream>
#include <vector>
#include <fstream>
#include <exception>

#include "BasicFiniteDifference.h"

inline bool checkSpaceAndTime(const SpaceAndTime &st)
{
	if (st.spaceX <= 0. || st.numGrid <= 0. || st.timeDomain < = 0. || \
		st.numTimeStep <= 0)
	{
		throw std::invalid_argument("invalid parameters because of not being positive.");
	}
	else
	{
		return true;	//return 1;
	}
}

inline bool checkVelocityInDomain(const std::vector<double> &vl)
{
	for (auto x in vl)
	{
		if (x < 0.0)
		{
			throw std::invalid_argument("invalid data for velocity because of not \
										being positive.");
			//break;
		}
	}
}

FiniteDifference::FiniteDifference()
{
	setSpaceAndTime();
	setVelocityInDomain();
}

FiniteDifference::~FiniteDifference()
{
	
}

void FiniteDifference::setSpaceAndTime()
{
	std::cout << "Load the parameters of space and time.\n";
	std::ifstream fileSpaceAndTime("spaceandtime.dat");
	if (!fileSpaceAndTime.is_open())
	{
		std::cerr << "Fail to open the file correctly.\n ";
		system("pause");
		exit(1);
	}
	fileSpaceAndTime.open("spaceandtime.dat");
	fileSpaceAndTime >> oneDimSpaceAndTime.spaceX >> oneDimSpaceAndTime.numGrid >> 
					oneDimSpaceAndTime.timeDomain >> oneDimSpaceAndTime.numTimeStep;
	fileSpaceAndTime.close();
	try
	{
		checkSpaceAndTime(oneDimSpaceAndTime);
	}
	catch (const std::invalid_argument &e)
	{
		std::cout << "The error is " << e << std::endl;
	}
	std::cout << "Finish loading the parameters of space and time.\n";
}

void FiniteDifference::setVelocityDomain()
{
	std::cout << "Load the velocity value in the domain.\n";
	std::ifstream fileVelocity("velocityindomain.dat");
	if (!fileVelocity.is_open())
	{
		std::cerr << "Fail to open the file on velocity correctly.\n";
	}
	fileVelocity.open("velocity.dat");
	double tempVelocity;
	while(fileVelocity >> tempVelocity)
	{
		velocityInDomain.push_back(tempVelocity);
	}
	try
	{
		checkVelocityInDomain(velocityInDomain);
	}
	catch (const std::invalid_argument &e)
	{
		std::cout << "The error is " << e << std::endl;
	}
	std::cout << "Finish loading the parameters of velocity in the domain.\n";
}

double FiniteDifference::getSpaceDomain()
{
	return oneDimSpaceAndTime.spaceX;
}

double FiniteDifference::getTimeLength()
{
	return oneDimSpaceAndTime.timeDomain;
}

void FiniteDifference::calGridInSpace()
{
	gridWidth = oneDimSpaceAndTime.spaceX / oneDimSpaceAndTime.numGrid;
}

void FiniteDifference::calTimeStep()
{
	timeStep = oneDimSpaceAndTime.timeDomain / oneDimSpaceAndTime.numTimeStep;
}