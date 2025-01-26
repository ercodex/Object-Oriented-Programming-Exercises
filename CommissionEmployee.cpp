#include <iostream>
#include "CommissionEmployee.h"
using namespace std;

// Constructor
CommissionEmployee::CommissionEmployee(const string& first, const string& last, const string& ssn, double sales, double rate)
    : firstName(first), lastName(last), SSN(ssn), grossSales(sales), commissionRate(rate) {}

// Getter / Setters
void CommissionEmployee::setFirstName(const string& firstName){
    this->firstName = firstName;
}
string CommissionEmployee::getFirstName() const {
    return firstName;
}
void CommissionEmployee::setLastName(const string& lastName){
    this->lastName = lastName;
}
string CommissionEmployee::getLastName() const {
    return lastName;
}
void CommissionEmployee::setSSN(const string& SSN){
    this->SSN = SSN;
}
string CommissionEmployee::getSSN() const {
    return SSN;
}
void CommissionEmployee::setGrossSales(double sales){
    grossSales = ( sales < 0.0 ) ? 0.0 : sales;
}
double CommissionEmployee::getGrossSales() const {
    return grossSales;
}
void CommissionEmployee::setCommissionRate(double rate){
    commissionRate = ( rate > 0.0 && rate < 1.0 ) ? rate : 0.0;
}
double CommissionEmployee::getCommissionRate() const {
    return commissionRate;
}

// Other functions
double CommissionEmployee::earnings() const {
    return commissionRate * grossSales;
}
void CommissionEmployee::print() const {
    cout << "commission employee: " << firstName << ' ' << lastName
         << "\nsocial security number: " << SSN
         << "\ngross sales: " << grossSales
         << "\ncommission rate: " << commissionRate;
}