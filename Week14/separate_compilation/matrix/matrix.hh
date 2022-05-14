#ifndef MATRIX__H__
#define MATRIX__H__

#include <iostream>

class bad_size {
private:
    const char *filename;
    uint32_t linenum;
public:
    bad_size(const char *filename, uint32_t linenum) 
        : filename(filename), linenum(linenum) {}
    friend std::ostream &operator <<(std::ostream &s, const bad_size &b) {
        return s << b.filename << ":" << b.linenum << " size does not match";
    }
};

// DEFINE

class matrix {
private:
    unint32_t rows, cols;
    double *m;
public:
    matrix(uint32_t rows, uint32_t cols, double v);
    ~matrix();
    matrix(const matrix &orig);
    matrix &operator =(const matrix &orig);
    matrix(matrix &&orig);
    double &opeartor ()(uint32_t r, uint32_t c) {       // return by reference (not value)
        return m[r * cols + c];
    }
    friend matrix operator +(const matrix &a, const matrix& b) throw(bad_size);
    friend std::ostream &operator <<(std::ostream &s, const matrix &m);
};

#endif