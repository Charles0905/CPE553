/*
Title: CPE553-hw4e
Author: Chenhui Yang
*/

#include <cmath>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
using namespace std;

class Vec3d {
    private:
        double x, y;
    public:
        Vec3d(double radius = 0.0) {
            constexpr double pi = 3.14159265358979;
            default_random_engine generator(0);
            uniform_real_distribution<double> randAngle(0.0,2*pi);
            double r = randAngle(generator);
            x = radius * sin(r);
            y = radius * cos(r);
        }

        friend ostream &operator<<(ostream &s, const Vec3d &f) {
            return s << "("<< f.x << ", " << f.y  << ")";
        }
};

class Body {
    private:
        string name, orbit;
        double mass, diam, peri, aphe, radius;
        Vec3d position;

    public:
        friend istream &operator>>(istream  &input, Body &f) { 
            input >> f.name >> f.orbit >> f.mass >> f.diam >> f.peri >> f.aphe;
            f.radius = (f.peri + f.aphe) / 2;
            f.position = Vec3d(f.radius);
            return input;            
        }
        friend ostream &operator<<(ostream &s, const Body &f) {
            return s << f.name << " " << f.mass  << " " << f.radius << " " << f.position;
        }
};

int main() {
    ifstream f("solarsystem.dat");
    char buf[1024];
    Body body;

    // Skip the first line
    f.getline(buf, sizeof(buf));

    while(!f.eof()) {
        f.getline(buf, sizeof(buf));
        istringstream line(buf);
        line >> body;
        cout << body << '\n';
    }
}