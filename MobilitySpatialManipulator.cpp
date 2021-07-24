#include <iostream>
#include<vector>
#include <ctype.h>

int mobility(int rigidBodies, int joints, std::vector <int> constraint);

int main()
{
	int rb = { 0 };
	int j = { 0 };
	std::vector<int> constraint;
	
	std::cout << "Enter the total number of mobile Rigid bodies : ";
	std::cin >> rb;
	std::cout << "\nEnter the total number of joints in the planar manipulator : ";
	std::cin >> j;
	std::cout << "" << std::endl;

	for (size_t i = 0; i < j; i++)
	{
		constraint.push_back(0);
	}

	int mob = mobility(rb, j, constraint);
	std::cout << "======================================================" << std::endl;
	std::cout << "Mobility of the given Planar Manipulator is : " << mob << std::endl;
	std::cout << "======================================================" << std::endl;
	return 0;
}

// Mobility of a Planar Manipulator
int mobility(int rigidBodies, int joints, std::vector <int> constraint)
{
	int DOF = { 0 };

	//std::vector <int> constraint;
	int total_constraint = { 0 };
	char manipType;
	int maxDOF = 0;
	std::cout << "Press 'P' for Planar manipulator and 'S' for Spatial Manipulator : ";
	std::cin >> manipType;
	std::cout << "" << std::endl;

	if (toupper(manipType) == 'P')
	{
		maxDOF = 3;
	}
	else if (toupper(manipType) == 'S')
	{
		maxDOF = 6;
	}
	else
	{
		std::cout << "Invalid Entry !!! Exiting Program" << std::endl;
		exit(0);
	}
	
	// DOF of each joint
	char decision;
	std::cout << "Whether any of your joint has Degree of Freedom more than 1 ? (y/n) :";
	std::cin >> decision;
	std::cout << "" << std::endl;

	if (toupper(decision) == 'N')
	{
		for (size_t i = 0; i < joints; i++)
		{
			constraint[i] = 1;
		}
	}
	else
	{
		for (size_t i = 0; i < joints; i++)
		{
			do
			{
				std::cout << "Enter the Degrees of freedom joint " << i + 1 << " : ";
				std::cin >> constraint[i];
				std::cout << "\n";
			} while (constraint[i] < 0 || constraint[i] > maxDOF);
		}
	}

	// Total Contraint imposed by the system
	for (size_t i = 0; i < joints; i++)
	{
		total_constraint += (maxDOF - constraint[i]);
	}

	std::cout << "The total constraint on the system is : " << total_constraint << std::endl;

	DOF = maxDOF * rigidBodies - total_constraint;
	return DOF;
}