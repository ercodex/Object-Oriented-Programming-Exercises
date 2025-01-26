/*

When to make a function "const" ?

Ask yourself:
	
	1) Does this function modify the object's state?

		If no, make the function const.
		
		Example: getRadius(), displayDetails(), isCircle().
		These functions usually retrieve information or perform computations without altering any members.

	2) Does this function need to modify the object's state?

		If yes, it cannot be const.
		
		Example: setRadius(), adjustSize(float factor).
		These functions alter member variables and thus must be non-const.

Why are your guesses commonly wrong?
	
	1) Member variables are mutable: You might forget that a function indirectly modifies the 
	object's state (e.g., caching values or incrementing counters). Such functions can't be const.

	2) Calling non-const functions: If a const member function calls another non-const member 
	function, it breaks the const promise, causing compilation errors.
	
	3) Understanding immutability: You may think of immutability as tied only to the return value 
	rather than the function's overall effect on the object.
		
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Item {
private:
    const int id;              // Const member variable (immutable once initialized)
    string name;
    mutable int accessCount;   // Mutable variable (modifiable even in const functions)

public:
    // Constructor
    Item(int itemId, const string& itemName)
        : id(itemId), name(itemName), accessCount(0) {
    }

    // Const member function: Does not modify the object
    int getId() const {
        accessCount++; // Allowed because accessCount is mutable
        return id;
    }

    // Const member function with a const return value
    const string& getName() const {
        return name;
    }

    // Non-const member function
    void setName(const string& newName) {
        name = newName;
    }

    // Const member function to print item details
    void display() const {
        cout << "ID: " << id << ", Name: " << name
            << ", Accessed: " << accessCount << " times\n";
    }
};

// A function with a const parameter
void printItemDetails(const Item& item) {
    item.display(); // Can call only const member functions
}

int main() {
    Item item(1, "Widget");

    item.display();  // OK
    cout << "Name: " << item.getName() << '\n'; // OK
    item.getId();
    item.setName("Gadget");
    item.display();  // Modified name

    // Using const object
    const Item constItem(2, "Immutable");
    constItem.display(); // OK
    constItem.getId();
    // constItem.setName("New Name"); // Error: Cannot call non-const member function on const object

    printItemDetails(constItem); // Passing a const reference

    return 0;
}