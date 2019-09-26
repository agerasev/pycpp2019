#include <iostream>

using namespace std;

template <typename T>
class Vec {
private:
    T data[2];
public:
    Vec() {}
    Vec(T x, T y) {
        this->data[0] = x;
        this->data[1] = y;
    }

    T &operator[](int i) {
        return this->data[i];
    }
    const T &operator[](int i) const {
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

    friend Vec operator!(const Vec &a) {
        return Vec(!a[0], !a[1]);
    }

    friend ostream &operator << (ostream &out, const Vec &v) {
        return out << "{" << v[0] << ", " << v[1] << "}";
    }
};

int main() {
    const Vec<bool> v(true, false);
    cout << !v << endl;

    Vec< Vec<int> > vv(Vec<int>(1, 2), Vec<int>(4, 5));
    cout << vv << endl;

    return 0;
}
