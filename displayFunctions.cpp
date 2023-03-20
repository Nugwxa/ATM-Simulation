#include "displayFunctions.h"
// User Class
#include "User.h"

// Function to display the main menu
void showMenu(){

    // Header
    std::cout<<std::setfill('*')<<std::setw(35)<<" ";
    std::cout<<std::setfill(' ')<< " "<<std::endl;
    std::cout<<std::setw(10)<<std::left<< "OJ ATM" << std::setw(24) << std::right<< "Choose an option" << std::endl;
    std::cout<<std::setfill('*')<<std::setw(35)<<" "<<std::endl;
    std::cout<<std::setfill(' ')<< " "<<std::endl;

    // Options
    std::cout<< "1. Check Balance"<<std::endl;
    std::cout<< "2. Withdraw Money"<<std::endl;
    std::cout<< "3. Deposit Money"<<std::endl;
    std::cout<< "4. Transfer"<<std::endl;
    std::cout<< "5. Exit"<<std::endl;

}

// Function to display the menu
void showTransferMenu(User user1, User user2, User user3){

    // Formatting the output
    std::cout<<std::setw(20)<< std::left<<"Account Name"<<" | "<<std::setw(4)<< "No."<<" | "<<std::setw(9)<< "Bal."<<" | "<< "Acc type" <<std::endl;
    std::cout<<std::setfill('-')<<std::setw(47)<<" \n"; // separating line
    std::cout<<std::setfill(' ')<< " \n"<<std::endl; // Empty line


    // Displaying user accounts and information
    std::cout<< "1. "<<std::setw(17)<< std::left<<user1.userName<<" | "<<user1.accountNumber<<std::setw(5)<<" | "<<std::setw(7)<< user1.userBalance<<" | "<< user1.accountType <<std::endl;
    std::cout<< "2. "<<std::setw(17)<< std::left<<user2.userName<<" | "<<user2.accountNumber<<std::setw(5)<<" | "<< user2.userBalance<<" | "<< user2.accountType <<std::endl;
    std::cout<< "3. "<<std::setw(17)<< std::left<<user3.userName<<" | "<<user3.accountNumber<<std::setw(5)<<" | "<< user3.userBalance<<" | "<< user3.accountType <<std::endl;
    std::cout<< "4. Exit"<<std::endl;

}
