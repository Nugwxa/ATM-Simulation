//
// Created by phavo on 3/20/2023.
//

#include <string>
#ifndef ATM_SIMULATION_USER_H
#define ATM_SIMULATION_USER_H


class User {
public:
    std::string userName; // User's name
    double userBalance;   // User's balance
    short accountNumber;  // User's account number
    short transferPin;    // User's transfer PIN

    // Character to represent the user's account type
    // 'A' = good account(can operate)
    // 'B' = bad account (can transfer money but can't receive money)
    // 'N' = no user (incomplete user)
    char accountType;

    User();

    User(std::string uName, double uBalance, short accNum, char accType, short transPin);

};


#endif //ATM_SIMULATION_USER_H
