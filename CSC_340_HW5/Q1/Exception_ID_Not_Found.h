/**
  * Name: Exception_ID_Not_Found.h
  * Author: Iain Raleigh
  * Student ID: 915133718
  * Compiler: g++
  */
#ifndef EXCEPTION_ID_NOT_FOUND
#define EXCEPTION_ID_NOT_FOUND
#include <stdexcept>
#include <string>
using namespace std;
class Exception_ID_Not_Found: public exception{
public:
  virtual const char* what() const throw() {
    return "ID not found.";
  }
};
int getProductID(int ids[], string names[], int numProducts, string target);
#endif
