#pragma once

#include <stdexcept>
#include <string>
#include <iostream>

class OutOfBounds : public std::out_of_range {
private:
    float wrongX;
    float wrongY;
    float wrongZ;
public:
    explicit OutOfBounds(const std::string& message, float x, float y, float z)
        : std::out_of_range(message), wrongX(x), wrongY(y), wrongZ(z) {};
    
    OutOfBounds(float x, float y, float z)
        : std::out_of_range("Error! Enter number 0.0 - 1.0. Your input data: x = " + std::to_string(x) + "; y = " + std::to_string(y) + "; z = " + std::to_string(z)), wrongX(x), wrongY(y), wrongZ(z) {};
    
    virtual ~OutOfBounds() noexcept = default;
    
    float getWrongX() const { return wrongX; };
    float getWrongY() const { return wrongY; };
    float getWrongZ() const { return wrongZ; };
    
    void print() {
        std::cout << "x = " + std::to_string(wrongX) + "; y = " + std::to_string(wrongY)+ "; z = " + std::to_string(wrongZ) << std::endl;
    }
};
