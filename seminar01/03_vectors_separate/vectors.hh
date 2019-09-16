#pragma once

class CartesianVector2;
class PolarVector2;


class CartesianVector2 {
private:
    double x;
    double y;

public:
    CartesianVector2(double x, double y);
    static CartesianVector2 from_polar(PolarVector2 p);
    
    double get_x();
    double get_y();

    double get_r();
    double get_phi();
};

class PolarVector2 {
private:
    double r;
    double phi;

public:
    PolarVector2(double r, double phi);
    static PolarVector2 from_cartesian(CartesianVector2 p);

    double get_x();
    double get_y();

    double get_r();
    double get_phi();
};
