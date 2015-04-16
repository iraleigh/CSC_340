/**
  * Name: main.cpp
  * Author: Iain Raleigh
  * Student ID: 915133718
  * Compiler: g++
	* Purpose: To test the functions in Exception_ID_Not_Found.cpp
  */
#include <iostream>
#include "Exception_ID_Not_Found.h"

int main() // Sample code to test the getProductID function
{
	int productIds[]= {4, 5, 8, 10, 13};
	string products[] = { "computer", "flash drive", "mouse", "printer", "camera" };
	try {
		cout << getProductID(productIds, products, 5, "mouse") << endl;
		cout << getProductID(productIds, products, 5, "camera") << endl;
		cout << getProductID(productIds, products, 5, "laptop") << endl;
	} catch (exception& e) {
		cerr << "Error:" << e.what() <<endl;
	}
	return 0;
}
