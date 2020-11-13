#include<iostream>
using namespace std;

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account{
public:
    void calculate(){
        amount += amount*interestRate;
    }
    static double rate(){
        return interestRate;
    }
    static void rate(double);
private:
    string owner;
    double amount;
    static double interestRate;
    static double initRate();
};

void Account::rate(double newRate){
    interestRate = newRate;
}

#endif