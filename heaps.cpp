#include <iostream>

using namespace std;

//Transforms list into a headp using the Williams method.
//Returns the number of swaps performed.
int make_heap_williams(int list[], int size)
{
    int swaps = 0;
    for(int i = 0; i < (size / 2); i++)
    {
        //Get index
        int leftChildIndex = (2 * i) + 1;
        int rightChildIndex = (2 * i) + 2;

        int parent = list[i];
        int leftChild = -1;
        int rightChild = -1;

        //Get values of parent and children
        if(leftChildIndex < size)
            leftChild = list[leftChildIndex];
        if(rightChildIndex < size)
            rightChild = list[rightChildIndex];

        //Check sizes
        if(parent < leftChild || parent < rightChild)
        {
            if(leftChild < rightChild)
            {
                swap(list[rightChildIndex], list[i]);
                swaps++;
            }
            else
            {
                swap(list[leftChildIndex], list[i]);
                swaps++;
            }
        }
    }

    if(!is_heap(list, size))
    {
        swaps += make_heap_williams(list, size);
    }

    return swaps;
}

//Transforms list into a heap using the Floyd (bottom-up) method.
//Returns the number of swaps performed.
int make_heap_floyd(int list[], int size)
{
    int swap = 0;
    for(int i = size; i > 0; i--)
    {
        //Index of parent and children
        int parentIndex = (i - 1) / 2;
        int leftChildIndex = (2 * parentIndex) + 1;
        int rightChildIndex = (2 * parentIndex) + 2;

        //Value of children and parent
        int parent = list[parentIndex];
        int leftChild = -1;
        int rightChild = -1;

        if(leftChildIndex < size)
            leftChild = list[leftChildIndex];
        if(rightChildIndex < size)
            rightChild = list[rightChildIndex];

        
    }
}

void print_heap(int list[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
    return;
}

bool is_heap(int list[], int size)
{
    for(int i = 0; i < size; i++)
    {
        int leftChildIndex = (2 * i) + 1;
        int rightChildIndex = (2 * i) + 2;

        int parent = list[i];
        int leftChild = -1;
        int rightChild = -1;
        if(leftChildIndex < size)
            leftChild = list[leftChildIndex];
        if(rightChildIndex < size)
            rightChild = list[rightChildIndex];

        if(parent < leftChild)
        {
            return false;
        }
        else if(parent < rightChild)
        {
            return false;
        }
    }
    return true;
}