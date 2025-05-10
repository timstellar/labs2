#include <iostream>

class MyPoint {
    int x, y;
public:
    MyPoint(int x, int y) : x(x), y(y) {
        std::cout << "MyPoint constructed: (" << x << ", " << y << ")\n";
    }
    ~MyPoint() {
        std::cout << "MyPoint destroyed: (" << x << ", " << y << ")\n";
    }
    void print() const {
        std::cout << "Point: (" << x << ", " << y << ")\n";
    }
};

