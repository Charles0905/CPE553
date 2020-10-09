/*
Title: CPE553-hw4a
Author: Chenhui Yang
*/
#include <iostream>
#include <cmath>
using namespace std;

class Vec3d {
public:
    private:
        double x, y, z;
    public:
        Vec3d(double a = 0.0, double b = 0.0, double c = 0.0) {
            x = a;
            y = b;
            z = c;
        }
        friend Vec3d operator+(Vec3d const &, Vec3d const &);
        friend Vec3d operator-(Vec3d const &, Vec3d const &);
        friend Vec3d operator-(Vec3d const &);
        friend double dot(Vec3d const &, Vec3d const &);

        double dot(Vec3d const &c) const {
            return x * c.x + y * c.y + z * c.z;    
        }
        static double dot(const Vec3d &a, const Vec3d &b) {
            return a.x * b.x + a.y * b.y + a.z * b.z;
        }

        double mag() const {
            return x * x + y * y + z * z;
        }
        double magSq() const {
            return sqrt(mag());
        }
        double dist(Vec3d const &c) const {
            double diff = (x - c.x) * (x - c.x) + (y - c.y) * (y - c.y) + (z - c.z) * (z - c.z);
            return sqrt(diff);
        }

        friend ostream &operator<<(ostream &s, const Vec3d &f);
};
Vec3d operator+(Vec3d const &c1, Vec3d const &c2) {
    return Vec3d(c1.x + c2.x, c1.y + c2.y, c1.z + c2.z);
}
Vec3d operator-(Vec3d const &c1, Vec3d const &c2) {
    return Vec3d(c1.x - c2.x, c1.y - c2.y, c1.z - c2.z);
}
Vec3d operator-(Vec3d const &c1) {
    return Vec3d(-c1.x, -c1.y, -c1.z);
}
double dot(Vec3d const &c1, Vec3d const &c2) {
    return c1.x * c2.x + c1.y * c2.y + c1.z * c2.z;
}
ostream &operator<<(ostream &s, const Vec3d &f) {
    return s << "("<< f.x << ", " << f.y  << ", " << f.z << ")";
}

int main() {
	// Main() Section 1
	const Vec3d a(1.0,2.5,3.5); // double precision!
	const Vec3d b(2.0);         //(2,0,0)
	const Vec3d c(2.0,3.5);     //(2,3.5,0)
	const Vec3d d;              //(0,0,0)

	// Main() Section 2
	const Vec3d e = a + d;  // use friend
	const Vec3d f = c - b;	// use friend
	const Vec3d g = -e;     // use friend
	
	// Main() Section 3	
	double r = dot(e, f); // regular function  e.x*f.x + e.y*f.y + e.z*f.z  (friend)
	double s = e.dot(f); // method
	double t = Vec3d::dot(e,f); // static function

	// Main() Section 4	
	double x = e.mag(); // square root of sum of square
	double y = e.magSq(); // sum of square
	double z = e.dist(f); // sqrt or sum of square of diff

	// Main() Section 5	
	cout << "a: " << a << '\n';
	cout << "b: " << b << '\n';
	cout << "c: " << c << '\n';
	cout << "d: " << d << '\n';
	cout << "e: " << e << '\n';
	cout << "f: " << f << '\n';
	cout << "g: " << g << '\n';
	cout << "r: " << r << '\n';
	cout << "s: " << s << '\n';
	cout << "x: " << x << '\n';
	cout << "y: " << y << '\n';
	cout << "z: " << z << '\n';
    
}