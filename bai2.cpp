#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string brand;
    int year;

public:
    Vehicle(string b, int y) : brand(b), year(y) {
        cout << "Vehicle constructor called" << endl;
    }

    ~Vehicle() {
        cout << "Vehicle destructor called" << endl;
    }
};

class Car : public Vehicle {
private:
    int numDoors;

public:
    Car(string b, int y, int doors) : Vehicle(b, y), numDoors(doors) {
        cout << "Car constructor called" << endl;
    }

    ~Car() {
        cout << "Car destructor called" << endl;
    }

    void display() {
        cout << "Car Information:" << endl;
        cout << "  Brand: " << brand << endl;
        cout << "  Year: " << year << endl;
        cout << "  Number of doors: " << numDoors << endl;
    }
};

int main() {
    cout << "Creating a Car object..." << endl;
    Car myCar("Toyota", 2023, 4);

    cout << "\nCar object created. Now destroying..." << endl;

    return 0;
}
