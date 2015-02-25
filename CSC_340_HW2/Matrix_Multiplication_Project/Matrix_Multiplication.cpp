#include <iostream>
#include <vector>

using namespace std;
/*
 * @parameters: two references to matrices A and B of nxm and mxn respectively
 * @return: a matrix of nxn that is the product of Matrix A and B.
 */
vector< vector <int> > multiply_matricies(vector< vector<int> >&, vector< vector<int> >&);

int main(){
	vector< vector<int> > A,B,C;
	int A_rows, A_columns;
	int B_rows, B_columns;
	cout << "How many rows are in matrix A? ";
	cin >> A_rows;
	cout << "How many columns are in matrix A? ";
	cin >> A_columns;

	A.resize(A_rows);
	for (int a = 0; a < A.size(); a++){
		A[a].resize(A_columns);
	}
	cout << "How many rows are in matrix B? ";
	cin >> B_rows;
	cout << "How many columns are in matrix B? ";
	cin >> B_columns;

	B.resize(B_rows);
	for (int b = 0; b < B.size(); b++){
		B[b].resize(B_columns);
	}

	for (int ai = 0; ai < A_rows; ai++) {
		cout << "Enter the values in row " << ai+1 << " of A:\n";
		for (int aj = 0; aj < A_columns; aj++){
			cin >> A[ai][aj];
		}
	}
	cout << "\n\nNext...\n\n";

	for (int bi = 0; bi < B_rows; bi++) {
		cout << "Enter the values in row " << bi+1 << " of B:\n";
		for (int bj = 0; bj < B_columns; bj++){
			cin >> B[bi][bj];
		}
	}

	cout << "\n\nCalculating...\n\n";


	cout << "The product of A and B is: \n";

	C = multiply_matricies(A,B);

	for (int i = 0; i < C.size();i++){
		for(int j = 0; j < C[0].size(); j++){
			cout << C[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

vector< vector<int > > multiply_matricies(vector< vector<int> >& A, vector< vector<int> >& B){
	vector< vector<int> > C;
	C.resize(B[0].size()); 								// Create a matrix
	for (int c = 0; c < C.size(); c++){   // of the correct size
		C[c].resize(A.size());              // with respects to A*B.
	}
	for (int i = 0; i < C.size();i++){           // For each row in
		for(int j = 0; j < C[0].size(); j++){      // each column of C,
			 for(int k = 0; k < A[0].size(); k++){   // calculate the summation
				C[i][j] += A[i][k] * B[k][j];          // of products for each element
			}                                        // in A and B
		}
	}
	return C;
}
