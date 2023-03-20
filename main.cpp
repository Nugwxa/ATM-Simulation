// This program simulates an ATM machine
// It allows the user to check their balance, withdraw money, deposit money,
// and exit the application.

#include <iostream>
#include <iomanip>
#include <ctime>

// User Class Header and Implementation Files
#include "User.h"
#include "User.cpp"

// Header and Implementation File for display functions( used to display the menu)
#include "displayFunctions.h"
#include "displayFunctions.cpp"

// Class to represent a user account
class User;

// Function that displays the main menu options to the user
void showMenu();

// Function that displays the transfer menu options to the user
void showTransferMenu(User user1, User user2, User user3);


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
    double balance = 1085.62;

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
                std::cout<<"Your available balance is $" << balance <<std::endl;
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

                    if(withdrawAmount<=balance){
                        balance -= withdrawAmount;
                        system("cls");
                        std::cout<< "Successfully withdrew $" << withdrawAmount<<std::endl;
                        correctWithdrawal = true;

                    }else{
                        std::cout<< "You don't have up to $" << withdrawAmount<<"."<<std::endl;
                        std::cout<< "Your balance is " << balance<<"."<<std::endl;
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
                        balance += depositAmount;
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
                        while(transferEnded == false){
                            double transferAmount;
                            const int uPin = 700;
                            int userPass; // user's transfer password (User Input)
                            int transPass; // receipient's receiving password (User Input)

                            // Check if account can receive transfers
                            if(user1.accountType == 'A'){
                                std::cout<< "Transfer to "<< user1.userName<<std::endl;
                                std::cout<< "Enter amount you want to transfer: ";
                                std::cin>> transferAmount;

                                // Check if balance is sufficient for transfer
                                if(transferAmount > balance){
                                    std::cout<< "You don't have up to " << transferAmount<<std::endl;
                                    transferEnded = true;
                                    break;
                                }

                                std::cout<< "Enter your transfer pin";
                                std::cin>> userPass;

                                std::cout<< "Enter "<< user1.userName <<"'s receiving pin";
                                std::cin>> transPass;

                                // Check if passwords are correct;
                                if( (userPass == uPin) && (transPass == user1.transferPin))
                                {
                                    std::cout<<"Successfully transfered $"<< transferAmount<<" to "<< user1.userName;
                                    balance -= transferAmount;
                                    user1.userBalance += transferAmount;
                                    transferEnded =true; // Exit the loop;
                                }

                            } else {
                                std::cout<< user1.userName <<" has a  type "<< user1.accountType<< " account so they cant receive money."<<std::endl;
                                transferEnded = true; // Exit the loop;
                                break;
                            }
                        }
                        break;
                    }
                    case 2:
                    {
                        // User 2
                        while(transferEnded == false){
                            double transferAmount;
                            const int uPin = 700;
                            int userPass; // user's transfer password (User Input)
                            int transPass; // receipient's receiving password (User Input)

                            if(user2.accountType == 'A'){
                                std::cout<< "Transfer to "<< user2.userName<<std::endl;
                                std::cout<< "Enter amount you want to transfer: ";
                                std::cin>> transferAmount;

                                // Check if balance is sufficient for transfer
                                if(transferAmount > balance){
                                    std::cout<< "You don't have up to " << transferAmount<<std::endl;
                                    transferEnded = true;
                                    break;
                                }

                                std::cout<< "Enter your transfer pin: ";
                                std::cin>> userPass;

                                std::cout<< "Enter "<< user2.userName <<"'s receiving pin: ";
                                std::cin>> transPass;

                                // Check if the passwords are correct
                                if( (userPass == uPin) && (transPass == user2.transferPin))
                                {
                                    std::cout<<"Successfully transfered $"<< transferAmount<<" to "<< user2.userName<<std::endl;
                                    balance -= transferAmount;
                                    user2.userBalance += transferAmount;
                                    transferEnded =true; // Exit the loop
                                }

                            } else {
                                std::cout<< user2.userName <<" has a  type "<< user2.accountType<< " account so they cant receive money."<<std::endl;
                                break; //Exit the Loop
                            }
                        }
                        break;
                    }
                    case 3:
                    {
                        // User 3
                        while(transferEnded == false){
                            double transferAmount;
                            const int uPin = 700;
                            int userPass; // user's transfer password (User Input)
                            int transPass; // receipient's receiving password (User Input)

                            // Check if account can receive transfers
                            if(user3.accountType == 'A'){
                                std::cout<< "Transfer to "<< user3.userName<<std::endl;
                                std::cout<< "Enter amount you want to transfer: ";
                                std::cin>> transferAmount;

                                // Check if balance is sufficient for transfer
                                if(transferAmount > balance){
                                    std::cout<< "You don't have up to " << transferAmount<<std::endl;
                                    transferEnded = true;
                                    break;
                                }

                                std::cout<< "Enter your transfer pin: ";
                                std::cin>> userPass;

                                std::cout<< "Enter "<< user3.userName <<"'s receiving pin: ";
                                std::cin>> transPass;

                                // Check if passwords are correct;
                                if( (userPass == uPin) && (transPass == user3.transferPin))
                                {
                                    std::cout<<"Successfully transfered $"<< transferAmount<<" to "<< user3.userName<<std::endl;
                                    balance -= transferAmount;
                                    user3.userBalance += transferAmount;
                                    transferEnded =true; // Exit the loop
                                }

                            } else {
                                std::cout<< user3.userName <<" has a  type "<< user3.accountType<< " account so they cant receive money."<<std::endl;
                                break;
                            }
                        }
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

