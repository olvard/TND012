// dugga1.cpp 
// Namn : Oliver lundin
// liu id: olilu316
// personal number: 200003116019

#include <iostream>

int main()
{
	//Ask the user with a menu and read option
	std::cout << "Triangle validation: 1 = angles, 2 = sides \n";

	int option = 0;

	std::cin >> option;

	//If statement for either option

	if (option == 1)
	{

		int alfa = 0;
		int beta = 0;
		int ceta = 0;

		std::cout << "Enter three angles: \n";

		std::cout << "Angle 1: "; std::cin >> alfa;
		std::cout << "Angle 2: "; std::cin >> beta;
		std::cout << "Angle 3: "; std::cin >> ceta;
		
		//first check if all angles are > 0

		if ((alfa > 0 && beta > 0 && ceta > 0))
		{

			int suma = alfa + beta + ceta;

			//check if the different possible outputs with more if statements

			if(suma == 180)
			{
				if (alfa == beta && alfa == ceta && beta == ceta)
				{
					std::cout << "Equilateral";
				}
				else if (alfa == beta || alfa == ceta || beta == ceta)
				{
					std::cout << "Isosceles";
				}
				else
					std::cout << "Valid triangle";
			}
			else 
			{
			 std::cout << "Invalid triangle";
			}

		}
		else
		{
		std::cout << "Invalid input, all angles must be > 0";
		}

	}

	//Program continues here for option 2

	else if (option == 2)
	{

		int a = 0;
		int b = 0;
		int c = 0;

		std::cout << "Enter 3 sides: \n";
		std::cout << "side a: "; std::cin >> a;
		std::cout << "side b: "; std::cin >> b;
		std::cout << "side c: "; std::cin >> c;

		//Check if all sides are > 0
		
		if ((a > 0 && b > 0 && c > 0))
		{

			//if statement for different possible outputs

			if ((a + b > c) && (a + c > b) && (b + c > a))
			{
				
				if (a == b && a == c && b == c)
				{
					std::cout << "Equilateral";
				}
				else if (a == b || a == c || b == c)
				{
					std::cout << "Isosceles";
				}
				else
					std::cout << "Valid triangle";
	
			}
			else
			{
				std::cout << "Invalid triangle";
			}
		}
		else
		{
			std::cout << "All sides must be > 0";
		}

	}
	else
	{
		std::cout << "Invalid option";
	}




}

