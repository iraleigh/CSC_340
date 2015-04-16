/**
  * Name: Account.cpp 
  * Author: Iain Raleigh
  * Student ID: 915133718
  * Compiler: g++
  */
#include "Account.h"
#include "Account_Exceptions.h"
Account::Account():balance(0)
{
}
Account::Account(double initialDeposit):balance( initialDeposit)
{
}
double Account::getBalance()
{
	return balance;
}
// returns new balance or -1 if error
double Account::deposit(double amount)
{
  Exception_Negative_Deposit exp_nd;
	if (amount > 0)
		balance += amount;
	else
		throw exp_nd; // code indicating error
	return balance;
}
// returns new balance or -1 if invalid amount
double Account::withdraw(double amount)
{
  Exception_Overdraw exp_o;
  Exception_Negative_Withdraw exp_nw;
	if((amount > balance) )
		throw exp_o;
  else if (amount < 0)
    throw exp_nw;
	else
		balance -= amount;
	return balance;
}
