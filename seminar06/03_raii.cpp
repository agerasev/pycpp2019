#include <iostream>
#include <string>
#include <exception>

using namespace std;

// RAII
class HexGuard {
public:
    HexGuard() {
        cout << hex;
    }
    ~HexGuard() {
        cout << dec;
    }
};

void print_hex(int x) {
    HexGuard hg;
    if (x < 0) {
        throw 0;
    } else {
        cout << "0x" << x << endl;
    }
}

int main() {
    
    try {
        print_hex(-255);
    } catch (...) {
        cout << "exception" << endl;
    }

    cout << 15 << endl;

    return 0;
}