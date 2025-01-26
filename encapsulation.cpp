#include <iostream>
using namespace std;

/*
Encapsulation means hiding attributes and methods in a class.
It blocks the direct access to attributes (Data Hiding). They're
only accessible by public methods (Get-Set Functions).
*/

class Car{
    private:

    // Attributes
    int year;
    string model;
    double batteryLife;

    public:

    // Methods

    // Constructor function
    Car(int yr, string mdl, double bLife) : year(yr), model(mdl), batteryLife(bLife) {}

    // Getter function for year (Accessor)
    int getYear() const { return year; } // Returns the year that car assembled

    // Getter function for model (Accessor)
    string getModel() const { return model; } // Returns the model of car

    // Getter function for batteryLife (Accessor)
    double getBatteryLife() const { return batteryLife; } // Returns the current battery life of car

    // Setter function to update batteryLife (Mutator)
    void setBatteryLife(double newBatteryLife) { batteryLife = newBatteryLife; } // Updates the battery life info

};

int main(){
    
    // Creating an object (instance)
    Car myTesla(2024, "Model S", 0.97);

    // Accessing the object through public methods
    cout << "Car Model: " << myTesla.getModel() << endl;
    cout << "Manifacturing Year: " << myTesla.getYear() << endl;
    cout << "Current Battery Life: " << myTesla.getBatteryLife() << endl;

    // Years passing...
    // Years passing...
    // Years passing...
    cout << "\nYears later...\n" << endl;

    // Battery life has drained. Car's software must update the indicator.
    myTesla.setBatteryLife(0.63);

    cout << "Car Model: " << myTesla.getModel() << endl;
    cout << "Manifacturing Year: " << myTesla.getYear() << endl;
    cout << "Current Battery Life: " << myTesla.getBatteryLife() << endl;

    return 0;
}

/*

Accessor functions provide external access to the private data members of a class.
They typically start with "get," which is why they are called getters. They do not 
modify data members; they only provide information externally.

Mutator functions allow external updates to the private data members of a class. 
These functions start with "set," which is why they are referred to as setters. 
They are used to change the values of data members.

*/