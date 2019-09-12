#include <iostream>

class Animal {
public:
    double energy;
    virtual void kind() {
        std::cout << "Animal" << std::endl;
    }
};

class Bird : public Animal {
public:
    double flight_speed;
    virtual void kind() {
        std::cout << "Bird { flight_speed: " << flight_speed << "}" << std::endl;
    }
};

class Fish : public Animal {
public:
    double swim_speed;
    virtual void kind() {
        std::cout << "Fish { swim_speed: " << swim_speed << "}" << std::endl;
    }
};

int main() {
    Animal *animals[2] = {new Fish(), new Bird()};
    for (int i = 0; i < 2; ++i) {
        animals[i]->kind();
        delete animals[i];
    }
    return 0;
}
