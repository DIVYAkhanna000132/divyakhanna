#include <iostream>
#include <cmath>

class Shape {
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() {
        return 3.14 * radius * radius;
    }
    double perimeter() {
        return 2 * 3.14 * radius;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() {
        return length * width;
    }
    double perimeter() {
        return 2 * (length + width);
    }
};

class Triangle : public Shape {
private:
    double side1;
    double side2;
    double side3;
public:
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}
    double area() {
        double s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
    double perimeter() {
        return side1 + side2 + side3;
    }
};

int main() {
    Shape* shapes[] = {new Circle(5), new Rectangle(4, 5), new Triangle(3, 4, 5)};

    for (Shape* shape : shapes) {
        std::cout << "Area: " << shape->area() << ", Perimeter: " << shape->perimeter() << std::endl;
    }

    return 0;
}