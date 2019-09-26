#include <iostream>

using namespace std;

void print(int n) {
    cout << "int: " << n << endl;
}

void print(double n) {
    cout << "double: " << n << endl;
}

int main() {
    print(100);
    print(100.0);

    return 0;
}
