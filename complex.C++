#include <iostream>

class Complex {
private:
    double real, imag;
public:
    Complex(double r = 0, double i = 0): real(r), imag(i) {}

    friend Complex operator+(Complex const &, Complex const &);

    void print() {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};

Complex operator+(Complex const &c1, Complex const &c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

int main() {
    Complex c1(2, 3), c2(4, 5);
    Complex c3 = c1 + c2;
    c3.print();

    return 0;
}