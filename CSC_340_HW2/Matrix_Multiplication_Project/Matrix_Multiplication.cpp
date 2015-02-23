#include <iostream>
#include <vector>

using namespace std;

void multiply_matricies(vector< vector<int> >&, vector< vector<int> >&);

int main(){
	vector< vector<int> > A,B;
	int A_rows, A_columns;
	int B_rows, B_columns;
	cout << "How many rows are in matrix A? ";
	cin >> A_rows;
	cout << "How many columns are in matrix A? ";
	cin >> A_columns;
	A.resize(A_columns);
	for (int a = 0; a < A.size(); a++){
		A[a].resize(A_rows);
	}
	cout << "How many rows are in matrix B? ";
	cin >> B_rows;
	cout << "How many columns are in matrix B? ";
	cin >> B_columns;

	B.resize(B_columns);
	for (int b = 0; b < B.size(); b++){
		B[b].resize(B_rows);
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
	multiply_matricies(A,B);
	return 0;
}

void multiply_matricies(vector< vector<int> >& A, vector< vector<int> >& B){
	vector< vector<int> > C;
	C.resize(B.size());
	for (int c = 0; c < C.size(); c++){
		C[c].resize(A.size());
	}
	for (int i = 0; i < C.size();i++){
		for(int j = 0; j < C[0].size(); j++){
			 for(int k = 0; k < C[0].size(); k++){
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	for (int i = 0; i < C.size();i++){
		for(int j = 0; j < C[0].size(); j++){
			cout << C[i][j] << " ";
		}
		cout << endl;
	}
}
