#include <iostream>
#include <vector>
#include <fstream>

#include "BasicFiniteDifference.h"

FiniteDifference::FiniteDifference()
{
	setSpaceAndTime();
	setVelocityInDomain();
}

FiniteDifference::~FiniteDifference()
{
	
}

FiniteDifference::setSpaceAndTime()
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
	fileSpaceAndTime >> 1dSpaceAndTime.spacX >> 1dSpaceAndTime.spaceGrid >> 
					1dSpaceAndTime.timeDomain >> 1dSpaceAndTime.timeStep;
	fileSpaceAndTime.close();
	std::cout << "Finish loading the parameters of space and time.\n";
}

FiniteDifference::setVelocityDomain()
{
	std::cout << "Load the velocity value in the domain.\n";
	std::ifstream fileVelocity("velocityindomain.dat");
	if (!fileVelocity.is_open())
	{
		std::cerr << "Fail to open the file on velocity correctly.\n";
	}
	fileVelocity.open("velocity.dat");
	fileVelocity >> 
	std::cout << "Finish loading the parameters of velocity in the domain.\n";
}