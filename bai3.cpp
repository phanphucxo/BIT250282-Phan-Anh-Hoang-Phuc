#include <iostream>
#include <string>
using namespace std;

class Base {
public:
    int pub;
protected:
    int prot;
private:
    int priv;

public:
    Base(int p, int pr, int pr2) : pub(p), prot(pr), priv(pr2) {}
};

class DerivedPublic : public Base {
public:
    DerivedPublic(int p, int pr, int pr2) : Base(p, pr, pr2) {}

    void test() {
        pub = 1;    
        prot = 2;   
    }
};

class DerivedProtected : protected Base {
public:
    DerivedProtected(int p, int pr, int pr2) : Base(p, pr, pr2) {}

    void test() {
        pub = 1;    
        prot = 2;   
    }
};

class DerivedPrivate : private Base {
public:
    DerivedPrivate(int p, int pr, int pr2) : Base(p, pr, pr2) {}

    void test() {
        pub = 1;    
        prot = 2;   
    }
};

int main() {
    DerivedPublic dp(1, 2, 3);

    DerivedProtected dpr(1, 2, 3);

    DerivedPrivate dpriv(1, 2, 3);

    cout << "Chương trình đã biên dịch thành công! Các dòng lỗi đã được comment." << endl;
    cout << "Kết luận:" << endl;
    cout << "- public inheritance: public thành public, protected thành protected" << endl;
    cout << "- protected inheritance: public và protected đều thành protected" << endl;
    cout << "- private inheritance: public và protected đều thành private" << endl;

    return 0;
}
