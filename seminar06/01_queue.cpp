#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {
    stack<int> s;

    cout << "stack" << endl;
    for (int i = 0; i < 8; ++i) {
        s.push(i);
    }

    for (int i = 0; i < 8; ++i) {
        cout << s.top() << endl;
        s.pop();
    }

    cout << "queue" << endl;

    queue<int> q;

    for (int i = 0; i < 8; ++i) {
        q.push(i);
    }

    for (int i = 0; i < 8; ++i) {
        cout << q.front() << endl;
        q.pop();
    }

    return 0;
}