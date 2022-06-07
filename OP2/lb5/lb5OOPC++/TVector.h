#pragma once
#ifndef TVECTOR_H_
#define TVECTOR_H_

#include <iostream>

class TVector {
private:
    size_t len;
    double* arr; 

public:
    TVector(size_t value = 1) {
        len = value;
        arr = new double[len];
        for (size_t i = 0; i < len; i++)
        {
            arr[i] = 0;
        }
    }

    ~TVector() { delete[] arr; }

    double& operator[] (const int index) { return arr[index]; };
    size_t size() { return len; }
    virtual void resize(size_t value) { len = value; }
    bool perp(const TVector &vec);
    bool parall(const TVector& vec);
    double length();
    friend std::ostream& operator << (std::ostream& out, const TVector &v);
    friend std::istream& operator >> (std::istream& in, TVector& v);
};

class R2Vector : public TVector
{
public:
    R2Vector():TVector(2) {}

    void resize(size_t value) {}
};

class R3Vector : public TVector
{
public:
    R3Vector() :TVector(3) {}

    void resize(size_t value) {}
};
#endif

