#include <iostream>
#include "OutOfBounds.hpp"
#include "PointsCords.hpp"

int main() {
    PointsCords point(1.0f, 0.5f, 0.5f);
    point.print();
    
    PointsCords point2(1.0f, 1.5f, 0.5f);
    return 0;
}
