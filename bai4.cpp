#include <iostream>
#include <string>
using namespace std;

const double PI = 3.14159265358979323846;

class Shape {
protected:
    string color;

public:
    Shape(string c) : color(c) {}

    void describe() {
        cout << "Shape: [" << color << "]" << endl;
    }

    virtual double area() {
        return 0.0;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(string c, double r) : Shape(c), radius(r) {}

    double area() override {
        return PI * radius * radius;
    }

    void describe() {
        Shape::describe(); 
        cout << "Circle with radius: " << radius << " - Area: " << area() << endl;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(string c, double w, double h) : Shape(c), width(w), height(h) {}

    double area() override {
        return width * height;
    }

    void describe() {
        Shape::describe();  
        cout << "Rectangle with width: " << width << ", height: " << height
             << " - Area: " << area() << endl;
    }
};

int main() {
    cout << "=== Thong tin hinh hoc ===" << endl << endl;

    Circle circle("Red", 5.0);
    cout << "--- Circle ---" << endl;
    circle.describe();
    cout << endl;

    Rectangle rectangle("Blue", 4.0, 6.0);
    cout << "--- Rectangle ---" << endl;
    rectangle.describe();
    cout << endl;

    Shape shape("Green");
    cout << "--- Base Shape ---" << endl;
    shape.describe();
    cout << "Area: " << shape.area() << endl;

    return 0;
}
