/**
*  Name      : Matrix
*  Author    : Iain Raleigh
*  Student ID: 915133718
*  Email     : iraleigh@mail.sfsu.edu
*  Compiler  : g++
*/
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
class matrix {
public:
  //default constructor:
  //initializes my_matrix to 0
  matrix();
  //explicit constructor:
  //creates a matrix object from a vector of vectors
  matrix(std::vector < std::vector<double> >);
  //sets the size fo the matrix to the given parameters
  void size(int,int);
  //returns the value at a location (i, j) given from
  //paramerters
  double get_value(int,int) const;
  //sets a value at a location (i, j) given from
  //parameters
  void set_value(double, int,int);
  //transposes the matrix along its diagonal
  void transpose();
  //overloads the * to multiply two matrices and return a matrix
  matrix operator*(const matrix);
  //overloads the * to multipy a matrix to a scalar and returns
  //a matrix
  matrix operator*(double);
  //overloads the - to subtract to matrices of the same dimension
  matrix operator-(const matrix);
  //overloads the << to send the matrix to an ostream
  friend std::ostream& operator<<(std::ostream&, const matrix);
private:
  //a vector of vectors to hold the matrix
  std::vector< std::vector <double> > my_matrix;
};
#endif
