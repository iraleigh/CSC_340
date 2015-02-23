#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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

			file1.seekg(0,ios::end);
			int end_of_1 = (int)file1.tellg();
			file1.seekg (0, ios::beg);

			file2.seekg(0,ios::end);
			int end_of_2 = (int)file2.tellg();
			file2.seekg (0, ios::beg);
			int i = 0;
			int j = 0;
			int k = 0;

			while ((i < end_of_1)&&(j < end_of_2)){

				file1.seekg(i, ios::beg);
				file2.seekg(j, ios::beg);
				file3.seekp(k, ios::beg);

				int temp_1 = (int)file1.get();
				int temp_2 = (int)file2.get();
				if(temp_1 < temp_2){
					file3.put((char)temp_1);
					i++;
					k++;
				} else {
					file3.put((char)temp_2);
					j++;
					k++;
				}
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
