/**
*  Name      : Matrix
*  Author    : Iain Raleigh
*  Student ID: 915133718
*  Email     : iraleigh@mail.sfsu.edu
*  Compiler  : g++
*/
#include "Matrix.h"
#include <vector>
using namespace std;

int main() {
  matrix m1;
  int m1_size;
  double m_a, m_b, B_rows, B_columns;
  vector< vector<double> > B;

  cout << "How many rows are in matrix A? ";
  cin >> m1_size;
  m1.size(m1_size, m1_size);
  for (int i = 0; i < m1_size; i++) {
    cout << "Enter the values in row " << i+1 << " of A:\n";
    for (int j = 0; j < m1_size; j++){
      cin >> m_a;
      m1.set_value(m_a, i, j);
    }
  }

  cout << "\nMatrix A is:\n" << m1;

  cout << "How many rows are in matrix B? ";
  cin >> B_rows;
  B_columns = B_rows;

  B.resize(B_rows);
  for (int b = 0; b < B.size(); b++){
    B[b].resize(B_columns);
  }
  for (int bi = 0; bi < B_rows; bi++) {
    cout << "Enter the values in row " << bi+1 << " of B:\n";
    for (int bj = 0; bj < B_columns; bj++){
      cin >> B[bi][bj];
    }
  }

  matrix m2(B);

  cout << "\nMatrix B is:\n" << m2;
  cout << "\nTransposing B. . .";
  m2.transpose();
  cout << "B is now:\n" << m2;

  cout << "\nA * B =\n" << m1 * m2;
  cout << "\nA * 10 = \n" << m1 * 10;
  cout << "\nA - B = \n" << m1 - m2;

  return 0;
}
