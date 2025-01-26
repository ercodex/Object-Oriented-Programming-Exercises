#include <iostream>
using namespace std;

class parkedCar{
    private:
    
    string model;
    string plate;
    int hours;
    static int emptyLots;

    public:

    static int getEmptyLots(){ return emptyLots; } // Returns empty parking lots

    // Constructor also calculates empty parking lots
    // Empty lots gets lowered when there is a
    // new car, which is a new object from this class.

    // Constructor:
    parkedCar(string mdl, string plt, int h) : model(mdl), plate(plt), hours(h) {
        --emptyLots;
    }

    // G-S for model
    string getModel() const {return model;}
    void setModel(string mdl) {this->model = mdl;}

    // G-S for plate
    string getPlate() const {return plate;}
    void setPlate(string plt) {this->plate = plt;}

    // G-S for hours
    int getHours() const {return hours;}
    void setHours(int h) {this->hours = h;}

    // Ticket price calculator
    int ticket() const {
        return ((hours*50) + 20);
    }
};

// Our parking lot has the capacity of 3 cars. We're kinda small :D
int parkedCar::emptyLots = 3;

int main(){        
    
    cout << "Empty lots: " << parkedCar::getEmptyLots() << endl << endl;

    
    parkedCar Car1("Volkswagen Transporter", "67_ACE_885", 4);
    
    cout << "Model: " << Car1.getModel() << endl;
    cout << "Plate: " << Car1.getPlate() << endl;
    cout << "Hours: " << Car1.getHours() << endl;
    cout << "Total price: " << Car1.ticket() << endl;
    
    cout << "Empty lots: " << parkedCar::getEmptyLots() << endl << endl;
    
    parkedCar Car2("Renault Broadway", "67_EEH_168", 7);
    cout << "Model: " << Car2.getModel() << endl;
    cout << "Plate: " << Car2.getPlate() << endl;
    cout << "Hours: " << Car2.getHours() << endl;
    cout << "Total price: " << Car2.ticket() << endl;
    
    cout << "Empty lots: " << parkedCar::getEmptyLots() << endl << endl;

    parkedCar Car3("Lamborghini Aventador", "67_ABC_2121", 1);    
    cout << "Model: " << Car3.getModel() << endl;
    cout << "Plate: " << Car3.getPlate() << endl;
    cout << "Hours: " << Car3.getHours() << endl;
    cout << "Total price: " << Car3.ticket() << endl;
    
    cout << "Empty lots: " << parkedCar::getEmptyLots() << endl << endl;
    
    cout << "All lots are full!!!" << endl;

    return 0;
}