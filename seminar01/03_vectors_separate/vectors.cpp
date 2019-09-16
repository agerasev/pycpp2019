#include <iostream>
#include <cmath>
#include <cassert>

#include "vectors.hh"


CartesianVector2::CartesianVector2(double x, double y) {
    this->x = x;
    this->y = y;
}
CartesianVector2 CartesianVector2::from_polar(PolarVector2 p) {
    return CartesianVector2(p.get_x(), p.get_y());
}

double CartesianVector2::get_x() {
    return this->x;
}
double CartesianVector2::get_y() {
    return this->y;
}

double CartesianVector2::get_r() {
    return sqrt(x*x + y*y);
}
double CartesianVector2::get_phi() {
    return atan2(y, x);
}


PolarVector2::PolarVector2(double r, double phi) {
    this->r = r;
    this->phi = phi;
}

PolarVector2 PolarVector2::from_cartesian(CartesianVector2 p) {
    return PolarVector2(p.get_r(), p.get_phi());
}

double PolarVector2::get_x() {
    return r*cos(phi);
}
double PolarVector2::get_y() {
    return r*sin(phi);
}

double PolarVector2::get_r() {
    return r;
}
double PolarVector2::get_phi() {
    return phi;
}

bool fcmp(double a, double b, double eps=1e-8) {
    return fabs(a - b) < eps;
}


int main() {
    double x = 3.0, y = 4.0;
    PolarVector2 pv = PolarVector2::from_cartesian(CartesianVector2(x, y));
    assert(fcmp(x, pv.get_x()));
    assert(fcmp(y, pv.get_y()));

    double r = 1.0, phi = M_PI/3.0;
    CartesianVector2 v = CartesianVector2::from_polar(PolarVector2(r, phi));
    assert(fcmp(r, v.get_r()));
    assert(fcmp(phi, v.get_phi()));

    std::cout << "Complete!" << std::endl;
    return 0;
}
