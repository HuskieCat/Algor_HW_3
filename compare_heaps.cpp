#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include "heaps.cpp"

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

void fillArrays(int array1[], int array2[], int size)
{
    for(int i = 0; i < size; i++)
    {
        array1[i] = 0;
        array2[i] = 0;
    }

    for(int i = 0; i < size; i++)
        array1[i] = rand() % 26;

    for(int i = 0; i < size; i++)
        array2[i] = array1[i];
}

int getAverage(int averages[], int size)
{
    int sum = 0;
    for(int i = 0; i < size; i++)
        sum += averages[i];
    return sum / size;
}

void printAverageArray(int averages[], int size)
{
    for(int i = 0; i < size; i++)
        cout << averages[i] << " ";
    cout << endl;
}