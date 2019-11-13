#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int sum(int a, int b) {
    return a + b;
}

int diff(int a, int b) {
    return a - b;
}

class Sum {
public:
    int m;
    Sum(int m) {
        this->m = m;
    }
    int operator()(int a, int b) {
        return this->m*(a + b);
    }
};

class Diff {
public:
    int m;
    Diff(int m) {
        this->m = m;
    }
    int operator()(int a, int b) {
        return this->m*(a - b);
    }
};

template <typename S, typename D>
vector<D> map(const vector<S> &v, function<D(S)> f) {
    vector<D> ov;
    ov.resize(v.size());
    for (int i = 0; i < v.size(); ++i) {
        ov[i] = f(v[i]);
    }
    return ov;
}

int main() {
    // Lambda-function captiring its environment.
    int m = 2, n = 10;
    function<int(int, int)> f = [&](int a, int b) -> int {
        return m*(a + b) + n;
    };
    m = 3;
    n = 5;

    cout << f(1, 2) << endl;

    // Mapping one vector to another with lambda-function
    vector<int> v;
    for (int i = 0; i < 8; ++i) {
        v.push_back(i);
        cout << i << " ";
    }
    cout << endl;

    vector<double> ov = map<int, double>(v, [](int x) -> double {
        return 0.5*x;
    });

    for (int i = 0; i < v.size(); ++i) {
        cout << ov[i] << " ";
    }
    cout << endl;

    return 0;
}