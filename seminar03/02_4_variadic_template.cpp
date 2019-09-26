/// -std=c++11 should be enabled

#include <iostream>

using namespace std;

template <typename T, int N>
class Vec {
private:
    T data[N];

    template <int I, typename ... X>
    void unwind(T a, X ... args) {
        static_assert(I < N - 1, "too many arguments");
        this->data[I] = a;
        this->unwind<I + 1>(args...);
    }

    template <int I>
    void unwind(T a) {
        static_assert(I == N - 1, "arguments count mismatch");
        this->data[I] = a;
    }

public:
    Vec() {}

    template <typename ... X>
    Vec(X ... args) {
        this->unwind<0>(args...);
    }

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
    Vec<bool, 3> v(true, false, true);
    cout << !v << endl;

    Vec<Vec<int, 3>, 2> vv(Vec<int, 3>(1, 2, 3), Vec<int, 3>(4, 5, 6));
    cout << vv << endl;

    return 0;
}
