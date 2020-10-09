/*
Title: CPE553-hw3a
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

        Complex add(Complex const c1) const {
            return Complex(real + c1.real, imag + c1.imag);
        }

        Complex operator-() const {
            return Complex(-real, -imag);    
        }

        friend Complex operator+(Complex const &, Complex const &);        
};

Complex operator+(Complex const &c1, Complex const &c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}


int main() {
	const Complex a(1.0, 2.0); // create a complex number with real=1.0 imag=2.0
	const Complex b(0.5, 0.0); // real = 0.5, imag = 0.0
	const Complex c = a + b;   // overload operator + using a friend function
	c.print(); // should print the following to cout: (1.5,2.0)
	// (member syntax).  Should look the same as method add where the name add
	// is replaced by operator +
	const Complex d = a.add(b); // this should be the same as the above except the name
	d.print();
	Complex e = -d; // implement unary - using a member operator. Since it has one parameter which is this should have ZERO PARAMETERS!!!
	e.print();
}