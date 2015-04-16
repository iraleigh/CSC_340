/**
  * Name: Exception_ID_Not_Found.cpp 
  * Author: Iain Raleigh
  * Student ID: 915133718
  * Compiler: g++
  */
#include "Exception_ID_Not_Found.h"
int getProductID(int ids[], string names[], int numProducts, string target){
  Exception_ID_Not_Found exp_nf;

  for (int i=0; i < numProducts; i++)
	{
		if (names[i] == target)
			return ids[i];
	}
	throw exp_nf; // not found
}
