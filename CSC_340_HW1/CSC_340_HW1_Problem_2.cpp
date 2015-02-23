/**
 *  Name      : Word Frequency Counter
 *  Author    : Iain Raleigh
 *  Student ID: 915133718
 *  Email     : iraleigh@mail.sfsu.edu
 *  Compiler  : g++ -std=c++11
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> readData();
void selectionSort(vector<int>& numbers);
void printVector(vector<int>& numbers);

int main() {
  vector<int> numbers = readData();
  selectionSort(numbers);
  printVector(numbers);
  return 0; 
}

vector<int> readData(){
  string listOfNumbers = "";
  vector<int> numbers(0);
  cout << "Enter Numbers to be sorted: ";
  getline(cin,listOfNumbers);
  int start = 0;
  size_t end = listOfNumbers.find(" ");
  while (end != string::npos) {
    numbers.push_back(stoi(listOfNumbers.substr(start, end - start)));
    start = end + 1;
    end = listOfNumbers.find(" ", start);
  }
  return numbers;
}
void selectionSort(vector<int>& numbers){
  for (int i = 0; i < numbers.size(); i++){
    for (int j = i; j < numbers.size(); j++){
      if (numbers.at(j) < numbers.at(i)) {
        int temp = numbers.at(i);
        numbers.at(i) = numbers.at(j);
        numbers.at(j) = temp;
      }
    }
  }
}
void printVector(vector<int>& numbers){
  cout << "Sorted Numbers: ";
  for (int i = 0; i < numbers.size(); i++) {
    cout << numbers.at(i) << " ";
  }
  cout << endl;
}
