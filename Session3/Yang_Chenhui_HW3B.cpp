/*
Title: CPE553-hw3b
Author: Chenhui Yang
*/

#include <iostream>
using namespace std;

class Complex {
    private:
        double real, imag;
    public:
        Complex(double r = 0, double i = 0) {
            real = r;
            imag = i;
        }

        void print() const {
            cout << "(" << real << ", " << imag << ")" << endl;
        }

        Complex operator+(Complex const &c1) const {
            return Complex(c1.real + real, c1.imag + imag);    
        }

        friend Complex operator-(Complex const &); 
        friend Complex operator*(Complex const &, Complex const &);
        friend ostream &operator<<(ostream &s, const Complex &f);
};

Complex operator-(Complex const &c1) {
    return Complex(-c1.real, -c1.imag);
}

Complex operator*(Complex const &c1, Complex const &c2) {
    return Complex(c1.real * c2.real - c1.imag * c2.imag, c1.real * c2.imag + c2.real * c1.imag);
}

ostream &operator<<(ostream &s, const Complex &f) {
    return s << "(" << f.real << ", " << f.imag << ")";
}

int main() {
	const Complex a(1.0, 2.0); // create a complex number with real=1.0 imag=2.0
	const Complex b(0.5, 0.0); // real = 0.5, imag = 0.0
	const Complex c = a + b;   // overload operator + using member
	Complex d = -c; // use friend
	const Complex e = a * b;   // complex multiplication
	cout << c << '\t' << d << '\t' << e << '\n';
}