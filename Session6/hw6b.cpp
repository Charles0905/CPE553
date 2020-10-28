/*
Title: CPE553-hw6b
Author: Chenhui Yang
*/

#include <iostream>
#include <memory.h>
using namespace std;

class DynamicBitmap {
    private:
        uint32_t* p;
        uint32_t w, h, c;
        // your class goes here!

    public:
        DynamicBitmap(uint32_t width = 0, uint32_t height = 0, uint32_t color = 0xFF000000):
            w(width), h(height), c(color), p(new uint32_t[width * height]) {}
        
        ~DynamicBitmap() {
            delete[] p;
        }

        DynamicBitmap(const DynamicBitmap& orig): w(orig.w), h(orig.h), c(orig.c), p(new uint32_t[orig.w * orig.h]) {
            memcpy(p, orig.p, orig.w * orig.h * sizeof(int));
        }

        DynamicBitmap& operator =(const DynamicBitmap& orig) {
            if (this != &orig) {
                delete[] p;
                w = orig.w;
                h = orig.h;
                c = orig.c;
                p = new uint32_t[orig.w * orig.h];
                memcpy(p, orig.p, orig.w * orig.h * sizeof(int));
            }
            return *this;
        }

        uint32_t operator ()(int y, int x) const {
            return p[y * w + x];
        }

        uint32_t& operator ()(int y, int x) {
            return p[y * w + x];
        }
};

int main() {
	// FIRST PART (ADD COLORS HERE)
	constexpr uint32_t BLACK = 0xFF000000; // black opaque
	constexpr uint32_t RED = 0xFFFF0000; // red opaque
	
	
	// SECOND PART (DO NOT EDIT)
	// int xcenter = 100;
	// int ycenter = 100;
	// int xdiameter = 200;
	// int ydiameter = 100;

	DynamicBitmap b(1024, 1024, BLACK); // Potentially dynamic size (Now: 1024 x 1024 pixels)
	b(32,32) = RED;
	cout << b(32,32);
	
	// b.horizLine(0, 500, 200, RED); // Red horizontal line, from x=0 to x=500, at y = 200
	// b.vertLine(0, 399, 300, RED); // Red vertical line, from y=0 to y=399, at x = 300
	
	// b.drawRect(200,200, 100,50, BLUE); // Blue rectangle, TOP-LEFT at x=200, y=200. width=100, height=50
	// b.fillRect(201,201, 98,48, WHITE); // White rectangle, same rules as above, but filled with color
	
	// b.line(400,0, 550,300, YELLOW); // Line drawn using https://en.wikipedia.org/wiki/Bresenham's_line_algorithm
	
	// b.ellipse(xcenter, ycenter, xdiameter, ydiameter, GREEN); //Ellipse using specs from above
	
	// b.save("bitmap2.png");
	DynamicBitmap b2 = b; // test copy constructor
	b2 = b; // test operator =
	
}