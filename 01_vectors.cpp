#include <iostream>
#include <cmath>


class CartesianVector2 {
private:
    double x;
    double y;

public:
    CartesianVector2(double x, double y) {
        this->x = x;
        this->y = y;
    }
    /*
    static CartesianVector2 from_polar(PolarVector2 p) {
        return CartesianVector2(p.get_x(), p.get_y());
    }
    */
    double get_x() {
        return this->x;
    }
    double get_y() {
        return this->y;
    }

    double get_r() {
        return sqrt(x*x + y*y);
    }
    double get_phi() {
        return atan2(y, x);
    }

    double length() {
        return get_r();
    }
    double angle() {
        return get_phi();
    }
};

class PolarVector2 {
private:
    double r;
    double phi;

public:
    PolarVector2(double r, double phi) {
        this->r = r;
        this->phi = phi;
    }

    static PolarVector2 from_cartesian(CartesianVector2 p) {
        return PolarVector2(p.get_r(), p.get_phi());
    }

    double get_x() {
        return r*cos(phi);
    }
    double get_y() {
        return r*sin(phi);
    }

    double get_r() {
        return r;
    }
    double get_phi() {
        return phi;
    }

    double length() {
        return get_r();
    }
    double angle() {
        return get_phi();
    }
};

int main() {
    PolarVector2 v = PolarVector2::from_cartesian(CartesianVector2(3, 4));
    std::cout << v.get_x() << " " << v.get_y() << std::endl;
    std::cout << v.length() << " " << v.angle() << std::endl;
    return 0;
}
