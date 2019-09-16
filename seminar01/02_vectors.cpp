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
};

int main() {
    CartesianVector2 cv = CartesianVector2(3, 4);
    std::cout << cv.get_x() << " " << cv.get_y() << std::endl;
    std::cout << cv.get_r() << " " << cv.get_phi() << std::endl;
    
    PolarVector2 pv = PolarVector2(1.0, M_PI/3.0);
    std::cout << pv.get_x() << " " << pv.get_y() << std::endl;
    std::cout << pv.get_r() << " " << pv.get_phi() << std::endl;

    return 0;
}
