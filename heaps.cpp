#include <iostream>

using namespace std;

void print_heap(int list[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << list[i] << ", ";
    }
    cout << endl;
    return;
}

//Transforms list into a headp using the Williams method.
//Returns the number of swaps performed.
int make_heap_williams(int list[], int size)
{
    int swaps = 0;
    for(int i = 1; i < size; i++)
    {
        //Get Index
        int parentIndex = (i - 1) / 2;
        int leftChildIndex = (2 * i) + 1;
        int rightChildIndex = (2 * i) + 2;

        int parent = 0;
        int leftChild = 0;
        int rightChild = 0;

        //Get values of parent and children
        if(parentIndex < size && parentIndex > -1)
        {
            parent = list[parentIndex];
            if(leftChildIndex < size)
                leftChild = list[leftChildIndex];
            else
                leftChild = -1;
            if(rightChildIndex < size)
                rightChild = list[rightChildIndex];
            else
                rightChild = -1;
        }

        //Check sizes
        if(parent < leftChild || parent < rightChild)
        {
            if(leftChild < rightChild)
            {
                swap(list[rightChildIndex], list[parentIndex]);
                swaps++;
            }
            else
            {
                swap(list[leftChildIndex], list[parentIndex]);
                swaps++;
            }
        }
    }

    return swaps;
}