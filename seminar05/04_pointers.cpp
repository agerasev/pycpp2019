#include <memory>

#include <iostream>

using namespace std;

class Dummy {
public:
    int n;

    Dummy(int n) {
        this->n = n;
        cout << "create dummy " << this->n << endl;
    }
    ~Dummy() {
        cout << "destroy dummy " << this->n << endl;
    }
};

int main() {
    cout << "enter main" << endl;
    shared_ptr<Dummy> p1(new Dummy(1));
    weak_ptr<Dummy> wp = p1;

    cout << wp.lock()->n << endl;

    {
        cout << "  enter scope" << endl;

        shared_ptr<Dummy> p2 = p1;
        cout << p2->n << endl;

        p1 = shared_ptr<Dummy>(new Dummy(2));

        cout << "  leave scope" << endl;
    }

    cout << p1->n << endl;

    /*
    unique_ptr<Dummy> p1(new Dummy(1));
    unique_ptr<Dummy> p2 = move(p1);
    cout << p2->n << endl;
    */
    cout << "leave main" << endl;
    return 0;
}