#include <iostream>
#include <vector>
#include <string>
#include <exception>

using namespace std;

class Exception : exception {
public:
    string msg;
    Exception(string msg) {
        this->msg = msg;
    }
};

class LowerBound : public Exception {
public:
    LowerBound() : Exception(string("index out of lower bound")) {
        
    }
};

class UpperBound : public Exception {
public:
    UpperBound() : Exception(string("index out of upper bound")) {
        
    }
};

class SafeVector {
public:
    vector<int> v;
    int &operator[](int i) {
        if (i < 0) {
            throw LowerBound();
        }
        if (i >= this->v.size()) {
            throw UpperBound();
        }
        return this->v[i];
    }
};

int main() {
    
    SafeVector sv;
    sv.v.resize(10, 0);

    try {
        cout << sv[11] << endl;
    } catch (Exception &e) {
        cout << "Exception: " << e.msg << endl;
    }

    return 0;
}
