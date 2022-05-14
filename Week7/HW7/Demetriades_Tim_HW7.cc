// Tim Demetriades
// EE 553 - Engineering Programming C++
// Professor Kruger
// 10/21/2021

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include <iostream>
using namespace std;

/*
hex: base 16
0   0000
1   0001
2   0010
3   0011
4   0100
5   0101
6   0110
7   0111
8   1000
9   1001
A   1010
B   1011
C   1100
D   1101
E   1110
F   1111

row-major order (12 pixel 2D array)
    0  1  2  3
    4  5  6  7
    8  9  10 11
    
    https://github.com/nothings/stb/blob/master/stb_image_write.h
    color format is AABBGGRR (alpha = transparency, blue, green, red)
*/

class Bitmap {
private:
    uint32_t w, h;      // width and height of array
    uint32_t *pixel;    // allocate an w*h array
public:
    // Constructor
    Bitmap(uint32_t width = 1, uint32_t height = 1, uint32_t color = 0xFFFFFFFF) // default 1x1 white bitmap
        : w(width), h(height), pixel(new uint32_t[width * height])
    {
        cout << "Creating bitmap object." << endl;
        
        // Set values
        for(int y = 0; y < h; y++)
            for(int x = 0; x < w; x++)
                set(x, y, color);
    }

    // Destructor
    ~Bitmap()
    {
        cout << "Deleting bitmap object." << endl;
        delete [] pixel;
    }

    // Copy Constructor
    Bitmap(const Bitmap &orig) 
        : w(orig.w), h(orig.h), pixel(new uint32_t[orig.w * orig.h])
    {
        cout << "Copy constructor called." << endl;
        for (int i = 0; i < w * h; i++)
            pixel[i] = orig.pixel[i];
    }

    //Assignment Operator = (Old way)
    Bitmap &operator =(const Bitmap &orig) 
    {
        cout << "Assignment operator called (old way)." << endl;
        if (this != &orig)      // check if arrays match, if they do -> don't do anything
            delete [] pixel;    // free memory for pixels it originally holds
            pixel = new uint32_t[orig.w * orig.h];  //allocate some memory for array using dimensions of orig
            w = orig.w;         // set dimensions of array to match dimensions of orig
            h = orig.h;
            for (int i = 0; i < w * h; i++)
                pixel[i] = orig.pixel[i];   // set each pixel value
        return *this;           // return the object 
    }

    // New way (commented out)
    // // Assignment Operator = (New way with C++11)
    // Bitmap &operator =(Bitmap copy)
    // {
    //     cout << "Assignment operator called (new way)." << endl;
    //     swap(pixel, copy.pixel);
    //     w = copy.w;
    //     h = copy.h;
    //     return *this;
    // }

    // Set color at certain pixel value where x = column and y = row (0-indexed)
    void set(uint32_t x, uint32_t y, uint32_t color) 
    {
        pixel[y * w + x] = color;
    }

    // Another way to set pixel value (with reference)
    uint32_t& operator ()(uint32_t x, uint32_t y) 
    {
        return pixel[y * w + x];
    }

    // Another way to set pixel value (with value)
    uint32_t operator ()(uint32_t x, uint32_t y) const 
    {
        return pixel[y * w + x];
    }

    // Draw a verical line
    void horizLine(uint32_t x1, uint32_t x2, uint32_t y, uint32_t color) 
    {
        for(int x_val = x1; x_val <= x2; x_val++) {
            (*this) (x_val, y) = color;     // set the color of the current pixel
            // Or we could use set
            //set(x_val, y, color);
            }
    }

    // Draw a horizontal line
    void vertLine(uint32_t y1, uint32_t y2, uint32_t x, uint32_t color)
    {
        for(int y_val = y1; y_val <= y2; y_val++) {
            (*this) (x, y_val) = color;     // set the color of the current pixel value
        }
    }

    // Draw a rectangle
    void rect(uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint32_t color) {
        // Use the horizLine and vertLine methods to draw the 4 lines of the rectangle (outline)
        // horizLine(x, x + w, y, color);
        // horizLine(x, x + w, y + h, color);
        // vertLine(y, y + h, x, color);
        // vertLine(y, y + h, x + w, color);

        // Use horizLine to draw a rectangle (filled-in)
        for (int i = y; i < y + h; i++)
            horizLine(x, x + w, i, color);
    }

    // Write file to png using stbi header
    void write(const char filename[]) 
    {
        stbi_write_png(filename, w, h, 4, pixel, 4*w);
    }

    void print_dimensions()
    {
        cout << "Width = " << w << endl;
        cout << "Height = " << h << endl;
    }

    friend ostream &operator <<(ostream &s, const Bitmap &bm)
    {
        s << bm.pixel[0] << endl;
        return s;
    }

    Bitmap(Bitmap&& orig) : w(orig.w), h(orig.h), pixel(orig.pixel) {
        cout << "Move constructor called" << endl;
        orig.pixel = nullptr;
    }

};

Bitmap f() {
    return Bitmap(640, 480, 0xFFFFFFFF);
}


int main() {
    Bitmap bm(640, 480, 0xFFFFFFFF);    // set every pixel to be color FFFFFF (white) and non-transparent
    bm.set(0, 0, 0xFF808080);       // set pixel at 0, 0 to be this color (grey)
    bm(3,4) = 0xFF808080;           // another way to set a pixel to a color
    bm.horizLine(0, 500, 0, 0xFFFF0000); // x1= 0 x2= 500, y = 0 BLUE
    bm.vertLine(0, 100, 10, 0xFF0000FF); // y1 = 0 y2 = 100, x = 10 RED
    bm.rect(300,100, 50, 50, 0xFF00FF00);; //x=300,y=100, w=50,h=50 GREEN
    bm.write("small.png");

    Bitmap bm2(1024, 1024, 0xFF000000); // set every pixel to be color 0 (black)
    bm2.horizLine(0, 500, 0, 0xFFFF0000); // x1= 0 x2= 500, y = 0 BLUE
    bm2.vertLine(0, 100, 10, 0xFF0000FF); // y1 = 0 y2 = 100, x = 10 RED
    bm2.rect(300,100, 50, 50, 0xFF00FF00);; //left=300,top=100, w=50,h=50 GREEN
    bm2.write("big.png");

    Bitmap bm3 = bm2; // copy constructor

    bm3 = bm3; // operator =

    Bitmap bm4 = f();

    bm4.print_dimensions();

    return 0;
}