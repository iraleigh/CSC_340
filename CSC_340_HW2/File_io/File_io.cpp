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
/*
 * @parameters: The name of two files to be merged
 * @return: The name of the file that was merged into
 */
string merge_files(string,string);

int main(){
	string file1, file2;

	cout << "Enter the name of the first file: ";
	cin >> file1;
	cout << "Enter the name of the second file: ";
	cin >> file2;

	cout << "The merged file name is: " << merge_files(file1,file2);
	return 0;
}

string merge_files(string file1_name,string file2_name){
	ifstream file1(file1_name);
	ifstream file2(file2_name);
	ofstream file3("text3.txt",ofstream::out);
	if (file1.is_open()){
		if (file2.is_open()) {
			string number_from_1, number_from_2;

			//get the end of the first file
			file1.seekg(0,ios::end);
			int end_of_1 = (int)file1.tellg();
			file1.seekg (0, ios::beg);

			//get the end of the second file
			file2.seekg(0,ios::end);
			int end_of_2 = (int)file2.tellg();
			file2.seekg (0, ios::beg);
			int i = 0; // first file's iterator
			int j = 0; // second file's iterator
			int k = 0; // merged file's iterator

			//iterate through all three files until either file is at its end
			while ((i < end_of_1)&&(j < end_of_2)){

				file1.seekg(i, ios::beg); // set the new position of the streams
				file2.seekg(j, ios::beg); //
				file3.seekp(k, ios::beg); //

				int temp_1 = (int)file1.get(); //load integers into temp values
				int temp_2 = (int)file2.get(); //
				if(temp_1 < temp_2){
					file3.put((char)temp_1); // iterate depending on condition
					i++;
					k++;
				} else {
					file3.put((char)temp_2);
					j++;
					k++;
				}
			}
			while (i< end_of_1){	// if file1 still has remaining numbers append
				file1.seekg(i, ios::beg); // them to file3
				file3.seekp(k, ios::beg);
				file3.put(file1.get());
				i++;
				k++;
			}
			while (j<end_of_2) {  // if file2 still has remaining numbers append
				file2.seekg(j, ios::beg); // them to file3
				file3.seekp(k, ios::beg);
				file3.put(file2.get());
				j++;
				k++;
			}


		} else {
			cout << "could not find " << file2_name;
		}
	} else {
		cout << "could not find " << file1_name;
	}
	file1.close();
	file2.close();
	file3.close();
	return "text3.txt";
}
