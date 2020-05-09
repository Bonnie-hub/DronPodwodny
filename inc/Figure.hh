#include<iostream>
//#include"SWektor.hh"
#include"SMacierz.hh"
#include"Dr3D_gnuplot_api.hh"
#include"Draw3D_api_interface.hh"

#ifndef FIGURE
#define FIGURE

using Vector3D = SWektor<double,3>;
using Matrix3D = SMacierz<double,3>;

class Figure
{
    protected:
    Matrix3D Rotation;
    Vector3D Center;
    std::shared_ptr<drawNS::Draw3DAPI> GnuPtr;
    double Id;

    public:
    Figure(const Matrix3D &rot, const Vector3D &center, std::shared_ptr<drawNS::Draw3DAPI> gnuptr)
    : Rotation(rot), Center(center), GnuPtr(gnuptr) , Id(0){}
    virtual ~Figure() {}
    virtual void draw() {}
    virtual void move(double length, double angle) {}
    virtual void rotate(double angle) {}
};

#endif