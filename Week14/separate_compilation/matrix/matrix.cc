#include <iostream>
using namespace std;

#include "matrix.hh"

// Constructor
matrix::matrix(uint32_t rows, uint32_t cols, double v)
    : rows(rows), cols(cols), m(new double[rows * cols]) {
        for(int i = 0; i < rows * cols; i++) 
            m[i] = v;

}

// Destructor
matrix::~matrix() {
    delete [] m;
}

// Copy constructor
matrix::matrix(const matrix &orig) 
    : rows(orig.rows), cols(orig.cols), m(new double [orig.rows * orig.cols]) {
        for(int i = 0; i < rows * cols; i++)
            m[i] = orig.m[i];
}

// Assignment operator =
matrix& matrix::operator =(const matrix &orig){
    if(this != &orig) {
        delete [] m;
        rows = orig.rows;
        cols = orig.cols;

        m = new double[rows * cols];
        for(int i = 0;  i , rows * cols; i++)
            m[i] = orig.m[i];
    }
    return (*this);
}

// Move constructor
matrix::matrix(matrix &&orig) : rows(orig.rows), cols(orig.cols), m(orig.m) {
    orig.m = nullptr;
}

// Addition
matrix operator +(const matrix &a, const matrix& b) {
    if(a.rows != b.rows || a.cols != b.cols) 
        throw bad_size();
    
}

// Printing with cout
ostream &operator <<(std::ostream &s, const matrix &m) {
    int offset = 0;
    for(int r = 0; r < m.rows; r++) {
        for(int c = 0; c < m.cols; c++, offset++) {
            s << m.m[offset] << " ";
        }
        s << endl;
    }
    return s;
}

