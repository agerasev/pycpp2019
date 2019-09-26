#include <iostream>

using namespace std;

template <typename T, int N>
class Vec {
private:
    T data[N];

public:
    Vec() {}

    T &operator[](int i) {
        return this->data[i];
    }
    const T &operator[](int i) const {
        return this->data[i];
    }

    friend Vec operator+(const Vec &a, const Vec &b) {
        Vec v;
        for (int i = 0; i < N; ++i) {
            v[i] = a[i] + b[i];
        }
        return v;
    }
    friend Vec operator-(const Vec &a, const Vec &b) {
        Vec v;
        for (int i = 0; i < N; ++i) {
            v[i] = a[i] - b[i];
        }
        return v;
    }
    friend Vec operator+(const Vec &a) {
        Vec v;
        for (int i = 0; i < N; ++i) {
            v[i] = -a[i];
        }
        return v;
    }

    friend Vec operator!(const Vec &a) {
        Vec v;
        for (int i = 0; i < N; ++i) {
            v[i] = !a[i];
        }
        return v;
    }

    friend ostream &operator << (ostream &out, const Vec &v) {
        out << "{";
        for (int i = 0; i < N; ++i) {
            out << v[i];
            if (i < N - 1) {
                out << ", ";
            }
        }
        out << "}";
        return out;
    }
};

int main() {
    Vec<bool, 3> v;
    v[0] = true;
    v[1] = false;
    v[2] = true;

    cout << !v << endl;

    return 0;
}
