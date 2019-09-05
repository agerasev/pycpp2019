#include <iostream>

namespace ns0 {
    int a = 0;
}

namespace ns1 {
    int a = 1;
}

using namespace ns0;
using namespace std;

int main() {
    //std::cout << "Hello, World!" << std::endl;
    cout << a << endl;
    cout << ns1::a << endl;
    return 0;
}
