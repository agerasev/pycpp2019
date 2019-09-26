#include <iostream>

using namespace std;


class Vec {
private:
    double data[2];
public:
    Vec() {
        this->data[0] = 0.0;
        this->data[1] = 0.0;
    }
    Vec(double x, double y) {
        this->data[0] = x;
        this->data[1] = y;
    }

    double &operator[](int i) {
        return this->data[i];
    }
    const double &operator[](int i) const {
        return this->data[i];
    }

    friend Vec operator+(const Vec &a, const Vec &b) {
        return Vec(a[0] + b[0], a[1] + b[1]);
    }
    friend Vec operator-(const Vec &a, const Vec &b) {
        return Vec(a[0] - b[0], a[1] - b[1]);
    }
    friend Vec operator-(const Vec &a) {
        return Vec(-a[0], -a[1]);
    }

    friend ostream &operator << (ostream &out, const Vec &v) {
        return out << "{" << v[0] << ", " << v[1] << "}";
    }
};

int main() {
    const Vec v(2.0, 3.0);

    cout << -v << endl;

    return 0;
}
