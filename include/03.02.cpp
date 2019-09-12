#include <iostream>

class Shape {
public:
    //virtual double area() = 0;
    Shape() {
        std::cout << "shape created" << std::endl;
    }
    virtual ~Shape() {
        std::cout << "shape deleted" << std::endl;
    }
};

class Circle : public Shape {
public:
    Circle() {
        std::cout << "circle created" << std::endl;
    }
    virtual ~Circle() {
        std::cout << "circle deleted" << std::endl;
    }
};

void fn() {
    Shape *c = new Circle;
    std::cout << "fn" << std::endl;
    delete c;
}

int main() {
    std::cout << "before" << std::endl;
    fn();
    std::cout << "after" << std::endl;

    /*
    float *dyn_array = new float[100];

    for (int i = 0; i < 100; ++i) {
        dyn_array[i] = (float)i;
    }
    for (int i = 0; i < 100; ++i) {
        std::cout << dyn_array[i] << ", ";
    }
    std::cout << std::endl;

    delete[] dyn_array;
    */
    return 0;
}
