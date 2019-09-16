#include <iostream>

using namespace std;

namespace ns0 {
    int a = 0;
}
namespace ns1 {
    int a = 1;
}

using namespace ns0;

int main() {
    cout << "ns0::a: " << a << endl;
    cout << "ns1::a: " << ns1::a << endl;
    return 0;
}
