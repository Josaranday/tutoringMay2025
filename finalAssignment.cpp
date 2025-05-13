#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

// the program will call these function prototypes
void getGrades();
int getTotal();
double getAverage(int);
int getLowest();
int getHighest();
void gradeDistribution();

const int SIZE = 5; // there are 5 different ranges, 5 is the size of the global array
int ranges[SIZE]; // declaring an array of size 5 - will detemine how many values fall into the following ranges
int myGradesArray[SIZE+15]; // array that will hold each value from the input text file


int main()
{

    int total, lowest, highest; // variable to hold the total and calculate the lowest and highest values from the array
    double average; // variable to calculate the average of all the grades stored in the array...initialize to zero

    getGrades(); //call a function

    cout << fixed << showpoint << setprecision(1); //output format for all values to screen


//*********************************************************************

    total = getTotal(); // call the function to get a total


//*********************************************************************

    average = getAverage(total); // call the function to get average


//**********************************************************************

    lowest = getLowest(); // call the function to determine lowest value from the array

//**********************************************************************

    highest = getHighest(); // call the function to determine highest value

//*********************************************************************

    gradeDistribution(); // Function call, calls a function to count values in certain ranges

    cout << setw(15) << "Lowest" << setw(15) << "Highest" << setw(15) << "Average" << endl;
    cout << setw(15) << lowest << setw(15) << highest << setw(15) << average << endl;
 //   cout << "Lowest: " << lowest << endl;
 //   cout << "Highest: " << highest << endl;
 //   cout << "Average: " << average << endl;

// Displays the values that fall into ranges and the number of values that fall in each of the ranges

    cout << "Grade Distribution" << endl;
    cout << " 0~59: " << ranges[0] << endl;
    cout << "60~69: " << ranges[1] << endl;
    cout << "70~79: " << ranges[2] << endl;
    cout << "80~89: " << ranges[3] << endl;
    cout << "90~100: " << ranges[4] << endl << endl;

    cout << "I enjoyed COSC1436. Looking forward to COSC1337 or next programming class!" << endl;

    return 0;

}

void getGrades()
{

//***************Read a file and populate an array with the values of file****************
// used to read data from a file
    fstream inFile;

// open the data file
    inFile.open("grades.txt");  

// Test if file exists
    if(!inFile)
    {
    cout << "Error opening file\n";
    cout << "Run the program again!!!\n";
    exit(1);
    }

    else
    {
    // Read data from file and store in array (values)
        for(int index = 0; index < SIZE+15; index++)
        {
        inFile >> myGradesArray[index]; //Read data and store in array
        // Validate data check if value is between 0 and 100 only
        if((myGradesArray[index] < 0) || (myGradesArray[index] > 100)) //input validation
        {
        cout << myGradesArray[index] << " is an invalid value. \n";
        cout << "Run the program again.\n";
        cout << "Fix the input file to include values between 0 and 100 only.\n";
        exit(1); // terminate program due to error trapping
        }
    }

    inFile.close();
    }

}

int getTotal()
{
// Read the Array and calculate the total of all values in the array

    int total =0;

    for(int i=0; i<SIZE+15; i++)
    {
    total = total + myGradesArray[i];
    }

    return total;

}


double getAverage(int total)
{
    double average = 0.0;
    // Calculate the average of the array values
    // Type cast total so you can get a double average

    average = double(total) / (SIZE+15);

    return average;

}


int getLowest()
{
// Determine the lowest value from the array
    int lowest;
    lowest = myGradesArray[0]; // initialize lowest with the first value/element of array
    // Use a for loop to cycle through the array and compare values
    // and update lowest if a lesser value is found
    for(int i = 1; i < SIZE+15; i++)
    {
    if(myGradesArray[i] < lowest)
    lowest = myGradesArray[i];
    }

    return lowest;
}


int getHighest()
{
// Determine the highest value from the array
    int highest;
    highest = myGradesArray[0];
    for(int i = 1; i < SIZE+15; i++)
    {
    if(myGradesArray[i] > highest)
    highest = myGradesArray[i];
    }

    return highest;

}

void gradeDistribution()
{
// Determine which values fall in a certain range
// set the values of each of the element of the range array to zero

    ranges [0] = 0; // 1st element to keep count of values between 0-59
    ranges [1] = 0; // 2nd element to keep count of values between 60-69
    ranges [2] = 0; // 3rd element to keep count of values between 70-79
    ranges [3] = 0; // 4th element to keep count of values between 80-89
    ranges [4] = 0; // 5th element to keep count of values between 90-100


    for(int count = 0; count < SIZE+15; count++)
    {
    // Determine if values of original array fall in the ranges of 0-59, 60-69, 70-79,
    // 80-89 and 90-100 and then keep a count of each set
    if ((myGradesArray[count] >= 0) && (myGradesArray[count] <= 59))
        {
        ranges[0] = ranges[0] + 1; //keeping count set 1
        }
    if ((myGradesArray[count] >= 60) && (myGradesArray[count] <= 69))
        {
        ranges[1] = ranges[1] + 1; //keeping count set 2
        }
    if ((myGradesArray[count] >= 70) && (myGradesArray[count] <= 79))
        {
        ranges[2] = ranges[2] + 1; //keeping count set 3
        }
    if ((myGradesArray[count] >= 80) && (myGradesArray[count] <= 89))
        {
        ranges[3] = ranges[3] + 1; //keeping count set 4
        }
    else if ((myGradesArray[count] >= 90) && (myGradesArray[count] <= 100))
        {
        ranges[4] = ranges[4] + 1; //keeping count set 5
        }
    }
}