/*
 * File for functions in ExplicitFiniteDifference class
 * 
 * */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

#include "ExplicitFiniteDifference.h"

using std::cout;
using std::cin;
using std::endl;

ExplicitFiniteDifference::ExplicitFiniteDifference():FiniteDifference()
{
	cout << "Using explicit finite difference method.\n";
	setInitialCondition();
}

ExplicitFiniteDifference::~ExplicitFiniteDifference()
{
	cout << "Calculation from explicit finite difference method is finished.\n";
}

void ExplicitFiniteDifference::setInitialCondition()
{
	//TODO write code for loading initial condition
	using std::ifstream;
	ifstream loadInitialCondition("initialcondition.dat");
	if (!loadInitialCondition.is_open())
	{
		std::cerr << "Fail to open the file of initial condition.\n";
		abort();
	}
	double tempInitial;
	while(loadInitialCondition >> tempInitial)
	{
		initialCondition.push_back(tempInitial);
	}
}

double ExplicitFiniteDifference::calCoeffNextSpace()
{
	double diffusionCoeff;
	diffusionCoeff = FiniteDifference::getDiffusionCoefficient();
	double spaceGrid;
	spaceGrid = FiniteDifference::getGridWidth();
	double timeStep;
	timeStep = FiniteDifference::getTimeStep();
	std::vector<double> velocity;
	velocity = FiniteDifference::getVelocityInDomain();
	double coeffNextSpace;
	coeffNextSpace = (diffusionCoeff / (spaceGrid * spaceGrid) - velocity[0] / \
					(2. * spaceGrid)) * timeStep;
	return coeffNextSpace;
}


double ExplicitFiniteDifference::calCoeffCurrentSpace()
{
	double diffusionCoeff;
	diffusionCoeff = FiniteDifference::getDiffusionCoefficient();
	double spaceGrid;
	spaceGrid = FiniteDifference::getGridWidth();
	double timeStep;
	timeStep = FiniteDifference::getTimeStep();
	double coeffCurrentSpace;
	coeffCurrentSpace = (2.0 * diffusionCoeff / (spaceGrid * spaceGrid) - 1.0 / \
						timeStep) * timeStep;
	return coeffCurrentSpace;
}

double ExplicitFiniteDifference::calCoeffPreviousSpace()
{
	double diffusionCoeff;
	diffusionCoeff = FiniteDifference::getDiffusionCoefficient();
	double spaceGrid;
	spaceGrid = FiniteDifference::getGridWidth();
	double timeStep;
	timeStep = FiniteDifference::getTimeStep();
	std::vector<double> velocity;
	velocity = FiniteDifference::getVelocityInDomain();
	coeffPreviousSpace = (diffusionCoeff / (spaceGrid * spaceGrid) + velocity[0] /\
						(2.0 * spaceGrid)) * timeStep;
}

void ExplicitFiniteDifference::outputDomainResults() const
{
	
}

void ExplicitFiniteDifference::calConcentration()
{
	/**/
}

