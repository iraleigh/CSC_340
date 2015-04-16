/**
*  Name      : Polynomial
*  Author    : Iain Raleigh
*  Student ID: 915133718
*  Email     : iraleigh@mail.sfsu.edu
*  Compiler  : g++
*/
#include "Polynomial.h"
polynomial::polynomial(){
  my_polynomial.resize(0); //set default size to 0
}
void polynomial::get_user_input(){
  int degree = 0;
  std::cout << "Enter the degree: ";
  std::cin >> degree;
  my_polynomial.resize(degree); //set the size to contain all terms necessary
  for (int i = 0; i < degree; i++) {
    std::cout << "Enter coefficient of x^" << degree - i <<":  ";
    std::cin >> my_polynomial[i].coefficient; //set coefficient
    my_polynomial[i].power = degree - i; //set degree
  }
}
int polynomial::degree() const{
  int i = 0;
  while (my_polynomial[i].coefficient == 0) //find the first non-zero
    i++;                                    //coefficient
  return my_polynomial[i].power;
}
double polynomial::coefficient(int power) const{
  return my_polynomial[power].coefficient; //return requested coefficient
}
void polynomial::changeCoefficient(double newCoefficient, int power){
  my_polynomial[power-1].coefficient = newCoefficient; //set the value
}
polynomial polynomial::multiply(double scalar) const{
  polynomial product_polynomial; //create return polynomial
  product_polynomial.my_polynomial.resize(my_polynomial.size()); //resize it
  for (int i = 0; i < my_polynomial.size(); i++){ //for each term
    //multiply it by a scalar
    product_polynomial.my_polynomial[i].coefficient = my_polynomial[i].coefficient * scalar;
  }
  return product_polynomial; //return product
}
polynomial polynomial::add(const polynomial addend_polynomial) const{
  polynomial sum_polynomial; //create return polynomial
  sum_polynomial.my_polynomial.resize(my_polynomial.size()); //resize it
  for (int i = 0; i < my_polynomial.size(); i++){ //for each term
    //add by the corresponding term in addend_polynomial
    sum_polynomial.my_polynomial[i].coefficient = my_polynomial[i].coefficient + addend_polynomial.my_polynomial[i].coefficient;
  }
  return sum_polynomial;
}
void polynomial::print() const{
  //print the first term
  std::cout << my_polynomial[0].coefficient << "x^" << my_polynomial[0].power;
  for (int i = 1; i < my_polynomial.size(); i++) {
    //print every other term with an equal sign
    std::cout <<" + "<< my_polynomial[i].coefficient << "x^" << my_polynomial[i].power;
  }
  std::cout << "\n";
}
polynomial polynomial::operator/(double scalar) const{
  polynomial quotient_polynomial; //create return polynomial
  quotient_polynomial.my_polynomial.resize(my_polynomial.size()); //resize it
  for (int i = 0; i < my_polynomial.size(); i++){ //for each term
    //divide by scalar
    quotient_polynomial.my_polynomial[i].coefficient = my_polynomial[i].coefficient / scalar;
  }
  return quotient_polynomial;
}
polynomial polynomial::operator-(){
  polynomial neg_polynomial; //create return polynomial
  neg_polynomial.my_polynomial.resize(my_polynomial.size()); //resize it
  for (int i = 0; i < my_polynomial.size(); i++){ //for each term
    //negate it
    neg_polynomial.my_polynomial[i].coefficient = -my_polynomial[i].coefficient;
  }
  return neg_polynomial;
}
std::ostream& operator<<(std::ostream& out_s, const polynomial out_polynomial){
  //output the first term
  out_s << out_polynomial.my_polynomial[0].coefficient << "x^" << out_polynomial.my_polynomial[0].power;
  for (int i = 1; i < out_polynomial.my_polynomial.size(); i++) {
    //output the following terms with an equal sign
    out_s <<" + "<< out_polynomial.my_polynomial[i].coefficient << "x^" << out_polynomial.my_polynomial[i].power;
  }
  out_s << "\n\n";
  return out_s;
}
