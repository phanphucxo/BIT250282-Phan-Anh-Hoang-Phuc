#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string name;
    int age;

public:

    Animal(string n, int a) : name(n), age(a) {}

    void eat() {
        cout << "[" << name << "] is eating..." << endl;
    }
};

class Dog : public Animal {
private:
    string breed;

public:

    Dog(string n, int a, string b) : Animal(n, a), breed(b) {}

    void bark() {
        cout << name << " (" << age << " years old, " << breed << ") says: Woof! Woof!" << endl;
    }

    void display() {
        cout << "Dog Information:" << endl;
        cout << "  Name: " << name << endl;
        cout << "  Age: " << age << " years" << endl;
        cout << "  Breed: " << breed << endl;
    }
};

int main() {
    Dog myDog("Buddy", 3, "Golden Retriever");

    myDog.eat();

    myDog.bark();

    return 0;
}
