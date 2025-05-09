#include <iostream>
#include <cmath>

using namespace std;

class RealNumber {
protected:
    double value;

public:
    RealNumber(double val = 0.0) : value(val) {}

    virtual double abs() const {
        return std::abs(value);
    }

    virtual void print() const {
        cout << "Вещественное число: " << value << endl;
        cout << "Модуль: " << abs() << endl;
    }

    virtual ~RealNumber() {}
};


class ComplexNumber : public RealNumber {
protected:
    double imaginary;

public:
    ComplexNumber(double real = 0.0, double imag = 0.0)
        : RealNumber(real), imaginary(imag) {}

    double abs() const override {
        return sqrt(value * value + imaginary * imaginary);
    }

    void print() const override {
        cout << "Комплексное число: " << value;
        if (imaginary >= 0) {
            cout << " + " << imaginary << "i" << endl;
        } else {
            cout << " - " << -imaginary << "i" << endl;
        }
        cout << "Модуль: " << abs() << endl;
    }
};

int main() {
    cout << "=== Статический полиморфизм ===" << endl;
    RealNumber realNum(-3.5);
    ComplexNumber complexNum(4.0, -3.0);

    realNum.print();
    complexNum.print();

    cout << "\n=== Динамический полиморфизм ===" << endl;
    RealNumber* numbers[2];
    numbers[0] = &realNum;
    numbers[1] = &complexNum;

    for (int i = 0; i < 2; ++i) {
        numbers[i]->print();
    }

    return 0;
}
