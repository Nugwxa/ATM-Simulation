// This program simulates an ATM machine
// It allows the user to check their balance, withdraw money, deposit money,
// and exit the application.

#include <iostream>
#include <iomanip>
#include <ctime>

// Class to represent a user account
class User{
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

    // Default constructor that sets initial values for the class variables
    User(){
        userName = "Null";
        userBalance = 0;
        accountNumber = 0000;
        accountType = 'N';
        transferPin = 0;

    }

    // Constructor that initializes the class variables with input values
    User(std::string uName, double uBalance, short accNum, char accType, short transPin){
    userName = uName;
    userBalance = uBalance;
    accountType = accType;
    accountNumber = accNum;
    transferPin = transPin;
    }

};

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
