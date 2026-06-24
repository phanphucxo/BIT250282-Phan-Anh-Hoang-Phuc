#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:

    Person(string n, int a) : name(n), age(a) {
        cout << "Person constructor called" << endl;
    }

    void displayBasicInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << " years" << endl;
    }
};

class Employee : public Person {
protected:
    int employeeId;
    double salary;

public:
    Employee(string n, int a, int id, double sal)
        : Person(n, a), employeeId(id), salary(sal) {
        cout << "Employee constructor called" << endl;
    }

    void displayInfo() {
        displayBasicInfo();
        cout << "Employee ID: " << employeeId << endl;
        cout << "Salary: " << salary << " VND" << endl;
    }
};

class Manager : public Employee {
private:
    string department;
    int teamSize;

public:
    Manager(string n, int a, int id, double sal, string dept, int team)
        : Employee(n, a, id, sal), department(dept), teamSize(team) {
        cout << "Manager constructor called" << endl;
    }

    void display() {
        displayInfo();
        cout << "Department: " << department << endl;
        cout << "Team Size: " << teamSize << " people" << endl;
    }
};

int main() {
    cout << "=== Tạo đối tượng Manager ===" << endl;
    Manager mgr("Nguyen Thi Xuan", 35, 1001, 25000000, "Marketing", 8);

    cout << "\n=== Thông tin đầy đủ của Manager ===" << endl;
    mgr.display();

    cout << "\n=== Chương trình hoàn tất ===" << endl;

    return 0;
}
