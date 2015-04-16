/**
*  Name      : Polynomial
*  Author    : Iain Raleigh
*  Student ID: 915133718
*  Email     : iraleigh@mail.sfsu.edu
*  Compiler  : g++
*/
#include "Polynomial.h"
#include <iostream>
using namespace std;
int main() {
  polynomial poly_1;
  polynomial poly_2;
  int power;
  double coefficient, scalar;
  poly_1.get_user_input();
  cout << poly_1 << "  is degree: " << poly_1.degree() << "\n";
  cout << "Enter the power of the term you would like to change: ";
  cin >> power;
  cout << "Enter a replacement coefficient: ";
  cin >> coefficient;
  poly_1.changeCoefficient(coefficient,power);
  cout << "Your polynomial is now:\n";
  poly_1.print();
  cout << "Create a second polynomial: ";
  poly_2.get_user_input();
  cout << "Enter a scalar to multiply it by: ";
  cin >> scalar;
  poly_2 = poly_2.multiply(scalar);
  cout << "Your 2nd polynomial is now:\n" << poly_2;
  cout << "Dividing it back to original";
  poly_2 = poly_2 / scalar;
  cout << "Your 2nd polynomial is now:\n" << poly_2;
  cout << "The 1st plus the 2nd = " << poly_1.add(poly_2) << "\n";
  cout << "The negation of the 1st is:\n" << -poly_1 << "\n";
  return 0;
}
