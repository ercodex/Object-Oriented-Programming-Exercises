#include <iostream>
using namespace std;

/*
Attributes (Öznitelikler) are used to define the properties of a class
or an object. They are variables declared inside a class.
*/

/*
Member data: It refers to the variables defined within a class. These
variables hold the state of the object instantiated from the class.
They are also known as 'fields' or 'instance variables'.
*/

class Person{
    private:

    /*
    They are generally hold private. They're closed to access request
    outside and this supports the encapsulation. The operations needed
    should be done by GET/SET functions which are the members of public.
    */

    string name; // Member data
    int age; // Member data
    double height; // Member data

};