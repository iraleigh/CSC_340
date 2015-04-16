/**
  * Name: main.cpp
  * Author: Iain Raleigh
  * Student ID: 915133718
  * Compiler: g++
  * Purpose: To test the functions in Account.cpp and Account_Exceptions.cpp
  */
#include <iostream>
#include "Account.h"
#include "Account_Exceptions.h"

using namespace std;

int main() {
  Account a;
  try {
    a.deposit(-1);
  } catch(exception& e){
    cerr << e.what() << endl;
  }
  try {
    a.withdraw(-1);
  } catch (exception& e) {
    cerr << e.what() << endl;
  }
  try {
    a.withdraw(1);
  } catch (exception& e){
    cerr << e.what() << endl;
  }
  return 0;
}
