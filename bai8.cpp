#include <iostream>
#include <iomanip>
using namespace std;

class Account {
protected:
    string accountNo;
    double balance;

public:
    Account(string accNo, double initialBalance) : accountNo(accNo), balance(initialBalance) {
        cout << "Account constructor called for account: " << accountNo << endl;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited " << amount << " to account " << accountNo
                 << ". New balance: " << balance << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew " << amount << " from account " << accountNo
                 << ". New balance: " << balance << endl;
        } else {
            cout << "Withdraw failed for account " << accountNo
                 << ". Insufficient balance or invalid amount." << endl;
        }
    } 
    double getBalance() const {
        return balance;
    }

    void display() const {
        cout << "Account: " << accountNo << ", Balance: " << fixed << setprecision(2) << balance << endl;
    }
};

class SavingsAccount : public Account {
protected:
    double interestRate; 

public:
    SavingsAccount(string accNo, double initialBalance, double rate)
        : Account(accNo, initialBalance), interestRate(rate) {
        cout << "SavingsAccount constructor called with interest rate: "
             << interestRate << "%" << endl;
    }

    virtual void addInterest() {
        double interest = balance * interestRate / 100.0;
        balance += interest;
        cout << "Added interest " << interest << " to SavingsAccount " << accountNo
             << ". New balance: " << balance << endl;
    }

    double getInterestRate() const {
        return interestRate;
    }
};
class VIPSavings : public SavingsAccount {
public:
    VIPSavings(string accNo, double initialBalance, double rate)
        : SavingsAccount(accNo, initialBalance, rate) {
        cout << "VIPSavings constructor called" << endl;
    }

    void addInterest() override {
        double interest = balance * interestRate * 2.0 / 100.0;
        balance += interest;
        cout << "Added VIP interest (double rate) " << interest << " to VIPSavings " << accountNo
             << ". New balance: " << balance << endl;
    }
};

int main() {
    cout << "=== Multilevel Inheritance: Bank Account System ===" << endl << endl;

    cout << "\nCreating SavingsAccount with initial balance 10,000:" << endl;
    SavingsAccount savings("SA001", 10000.0, 3.5); 
    savings.display();

    cout << "\nCreating VIPSavings with initial balance 10,000:" << endl;
    VIPSavings vip("VIP001", 10000.0, 3.5); 
    vip.display();

    cout << "\n=== Calculating interest over 3 periods ===" << endl;

    cout << "\nSavingsAccount interest calculation (3.5% rate):" << endl;
    double savingsBalanceAfter3 = savings.getBalance();
    for (int i = 1; i <= 3; i++) {
        double prevBalance = savings.getBalance();
        savings.addInterest();
        savingsBalanceAfter3 = savings.getBalance();
    }

    cout << "\nVIPSavings interest calculation (double rate = 7%):" << endl;
    double vipBalanceAfter3 = vip.getBalance();
    for (int i = 1; i <= 3; i++) {
        double prevBalance = vip.getBalance();
        vip.addInterest();
        vipBalanceAfter3 = vip.getBalance();
    }

    cout << "\n=== Final Comparison After 3 Interest Periods ===" << endl;
    cout << "SavingsAccount final balance: " << fixed << setprecision(2) << savingsBalanceAfter3 << endl;
    cout << "VIPSavings final balance: " << fixed << setprecision(2) << vipBalanceAfter3 << endl;
    cout << "Difference: " << (vipBalanceAfter3 - savingsBalanceAfter3) << endl;

    cout << "\n=== Program completed successfully ===" << endl;
    return 0;
}
