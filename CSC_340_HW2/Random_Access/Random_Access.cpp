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
	cout<<"\nAccessing File...\n";
	fstream file("file1.txt");
	if (file.is_open()){
		file.seekp(30000);
		file.seekg(30000);
		cout <<"\nInserting numbers at line 6000...\n";
		int i = 0;
		do {
			cout << (int)(file.get() - 48);
			file.seekg(1,file.cur);
			i++;
		} while (i<4);
		cout <<"\nRandom Access, success.\n";
	} else {
		cout <<"file1.txt is could not be opened";
	}

}
