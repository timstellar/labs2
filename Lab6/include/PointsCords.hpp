#pragma once

#include "OutOfBounds.hpp"

struct PointsCords {
public:
    float x;
    float y;
    float z;
    
    PointsCords(float posX, float posY, float posZ) : x(posX), y(posY), z(posZ) {
        if (0.0f >= posX || posX >= 1.0f || 0.0f >= posY || posY >= 1.0f || 0.0f >= posZ || posZ >= 1.0f) {
            throw OutOfBounds(posX, posY, posZ);
        }
    };
    
    void print() {
        std::cout << "x = " + std::to_string(x) + "; y = " + std::to_string(y)+ "; z = " + std::to_string(z) << std::endl;
    }
};
