/**
  * Name: Account_Exceptions.h
  * Author: Iain Raleigh
  * Student ID: 915133718
  * Compiler: g++
  */
#ifndef ACCOUNT_EXCEPTIONS_H
#define ACCOUNT_EXCEPTIONS_H
#include <stdexcept>
using namespace std;
class  Exception_Negative_Deposit: public exception {
public:
  virtual const char* what() const throw() {
    return "Can't deposit negative amount.";
  }
};
class  Exception_Overdraw: public exception {
public:
  virtual const char* what() const throw() {
    return "Overdraw.";
  }
};
class  Exception_Negative_Withdraw: public exception {
public:
  virtual const char* what() const throw() {
    return "Can't withdraw negative amount.";
  }
};
#endif
