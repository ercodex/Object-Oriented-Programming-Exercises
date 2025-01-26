#include <iostream>
#include <iomanip>
#include "CommissionEmployee.h"
using namespace std;

int main(){
    // Initalize Muammer Cil
    CommissionEmployee muammer ("Muammer", "Cil", "6086-8433-884", 10000, .06);
    cout << fixed << setprecision(2); // Print 2 numbers after comma

    // get commission employee data
    cout << "Employee information obtained by get functions: \n"
    << "\nFirst name is " << muammer.getFirstName()
    << "\nLast name is " << muammer.getLastName()
    << "\nSocial security number is "
    << muammer.getSSN()
    << "\nGross sales is " << muammer.getGrossSales()
    << "\nCommission rate is " << muammer.getCommissionRate()<<endl;

    muammer.setGrossSales( 8000 ); // set gross sales
    muammer.setCommissionRate( .1 ); // set commission rate

    cout<<"\nUpdated employee information output by print function: \n" <<endl;
    muammer.print(); // display the new employee information
    
    return 0;
}