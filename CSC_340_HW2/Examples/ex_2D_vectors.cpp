//use the user-defined class: myIntVector
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int num_rows{0};
	int num_cols{0};

	vector< vector<int> > matrix{{11,12},{21,22}};//initialize to a 2x2 matrix
	num_rows = matrix.size();
	num_cols = matrix[0].size();

	//print out the initial matrix
	cout << "=====2x2 matrix==========\n";
	for (int i=0; i<num_rows; i++) {
		for (int j=0; j<num_cols; j++ ){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	//resize the matrix to 5x6
	num_rows = 5;
	num_cols = 6;
	matrix.resize(num_rows); //reserve 5 rows
	for (int i=0; i<num_rows; i++) //reseve 6 cols for each row
		matrix[i].resize( num_cols );

    //print out the new and larger matrix
	cout << "=====5x6 matrix==========\n";
	for (int i=0; i<num_rows; i++) {
		for (int j=0; j<num_cols; j++ ){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
