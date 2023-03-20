//
// Created by phavo on 3/20/2023.
//

#include "User.h"


// Default constructor that sets initial values for the class variables
User::User(){
    userName = "Null";
    userBalance = 0;
    accountNumber = 0000;
    accountType = 'N';
    transferPin = 0;

}

// Constructor that initializes the class variables with input values
User::User(std::string uName, double uBalance, short accNum, char accType, short transPin){
    userName = uName;
    userBalance = uBalance;
    accountType = accType;
    accountNumber = accNum;
    transferPin = transPin;
}

