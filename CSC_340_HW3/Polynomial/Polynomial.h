/**
*  Name      : Polynomial
*  Author    : Iain Raleigh
*  Student ID: 915133718
*  Email     : iraleigh@mail.sfsu.edu
*  Compiler  : g++
*/
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
#include <vector>

// this is to maintain a high level of readabilty
// but is not a necessary feature.
struct term {double coefficient; int power;};

class polynomial {

public:
  //default constructor
  polynomial();
  //get user input to fill the polynomial vector
  void get_user_input();
  //return the value of the highest power
  int degree() const;
  //return the coefficient at given term; determined by the power
  double coefficient(int) const;
  //change coefficient at given term
  void changeCoefficient(double, int);
  //multiply all coefficients by a double
  polynomial multiply(double) const;
  //add two polynomials
  polynomial add(const polynomial) const;
  //print this polynomial
  void print() const;
  //overload / to devide by double
  polynomial operator/(double) const;
  //overload - to negate the polynomial
  polynomial operator-();
  //overload << to push the polynomial to an out stream
  friend std::ostream& operator<<(std::ostream&, const polynomial);

private:
  std::vector<term> my_polynomial;
};

#endif
