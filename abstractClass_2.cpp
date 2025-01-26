#include <iostream>
using namespace std;

// Abstract class "Device"
class Device {
protected:
    float price;       // Price of the device
    bool isOpen;       // Whether the device is open
public:
    // Constructor initializes the price and whether it's open
    Device(float price, bool isOpen) : price(price), isOpen(isOpen) {}

    // Pure virtual functions to enforce derived class behavior
    virtual void openDevice() = 0;  // Abstract method to open the device
    virtual void closeDevice() = 0; // Abstract method to close the device
    virtual void cleanDevice() const = 0; // Abstract method to clean the device

    // Virtual destructor to ensure proper cleanup in derived classes
    // Destructors SHOULD be virtual.
    virtual ~Device() = default;

    // Common method for all devices: returns whether the device is open
    bool isDeviceOpen() const {
        return isOpen;
    }
};

// Concrete class "Camera", derived from "Device"
class Camera : public Device {
private:
    int age;           // Age of the camera in years
    int cameraRoll;    // Number of photos taken
public:
    // Constructor initializes both base and derived class attributes
    Camera(float price, bool isOpen, int age, int cameraRoll) 
        : Device(price, isOpen), age(age), cameraRoll(cameraRoll) {}

    // Override method to open the camera
    void openDevice() override {
        if (!isOpen) {
            cout << "Opening the camera..." << endl;
            isOpen = true;
        } else {
            cout << "Camera is already open!" << endl;
        }
    }

    // Override method to close the camera
    void closeDevice() override {
        if (isOpen) {
            cout << "Closing the camera..." << endl;
            isOpen = false;
        } else {
            cout << "Camera is already closed!" << endl;
        }
    }

    // Override method to clean the camera
    void cleanDevice() const override {
        cout << "Cleaning the camera lens and body..." << endl;
    }

    // Function to simulate taking a photo
    void record() {
        if (isOpen) {
            cout << "Taking a photo..." << endl;
            cameraRoll++;
        } else {
            cout << "Cannot take a photo. The camera is closed!" << endl;
        }
    }

    // Get the total number of photos taken
    int getPhotoCount() const {
        return cameraRoll;
    }

    // Print camera details (for debugging or logging)
    void printDetails() const {
        cout << "Camera Details: \n";
        cout << "- Price: $" << price << "\n";
        cout << "- Age: " << age << " years\n";
        cout << "- Number of Photos: " << cameraRoll << "\n";
        cout << "- Open: " << (isOpen ? "Yes" : "No") << "\n";
    }
};

int main() {
    // Create a Camera object
    Camera D90(1000.0f, false, 5, 0);

    // Display camera details
    D90.printDetails();

    // Check if the camera is open
    cout << "Is the camera open? " << (D90.isDeviceOpen() ? "Yes" : "No") << endl;

    // Open the camera and take photos
    D90.openDevice();
    D90.record();
    D90.record();
    D90.record();

    // Display the number of photos taken
    cout << "Number of photos: " << D90.getPhotoCount() << endl;

    // Clean and close the camera
    D90.cleanDevice();
    D90.closeDevice();

    // Final state of the camera
    D90.printDetails();

    // It is going to be a problem when user wants to create an object from Base Class.
    // Device deneme(1500, 0);

    // This type of usage with pure virtual functions (Abstract Base Class) is a way of
    // forcing the programmer to write code for a specific purpose. Abstract Base Class
    // creates a common interface for all derived classes from it.

    // Also know that, a constructor can't be made "virtual". But it is recommended to
    // make destructors "virtual". But you have to give the definition of destructor. 
    return 0;
}
