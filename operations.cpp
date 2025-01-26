#include <iostream>
using namespace std;

/*
Operations are defined as actions that we can perform on a class.
They're performed with class's member functions (methods). Generally,
member functions can access private attributes. As an example, calculating, 
processing, or manipulating data are what we called 'operations'.
*/

class BankAccount {
    private:
    
    double balance;

    public:
    
    // Method: deposit() 
    void deposit(double amount){ // Operation: Adding money to balance
        balance += amount;
    }

    // Method: withdraw()
    void withdraw(double amount){ // Operation: Withdrawing money from balance
        if (balance >= amount){
            balance -= amount;
        }
    }
};