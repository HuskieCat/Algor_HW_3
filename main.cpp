#include <iostream>
#include "heaps.cpp"

using namespace std;

int main() 
{
  cout<<"Program Start"<<endl;

  int size = 10;
  int myArray[size];

  for(int i = 0; i < size; i++)
  {
    myArray[i] = i;
  }

  //print_heap(myArray, size);

  cout << "Swaps: " << make_heap_williams(myArray, size) << endl;

  print_heap(myArray, size);

  cout<<"Program End"<<endl;
} 