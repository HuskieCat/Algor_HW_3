#include <iostream>

/**
 * Backend for organizing heaps via two methods, Williams and Floyd
 * 
 * @author: Bradley Henderson
 */

using namespace std;

void print_heap(int[], int);
bool is_heap(int[], int);
int fix_heap(int[], int, int);
void set_children_values(int[], int, int&, int&, int&, int&);
int peform_swap(int[], int&, int&, int&, int&, int&, int&);

//Transforms list into a headp using the Williams method.
//Returns the number of swaps performed.
int make_heap_williams(int list[], int size)
{
    int swaps = 0;
    for(int i = 0; i < (size / 2); i++)
    {
        //Get index
        int parentIndex = i;
        int leftChildIndex = (2 * i) + 1;
        int rightChildIndex = (2 * i) + 2;

        int parent = list[i];
        int leftChild;
        int rightChild;
        set_children_values(list, size, 
                        leftChildIndex, rightChildIndex, leftChild, rightChild);

        swaps += peform_swap(list, parentIndex, leftChildIndex, rightChildIndex, 
                               parent, leftChild, rightChild);
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
        int leftChild;
        int rightChild;
        set_children_values(list, size, 
                        leftChildIndex, rightChildIndex, leftChild, rightChild);

        swaps += peform_swap(list, parentIndex, leftChildIndex, rightChildIndex, 
                               parent, leftChild, rightChild);

        if(i <= (size/2) - 1)
        {
            swaps += fix_heap(list, size, parentIndex);
        }

    }
    return swaps;
}

//Prints the heap, good for testing
void print_heap(int list[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
    return;
}

//Checks a heap top-down to make sure everything is a heap
bool is_heap(int list[], int size)
{
    for(int i = 0; i < size; i++)
    {
        int leftChildIndex = (2 * i) + 1;
        int rightChildIndex = (2 * i) + 2;

        int parent = list[i];
        int leftChild;
        int rightChild;
        set_children_values(list, size, 
                        leftChildIndex, rightChildIndex, leftChild, rightChild);

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

//Essentually bubbling down the heap to fix the sub heaps.
int fix_heap(int list[], int size, int parentIndex)
{
    if(parentIndex  <= -1)
        return 0;

    int swaps = 0;
    int leftChildIndex = (2 * parentIndex) + 1;
    int rightChildIndex = (2 * parentIndex) + 2;

    int parent = list[parentIndex];
    int leftChild;
    int rightChild;

    set_children_values(list, size, 
                        leftChildIndex, rightChildIndex, leftChild, rightChild);

    if((leftChild == -1) && (rightChild == -1))
        return swaps;

    swaps += peform_swap(list, parentIndex, leftChildIndex, rightChildIndex, 
                               parent, leftChild, rightChild);

    swaps += fix_heap(list, size, leftChildIndex);
    swaps += fix_heap(list, size, rightChildIndex);

    return swaps;
}

//Sets the values for the left and right children
void set_children_values(int list[], int size, 
                  int &leftChildIndex, int &rightChildIndex, 
                  int &leftChild, int &rightChild)
{
    leftChild = -1;
    rightChild = -1;

    //Get values of parent and children
    if(leftChildIndex < size)
        leftChild = list[leftChildIndex];
    if(rightChildIndex < size)
        rightChild = list[rightChildIndex];
}

//Performs the swaps and returns 1 or 0 depending if it actually gets swapped
int peform_swap(int list[], int &parentIndex, int &leftChildIndex, int &rightChildIndex, 
                            int &parent, int &leftChild, int &rightChild)
{
    if(parent < leftChild || parent < rightChild)
    {
        if(leftChild > rightChild)
        {
            swap(list[parentIndex], list[leftChildIndex]);
            return 1;
        }
        else
        {
            swap(list[parentIndex], list[rightChildIndex]);
            return 1;
        }
    }
    return 0;
}