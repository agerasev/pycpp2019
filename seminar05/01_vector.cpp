#include <vector>

#include <iostream>

using namespace std;


int main() {
    cout << "vector indexing and resizing" << endl;
    {
        vector<int> v;

        // resize and fill with 1
        v.resize(10, 1);
        cout << v.size() << endl;
        for (int i = 0; i < v.size(); ++i) {
            cout << v[i] << " ";
        }
        cout << endl;

        // change some cells
        v[0] = 5;
        v[4] = 6;
        v.back() = 7;
        cout << v.size() << endl;
        for (int i = 0; i < v.size(); ++i) {
            cout << v[i] << " ";
        }
        cout << endl;

        // resize and fill new cells with 2
        v.resize(20, 2);
        cout << v.size() << endl;
        for (int i = 0; i < v.size(); ++i) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    cout << "vector as stack, its size and capacity" << endl;
    {
        vector<int> v;

        // initial size and capacity
        cout << "size: " << v.size() << ", capacity: " << v.capacity() << endl;

        // push elements
        for (int i = 0; i < 17; ++i) {
            cout << "push " << i << endl;
            v.push_back(i);
            cout << "size: " << v.size() << ", capacity: " << v.capacity() << endl;
        }

        // pop elements
        for (int i = 0; i < 10; ++i) {
            cout << "push " << v.back() << endl;
            v.pop_back();
            cout << "size: " << v.size() << ", capacity: " << v.capacity() << endl;
        }

        // shrink to fit
        v.shrink_to_fit();
        cout << "size: " << v.size() << ", capacity: " << v.capacity() << endl;
    }
    
    cout << "iteration over vector" << endl;
    {
        vector<int> v;
        for (int i = 0; i < 8; ++i) {
            v.push_back(i);
        }

        // indexing
        for (int i = 0; i < v.size(); ++i) {
            cout << v[i] << " ";
        }
        cout << endl;

        // using iterators
        for (vector<int>::iterator i = v.begin(); i != v.end(); ++i) {
            cout << *i << " ";
        }
        cout << endl;

        // short form
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    
    return 0;
}
