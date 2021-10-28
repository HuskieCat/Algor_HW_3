#include <iostream>
#include "heaps.cpp"

using namespace std;

int main() 
{
  cout<<"Program Start"<<endl;

  int size = 100;
  int myArray[size];
  int myArray2[size];

  for(int i = 0; i < size; i++)
  {
    myArray[i] = i;
    myArray2[i] = i;
  }

  //print_heap(myArray, size);
  cout << "William Swaps: " << make_heap_williams(myArray, size) << endl;
  //print_heap(myArray, size);

  //cout<<endl;

  //print_heap(myArray2, size);
  cout << "Floyd Swaps: " << make_heap_floyd(myArray2, size) << endl;
  //print_heap(myArray2, size);

  cout<<"Program End"<<endl;
} 