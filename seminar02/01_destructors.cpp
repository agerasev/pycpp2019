#include <iostream>

using namespace std;

class Parent {
public:
    Parent() {
        cout << "parent created" << endl;
    }
    virtual ~Parent() {
        cout << "parent deleted" << endl;
    }
};

class Child : public Parent {
public:
    Child() {
        cout << "  child created" << endl;
    }
    virtual ~Child() {
        cout << "  child deleted" << endl;
    }
};

void check_stack() {
    Child c;
    cout << "    object on stack" << endl;
}

void check_heap() {
    Parent *c = new Child;
    cout << "    object on heap" << endl;
    delete c;
}

int main() {
    check_stack();
    cout << endl;
    check_heap();
    return 0;
}
