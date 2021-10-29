#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include "heaps.cpp"

/**
 * Generates random unorganised heaps. The user at the command line can enter the length
 * of array they want and how many times it will try that. Then it'll spit out the average
 * of k trials.
 * 
 * @Author: Bradley Henderson
 */

using namespace std;

void fillArrays(int[], int[], int);
int getAverage(int[], int);
void printAverageArray(int[], int);

int main(int argc, char** argv)
{
    if(argc != 3)
        cout << "Please input: ./" << argv[0] << " <Size of Array> <Number of Trials>"
        << endl;

    int size = atoi(argv[1]);
    int repeat = atoi(argv[2]);

    srand(time(0));

    int williamArray[size];
    int williamAverages[repeat];

    int floydArray[size];
    int floydAverages[repeat];

    for(int i = 0; i < repeat; i++)
    {
        fillArrays(williamArray, floydArray, size);

        williamAverages[i] = make_heap_williams(williamArray, size);
        floydAverages[i] = make_heap_floyd(floydArray, size);
    }

    cout << "William average swaps: " << getAverage(williamAverages, repeat) << endl;
    cout << "Floyd average swaps: " << getAverage(floydAverages, repeat) << endl;

    return 0;
}

//Fills the arrays
void fillArrays(int array1[], int array2[], int size)
{
    //Not needed but for extra protection
    for(int i = 0; i < size; i++)
    {
        array1[i] = 0;
        array2[i] = 0;
    }

    for(int i = 0; i < size; i++)
    {
        array1[i] = rand() % 26;
        array2[i] = array1[i];
    }        
}

//Returns the average of an array
int getAverage(int averages[], int size)
{
    int sum = 0;
    for(int i = 0; i < size; i++)
        sum += averages[i];
    return sum / size;
}

//Prints individual values for the average arrays
void printAverageArray(int averages[], int size)
{
    for(int i = 0; i < size; i++)
        cout << averages[i] << " ";
    cout << endl;
}