// This program simulates an ATM machine
// It allows the user to check their balance, withdraw money, deposit money,
// and exit the application.

#include <iostream>
#include <ctime>

// User Class Header and Implementation Files
#include "User.h"
#include "User.cpp"

// Header and Implementation File for display functions( used to display the menu)
#include "displayFunctions.h"
#include "displayFunctions.cpp"

// Header and Implementation File for transfer functions
//#include "transferFunctions.h"
#include "transferFunctions.cpp"

// Class to represent a user account
class User;

// Function that displays the main menu options to the user
void showMenu();

// Function that displays the transfer menu options to the user
void showTransferMenu(User user1, User user2, User user3);

// Function that handles money transfer
void transferTo(User receivingUser, double balance);


int main(){

    srand(time(NULL));  // Seed the random number generator with the current time

    // Generate 3 random 4-digit numbers
    int acc01 = rand() % 9000 + 1000; // range of 1000-9999
    int acc02 = rand() % 9000 + 1000;
    int acc03 = rand() % 9000 + 1000;


    // Create 3 user objects using the User class
    User user1("John Doe", 152.01, acc01, 'A', 888);
    User user2("Rick Boogs", 9773.76,acc02, 'A', 456);
    User user3("Matthew Poole", 2968.88, acc03, 'B', 111);


    //std::cout<< user3.userName;

    int option = 0;
    double activeUserbalance = 1085.62;

    // Main loop
    do{
        // Show menu to the user
        showMenu();

        // Get the user's option
        std::cout<< "Enter Option: ";
        std::cin>> option;

        // Clear the screen for better user experience
        system("cls");

        // Process user's option
        switch(option){
            case 1:
                // Display the user's balance
            {
                std::cout<<"Your available balance is $" << activeUserbalance <<std::endl;
                break;
            }

            case 2:
                // Withdraw money
            {
                double withdrawAmount;
                bool correctWithdrawal = false;

                // Check if the user is withdrawing more than they have
                while (correctWithdrawal ==false){
                    std::cout<< "Enter amount you want to withdraw: ";
                    std::cin>> withdrawAmount;

                    // Return user back to menu if they enter -1
                    if (withdrawAmount == -1){
                        system("cls");
                        break;
                    }
                    
                    if(withdrawAmount<=activeUserbalance){
                        activeUserbalance -= withdrawAmount;
                        system("cls");
                        std::cout<< "Successfully withdrew $" << withdrawAmount<<std::endl;
                        correctWithdrawal = true;

                    }else{
                        std::cout<< "You don't have up to $" << withdrawAmount<<"."<<std::endl;
                        std::cout<< "Your balance is " << activeUserbalance<<"."<<std::endl;
                        std::cout<< "Enter '-1' to return to menu"<<std::endl;
                    }
                }
                break;
            }

            case 3:
                // Deposit money
            {
                double depositAmount;
                const double MAX_DEPOSIT = 5000;
                bool correctDeposit = false;

                // Check if the deposit isn't more than the allowed amount
                while (correctDeposit ==false){
                    std::cout<< "Enter deposit amount: ";
                    std::cin>> depositAmount;

                    // Return user back to menu if they enter -1
                    if (depositAmount == -1){
                        system("cls"); // Clear the screen for better user experience
                        break;
                    }

                    if (depositAmount > MAX_DEPOSIT){
                        std::cout<< "Invalid deposit! The max amount you can deposit at a time is $" <<MAX_DEPOSIT<<"."<<std::endl;
                        std::cout<< "Enter '-1' to return to menu"<<std::endl;
                    } else{
                        activeUserbalance += depositAmount;
                        system("cls");// Clear the screen for better user experience
                        std::cout<< "Successfully deposited $" << depositAmount<<std::endl;
                        correctDeposit = true;
                    }
                }
                break;
            }
            case 4:
                // Display accounts to transfer to
            {
                int user = 0;
                system("cls");

                showTransferMenu(user1, user2, user3);
                std::cout<<"\nEnter User: ";
                std::cin>>user;

                system("cls");

                bool transferEnded = false;

                switch(user){
                    case 1:
                    {
                        //User 1
                        transferTo(user1, activeUserbalance);
                        break;
                    }
                    case 2:
                    {
                        // User 2
                        transferTo(user2, activeUserbalance);
                        break;
                    }
                    case 3:
                    {
                        // User 3
                        transferTo(user3, activeUserbalance);
                        break;
                    }
                    case 4:
                    {
                        break;
                    }
                } // End of User Switch Case
                break;
            } //End of Case 4 (Transactions)

            case 5:
                // Exit the application
            {
                std::cout<< "Exiting Application!"<<std::endl;
                break;
            }
        }

    }while(option!=5);

    // End of program
    return 0;
}
