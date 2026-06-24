#include <iostream>
using namespace std;

class Auditor; 

class Wallet {
private:
    double money;

public:
    Wallet(double m) {
        money = m;
    }

    friend void inspect(const Wallet& w);

    friend class Auditor;
};

void inspect(const Wallet& w) {
    cout << "Inspect: Wallet contains "
         << w.money << " VND" << endl;
}

class Auditor {
public:
    void audit(const Wallet& w) {
        cout << "Audit: Wallet contains "
             << w.money << " VND" << endl;
    }
};

int main() {
    Wallet myWallet(500000);

    inspect(myWallet);

    Auditor a;
    a.audit(myWallet);

    return 0;
}
