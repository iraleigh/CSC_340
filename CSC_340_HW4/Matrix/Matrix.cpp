/**
*  Name      : Matrix
*  Author    : Iain Raleigh
*  Student ID: 915133718
*  Email     : iraleigh@mail.sfsu.edu
*  Compiler  : g++
*/
#include "Matrix.h"
matrix::matrix(){
  my_matrix.resize(0); //resizes the data member vector to zero
}
matrix::matrix(std::vector < std::vector<double> > par_matrix){
  my_matrix = par_matrix;
}
void matrix::size(int i, int j){
  my_matrix.resize(i);
  //resize each nested vector to the given j value
  for (int k = 0; k < i; k++){
    my_matrix[k].resize(j);
  }
}
double matrix::get_value(int i,int j) const{
  return my_matrix[i][j]; //return the value at (i, j)
}
void matrix::set_value(double a, int i ,int j){
  my_matrix[i][j] = a; //set the value at (i, j)
}
void matrix::transpose(){
  double a1, a2; //temp values
  //for each row
  for (int i = 0; i < my_matrix.size(); i++){
    //for each term starting from the diagonal
    for (int j = i; j < my_matrix[0].size(); j++) {
      //switch the terms accross the diagonal
      a1 = this->get_value(i,j);
      a2 = this->get_value(j,i);
      this->set_value(a2,i,j);
      this->set_value(a1,j,i);
    }
  }
}
matrix matrix::operator*(const matrix factor){
  matrix product;
  product.size(factor.my_matrix[0].size(),my_matrix.size());
  //for each row of the product
  for (int i = 0; i < product.my_matrix.size();i++){
    //for each column of the row
    for(int j = 0; j < product.my_matrix[0].size(); j++){
      //for each column in this matrix
      for(int k = 0; k < my_matrix[0].size(); k++){
        //take the product of the the respective prositions
        product.my_matrix[i][j] += my_matrix[i][k] * factor.my_matrix[k][j];
      }
    }
  }
  return product;
}
matrix matrix::operator*(double scalar){
  matrix product; //create a product matrix
  product.size(my_matrix.size(), my_matrix[0].size()); //resize it
  //for each row
  for (int i = 0; i < my_matrix.size(); i++){
    //for each column
    for (int j = 0; j < my_matrix[0].size(); j++) {
      //set the multiplied value to the product
      product.set_value((this->get_value(i,j) * scalar),i,j);
    }
  }
  return product;
}
matrix matrix::operator-(const matrix subtrahend){
  matrix difference; //create a difference matrix
  difference.size(my_matrix.size(), my_matrix[0].size()); //resize it
  //for each row
  for (int i = 0; i < my_matrix.size(); i++){
    //for each column
    for (int j = 0; j < my_matrix[0].size(); j++) {
      //set the subtracted value to the difference
      difference.set_value((this->get_value(i,j) - subtrahend.get_value(i,j)),i,j);
    }
  }
  return difference;
}
std::ostream& operator<<(std::ostream& os, const matrix out){
  //for each element in the matrix
  for (int i = 0; i < out.my_matrix.size();i++){
    for(int j = 0; j < out.my_matrix[0].size(); j++){
      os << out.my_matrix[i][j] << " "; //push to the out stream
    }
    os << std::endl; //endl is for formating
  }
  return os; //return the out stream
}
