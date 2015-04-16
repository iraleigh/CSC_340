/**
  * Name: Account.h
  * Author: Iain Raleigh
  * Student ID: 915133718
  * Compiler: g++
  */
#ifndef ACCOUNT_H
#define ACCOUNT_H
class Account{
  private:
       double balance;
  public:
  Account();
	Account(double initialDeposit);
	double getBalance();
	// returns new balance or throws error
	double deposit(double amount);
	// returns new balance or throws error if invalid amount
	double withdraw(double amount);
};


#endif
