#include <iostream>
#include <string>
using namespace std;

class BankAccount {
protected:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited " << amount << " VND. New balance: " << balance << " VND" << endl;
        }
    }

    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew " << amount << " VND. Remaining balance: " << balance << " VND" << endl;
        } else {
            cout << "Withdrawal failed: Insufficient funds or invalid amount." << endl;
        }
    }

    double getBalance() {
        return balance;
    }
};

class SavingsAccount : public BankAccount {
private:
    double minimumBalance;

public:
    SavingsAccount(double initialBalance, double minBalance)
        : BankAccount(initialBalance), minimumBalance(minBalance) {}

    void withdraw(double amount) override {
        if (amount > 0) {
            double remainingBalance = balance - amount;
            if (remainingBalance >= minimumBalance) {
                balance = remainingBalance;
                cout << "Withdrew " << amount << " VND. Remaining balance: " << balance
                     << " VND (Minimum balance maintained: " << minimumBalance << " VND)" << endl;
            } else {
                cout << "Withdrawal failed: After withdrawal, balance (" << remainingBalance
                     << " VND) would be below minimum balance (" << minimumBalance << " VND)." << endl;
            }
        } else {
            cout << "Withdrawal failed: Invalid amount." << endl;
        }
    }

    void displayAccountInfo() {
        cout << "Savings Account Information:" << endl;
        cout << "  Current Balance: " << balance << " VND" << endl;
        cout << "  Minimum Balance: " << minimumBalance << " VND" << endl;
    }
};

int main() {
    SavingsAccount myAccount(1000000, 200000);

    cout << "=== Tài khoản tiết kiệm ban đầu ===" << endl;
    myAccount.displayAccountInfo();

    cout << "\n=== Gửi tiền 500000 VND ===" << endl;
    myAccount.deposit(500000);

    cout << "\n=== Thử rút 800000 VND (sẽ thành công) ===" << endl;
    myAccount.withdraw(800000);

    cout << "\n=== Thử rút 600000 VND (sẽ thất bại - dưới mức tối thiểu) ===" << endl;
    myAccount.withdraw(600000);

    cout << "\n=== Thử rút 400000 VND (sẽ thành công) ===" << endl;
    myAccount.withdraw(400000);

    cout << "\n=== Trạng thái tài khoản cuối ===" << endl;
    myAccount.displayAccountInfo();

    return 0;
}
