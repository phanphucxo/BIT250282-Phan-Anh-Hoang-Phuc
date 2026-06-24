#include <iostream>
#include <string>

class Security final {
private:
    std::string encryptionKey;

public:
    Security(std::string key) : encryptionKey(key) {}

    void encrypt(std::string data) {
        std::cout << "Encrypting data with key: " << encryptionKey << std::endl;
    }
};

class Base {
public:
    virtual void process() final {
        std::cout << "Base process execution." << std::endl;
    }
};

int main() {
    Security sec("SecretKey123");
    sec.encrypt("Hello World");

    Base b;
    b.process();

    return 0;
}
