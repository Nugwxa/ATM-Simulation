#include "transferFunctions.h"

// Function that handles money transfer
void transferTo(User receivingUser, double balance){
    bool transferEnded = false;
    while(!transferEnded){
        double transferAmount;
        const int uPin = 700;
        int userPass; // user's transfer password (User Input)
        int transPass; // receipient's receiving password (User Input)

        // Check if account can receive transfers
        if(receivingUser.accountType == 'A'){
            std::cout<< "Transfer to "<< receivingUser.userName<<std::endl;
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

            std::cout<< "Enter "<< receivingUser.userName <<"'s receiving pin: ";
            std::cin>> transPass;

            // Check if passwords are correct;
            if( (userPass == uPin) && (transPass == receivingUser.transferPin))
            {
                std::cout<<"Successfully transfered $"<< transferAmount<<" to "<< receivingUser.userName<<std::endl;
                balance -= transferAmount;
                receivingUser.userBalance += transferAmount;
                transferEnded =true; // Exit the loop
            }

        } else {
            std::cout<< receivingUser.userName <<" has a  type "<< receivingUser.accountType<< " account so they cant receive money."<<std::endl;
            break;
        }
    }


}
