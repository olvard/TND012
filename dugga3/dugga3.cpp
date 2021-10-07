// ============================================================
// TND012: Dugga 3
// Name: Oliver Lundin  
// LiU-id: olilu316
// ============================================================

#include <iostream>
#include <cstdlib>  // std::rand
#include <ctime>    // used for seeding the random generator
#include <cmath>    // used for sqrt operator
#include <iomanip>  // used to set precision

//What does the program compute?
//It seems like the program is converging towards pi(3.14159...)

//FUNCTION DECLARATION

//Reads input number of points to made.
int getNumberOfSamples();

//Generates random double numbers.
double getRandomNumber();

//Datatype for a point in 2D space.
struct point
{
    double x;
    double y;
};

//Creates random point by using getrandomnumber function.
point getRandomPoint();

//Checks if the point is inside a square.
bool insideSquare(point p);

//checks if the point is inside a circle.
bool insideCircle(point p);

//Prints the ratio between the points inside the circle over the points inside the square.
void printRatio(int a, int b);

int main()
{
   
    int input = getNumberOfSamples();

    //Declaring counters
    int nsquare = 0;
    int ncircle = 0;

    std::srand((unsigned)std::time(0));  // use current time as seed for random generator

    //For loop to loop get the correct amount of points requested by the user.
    for (int i = 0; i < input; i++)
    {
        //declaring a variable of type point to a random number.
        point coord = getRandomPoint();

        //Check if it is inside the square with function. Adds 1 to counter if it is.
        if (insideSquare(coord))
        {
            nsquare++;
        }
      
        //Check if it is inside circle with function. Adds 1 to counter if it is.
        if (insideCircle(coord))
        {
            ncircle++;
        }

    }

    //displays the ratio between the counters by using function.
    printRatio(ncircle, nsquare);


}


//FUNCTION DEFINITION

int getNumberOfSamples()
{

    int input;

    do
    {
        std::cout << "Number of samples: ";

        std::cin >> input;

    } while (input <= 0);

    return input;
}

double getRandomNumber()
{

    constexpr double Max = RAND_MAX;

    double r = std::rand() / Max;

    double random = 2.0 * r - 1.0;

    return random;
}


point getRandomPoint()
{
    //Creating a point with custom datatype.
    point coord;

    //assigning x and y doubles of datatype to randomnr by using getrandomnumber function.
    coord.x = getRandomNumber();
    coord.y = getRandomNumber();

    return coord;
}

bool insideSquare(point p)
{
    //Declaring doubles for unit square limits.
    double y_max = 0.5;
    double y_min = -0.5;
    double x_max = 0.5;
    double x_min = -0.5;

    if (p.y < y_max && p.y > y_min && p.x < x_max && p.x > x_min)
    {
        return true;
    }
    else return false;
}

bool insideCircle(point p)
{
    double radius = 1;

    //Using origa point to measure.
    double ox = 0.0;
    double oy = 0.0;

    //Using distance formula to calculate distance from origo to a random point.
    //Note, the use of ox and oy is not neccessary but helps demonstrate what is being done.
    double d = sqrt(((p.x - ox) * (p.x - ox)) + ((p.y - oy) * (p.y - oy)));

    //if the distance is smaller than the radius then the point lies inside the circle.
    if (d < radius)
    {
        return true;
    }
    else return false;


}

void printRatio(int a, int b)
{
    std::cout << std::setprecision(7) << std::fixed; // Sets the precision to 7 decimals.

    //When the program is given small samples, there is a chance that there are no points inside
    //the circle and the console will then return "inf" as ratio.
    if (b == 0)
    {
        std::cout << "Ratio can not be calculated, there are no points inside the square.";
    }
    else
    {
        double ratio = (double)a / (double)b;
        std::cout << "Ratio: " << ratio;
    }
}