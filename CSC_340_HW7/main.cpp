/**
  * Name: main.cpp
  * Author: Iain Raleigh
  * Student ID: 915133718
  * Compiler: g++
  * Purpose: To test the functions in recursion.cpp
  */

#include "recursion.h"

int main() {
  Recursion r;
  struct Pair largest;
  int arr[MAX_SIZE];
  int size;
  int k;
  cout << "How many integers are in your list? ";
  cin >> size;
  cout << "Enter a list of "<< size <<" numbers: ";
  for(int i = 0;i<size;i++) cin >> arr[i];
  r.store(arr, size);
  cout << "This is the array in reverse: ";
  r.print_reverse();
  cout << endl;
  largest = r.largest_value();
  cout << endl <<largest.value <<" is the largest value at position "<< largest.index + 1 << endl << endl;
  cout << "Which smallest value would you like to see? ";
  cin >> k;
  cout << endl <<"That value is " <<r.find_k_smallest(k) << endl;

  return 0;
}
