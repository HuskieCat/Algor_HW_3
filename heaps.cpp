#include <iostream>

using namespace std;

void print_heap(int[], int);
bool is_heap(int[], int);
int fix_heap(int[], int, int);

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
    int swaps = 0;
    for(int i = size - 1; i > 0; i--)
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

        //Check sizes
        if(parent < leftChild || parent < rightChild)
        {
            if(leftChild > rightChild)
            {
                swap(list[parentIndex], list[leftChildIndex]);
                swaps++;
            }
            else
            {
                swap(list[parent], list[rightChildIndex]);
                swaps++;
            }
        }

        if(i <= (size/2) - 1)
        {
            swaps += fix_heap(list, size, parentIndex);
        }

    }
    return swaps;
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
        if(leftChildIndex < size - 1)
            leftChild = list[leftChildIndex];
        if(rightChildIndex < size - 1)
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

int fix_heap(int list[], int size, int parentIndex)
{
    if(parentIndex  <= -1)
        return 0;

    int swaps = 0;
    int leftChildIndex = (2 * parentIndex) + 1;
    int rightChildIndex = (2 * parentIndex) + 2;

    int parent = list[parentIndex];
    int leftChild = -1;
    int rightChild = -1;

    if(leftChildIndex < size)
        leftChild = list[leftChildIndex];
    if(rightChildIndex < size)
        rightChild = list[rightChildIndex];

    if((leftChild == -1) && (rightChild == -1))
        return swaps;

    if(parent < leftChild || parent < rightChild)
    {
        if(leftChild > rightChild)
        {
            swap(list[parentIndex], list[leftChildIndex]);
            swaps++;
        }
        else
        {
            swap(list[parentIndex], list[rightChildIndex]);
            swaps++;
        }
    }

    swaps += fix_heap(list, size, leftChildIndex);
    swaps += fix_heap(list, size, rightChildIndex);

    return swaps;
}