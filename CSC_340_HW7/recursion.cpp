/**
  * Name: recursion.cpp
  * Author: Iain Raleigh
  * Student ID: 915133718
  * Compiler: g++
  * Purpose: To implement the functions in recursion.h
  */
#include "recursion.h"
#include <algorithm>

Recursion::Recursion(){
  for(int i = 0; i < MAX_SIZE; i++){
    arr[i] = 0;
  }
  size = MAX_SIZE;
}
void Recursion::store(int* values, int size){
  for(int i = 0; i < size; i++){
    arr[i] = values[i];
  }
  this->size = size;
}
void Recursion::print_reverse(){
  p_rev(this,0);
}
struct Pair Recursion::largest_value(){
  struct Pair lp;
  lp.index = l_val(*this,0,1);
  lp.value = arr[lp.index];
  return lp;
}
int Recursion::find_k_smallest(int k){
  return arr[k_small(k,*this,0,size-1)];
}
void p_rev(Recursion* r, int i){
  if (i < (r->size - 1))
    p_rev(r,i+1);
  cout << r->arr[i] << " ";
}
void Recursion::swap(int i, int j){
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}
int l_val(const Recursion& r,int i, int j){
  if (i < (r.size -1) && j < (r.size)){
    if(r.arr[i] < r.arr[j])
      return l_val(r,j,j+1);
    else
      return l_val(r,i,j+1);
  } else {
    return i;
  }
}
int k_small(int k , Recursion& r,int f,int l){
  int q = partition(r,f,l);
  if(k == (q-f+1)){
    return q;
  } else if(k < (q-f+1)){
    return k_small(k,r,f,q-1);
  } else {
    return k_small(k-(q-f+1),r,q+1,l);
  }
}
int partition(Recursion& r,int p, int n){
  int x = r.arr[n];
  int i = p - 1;
  for (int j = p; j < n; j++){
    if (r.arr[j] <= x){
      i++;
      r.swap(i,j);
    }
  }
  r.swap(i+1,n);
  return i+1;
}
