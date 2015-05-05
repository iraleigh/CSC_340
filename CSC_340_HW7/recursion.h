/**
  * Name: recursion.h
  * Author: Iain Raleigh
  * Student ID: 915133718
  * Compiler: g++
  * Purpose: To define the functions in the rest of the program
  */
#ifndef RECURSION_H
#define RECURSION_H
#include <iostream>

using namespace std;

const int MAX_SIZE = 100;
struct Pair{
  int value;
  int index;
};

class Recursion {
private:
  int arr[MAX_SIZE];
  int size;
  int pivot_point;
public:
  Recursion();
  void store(int*,int);
  void print_reverse();
  struct Pair largest_value();
  int find_k_smallest(int);
  void swap(int,int);//helper of partition()
  friend void p_rev(Recursion*,int);
  friend int l_val(const Recursion&,int,int);//helper of largest_value()
  friend int k_small(int,Recursion&,int,int);//helper of find_k_smallest()
  friend int partition(Recursion&,int,int);//helper of k_small()
};
#endif
