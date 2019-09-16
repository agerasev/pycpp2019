#include <iostream>
#include <cmath>

using namespace std;


class Point {
public:
    double x, y;
    Point() {
        this->x = 0.0;
        this->y = 0.0;
    }
    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }
};

class Shape {
public:
    virtual double area() = 0;
};

class Circle : public Shape {
public:
    double radius;

    Circle() {
        this->radius = 1.0;
    }
    Circle(double radius) {
        this->radius = radius;
    }
    virtual double area() {
        return M_PI*this->radius*this->radius;
    }
};

class Polygon : public Shape {
public:
    Point *vertices;
    int vertex_count;

    Polygon(int n) {
        this->vertex_count = n;
        this->vertices = new Point[n];
    }
    Polygon(const Polygon &other) : Polygon(other.vertex_count) {
        for (int i = 0; i < other.vertex_count; ++i) {
            this->vertices[i] = other.vertices[i];
        }
    }
    virtual ~Polygon() {
        delete[] this->vertices;
    }

    Polygon &operator=(Polygon &other) {
        delete[] this->vertices;
        this->vertices = new Point[other.vertex_count];
        this->vertex_count = other.vertex_count;
        for (int i = 0; i < other.vertex_count; ++i) {
            this->vertices[i] = other.vertices[i];
        }
    }

    virtual double area() {
        Point *ps = this->vertices;
        Point p = ps[0];
        double total_area = 0.0;
        for (int i = 1; i < this->vertex_count - 1; ++i) {
            Point d = Point(ps[i + 1].x - ps[i].x, ps[i + 1].y - ps[i].y);
            Point e = Point(ps[i].x - p.x, ps[i].y - p.y);
            total_area += (d.x*e.y - d.y*e.x)/2.0;
        }
        return fabs(total_area);
    }
};

int main() {
    Circle c(10.0);
    cout << "circle area: " << c.area() << endl;

    Polygon p(4);
    p.vertices[0] = Point(0.0, 0.0);
    p.vertices[1] = Point(1.0, 0.0);
    p.vertices[2] = Point(1.0, 1.0);
    p.vertices[3] = Point(0.0, 1.0);
    cout << "polygon area: " << p.area() << endl;

    return 0;
}
