/*
Title: CPE553-hw3c
Author: Chenhui Yang
*/

#include <iostream>
#include <cstring>
using namespace std;

class Body {
    private:
        char name[20];
        double mass, x, y, z, rad;
    public:
        Body(const char name[], double mass, double x, double y, double z, double rad):
            mass(mass), x(x), y(y), z(z), rad(rad)
        {
            strncpy(this->name, name, 20);
        }

        friend ostream &operator<<(ostream &s, const Body &f);
};

ostream &operator<<(ostream &s, const Body &f) {
    return s << " "<< f.name << " "<< f.mass << " " << f.x  << " " << f.y << " "<< f.z << " " << f.rad;
}

int main() {
	//         name      mass(kg) x y z  radius (m)
	Body earth("earth", 5.972e24, 0,0,0, 6.371e6);
	Body moon("moon",   7.34767309e22, 384.400e6,0,0,  1.737e6);
	cout << earth << '\n';
	cout << moon << '\n';
}