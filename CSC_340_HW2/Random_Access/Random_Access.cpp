/**
*  Name      : Word Frequency Counter
*  Author    : Iain Raleigh
*  Student ID: 915133718
*  Email     : iraleigh@mail.sfsu.edu
*  Compiler  : g++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void random_access();

int main() {
	random_access();
	return 0;
}
void random_access(){
	cout<<"\nAccessing File...";
	fstream file("file1.txt", fstream::app);
	if (file.is_open()){
		cout << "Success.";
		cout <<"\nInserting numbers at line 6000...";
		// Append these numbers to the end of the file
		// to create space within the file
		for (int i = 81; i >= 77; i--) {
		file << "77" << i << "\n";
		}

		file.close();
		file.open("file1.txt"); // reopen the file without append flag


		// ** put the appended numbers in an array
		file.seekg(-25,ios::end);
		char * numbers = new char(25);
		file.read(numbers,25);
		// **

		// Move all of the numbers in the file, up to line 6000
		// into the appended space.
		for (int j = 0; j < 4000; j++) {
			file.seekg((-30-(j*5)),ios::end);
			string line;
			getline(file,line);
			file.seekp((-5-(j*5)),ios::end);
			file << line << "\n";
		}
		// Put the numbers into the correct position
		file.seekp(30000,ios::beg);
		file << numbers;
		file.close();
		delete numbers;

		cout << "Success.\n";
	} else {
		cout <<"file1.txt is could not be opened";
	}

}
