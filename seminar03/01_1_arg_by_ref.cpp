#include <iostream>

using namespace std;

class Huge {
public:
    int data[1000];
};

void print(int i, const Huge &h) {
    cout << h.data[i] << endl;
}

int main() {
    Huge h;
    h.data[100] = 88;
    print(100, h);

    return 0;
}
