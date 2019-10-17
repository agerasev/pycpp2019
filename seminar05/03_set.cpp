#include <set>
#include <string>

#include <iostream>

using namespace std;

int main() {
    set<string> m;

    // instert ellements into set
    m.insert("one");
    m.insert("two");
    m.insert("three");

    // check set contains element
    cout << (m.find("three") != m.end()) << endl;
    cout << (m.find("four") != m.end()) << endl;

    // iterate over set elements
    for (string s : m) {
        cout << s << endl;
    }

    return 0;
}
