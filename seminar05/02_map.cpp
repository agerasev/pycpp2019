#include <map>
#include <string>

#include <iostream>

using namespace std;

int main() {
    map<string, int> m;

    // Insert pairs of key-value
    m.insert(make_pair("one", 1));
    m.insert(make_pair("two", 2));
    m["three"] = 3;

    // Check map contains key
    cout << (m.find("three") != m.end()) << endl;
    cout << (m.find("four") != m.end()) << endl;

    // Read and write value by key
    cout << m["three"] << endl;
    m["three"] = 4;

    // Iterate over all key-value pairs
    for (pair<string, int> p : m) {
        cout << p.first << ": " << p.second << endl;
    }

    return 0;
}
