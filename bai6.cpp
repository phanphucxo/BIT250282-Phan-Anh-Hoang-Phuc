#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int hoursWorked;
    double hourlyRate;

public:
    Employee(string n, int hours, double rate)
        : name(n), hoursWorked(hours), hourlyRate(rate) {}

    virtual double calculatePay() {
        return hoursWorked * hourlyRate;
    }

    void displayInfo() {
        cout << "Employee: " << name << endl;
        cout << "  Hours Worked: " << hoursWorked << endl;
        cout << "  Hourly Rate: " << hourlyRate << " VND/hour" << endl;
        cout << "  Monthly Salary: " << calculatePay() << " VND" << endl;
    }
};

class Manager : public Employee {
private:
    double bonus;

public:

    Manager(string n, int hours, double rate, double b)
        : Employee(n, hours, rate), bonus(b) {}

    double calculatePay() override {
        return Employee::calculatePay() + bonus;
    }

    void displayInfo() {
        cout << "Manager: " << name << endl;
        cout << "  Hours Worked: " << hoursWorked << endl;
        cout << "  Hourly Rate: " << hourlyRate << " VND/hour" << endl;
        cout << "  Bonus: " << bonus << " VND" << endl;
        cout << "  Total Monthly Salary: " << calculatePay() << " VND" << endl;
    }
};

class Intern : public Employee {
public:
    // Constructor
    Intern(string n, int hours, double rate)
        : Employee(n, hours, rate) {}

    double calculatePay() override {
        return Employee::calculatePay() * 0.8;
    }

    void displayInfo() {
        cout << "Intern: " << name << endl;
        cout << "  Hours Worked: " << hoursWorked << endl;
        cout << "  Hourly Rate: " << hourlyRate << " VND/hour" << endl;
        cout << "  Monthly Salary: " << calculatePay() << " VND (after 20% intern tax)" << endl;
    }
};

int main() {
    cout << "=== So sánh lương của các loại nhân viên ===" << endl << endl;

    Employee emp("Nguyen Van A", 160, 50000);
    cout << "--- Employee ---" << endl;
    emp.displayInfo();
    cout << endl;

    Manager mgr("Tran Thi B", 180, 80000, 5000000);
    cout << "--- Manager ---" << endl;
    mgr.displayInfo();
    cout << endl;

    Intern intn("Le Van C", 100, 30000);
    cout << "--- Intern ---" << endl;
    intn.displayInfo();
    cout << endl;

    cout << "=== Kết luận ===" << endl;
    cout << "Manager có lương cao nhất (bao gồm cả thưởng)" << endl;
    cout << "Employee có lương cơ bản" << endl;
    cout << "Intern có mức lương thấp nhất (80% lương cơ bản)" << endl;

    return 0;
}
