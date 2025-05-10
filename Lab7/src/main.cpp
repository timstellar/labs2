#include <iostream>
#include "MyUnique.hpp"
#include "MyPoint.hpp"
#include "MyShared.hpp"

template<typename T, typename... Args>
MyShared<T> Make_MyShared(Args&&... args) {
    return MyShared<T>(new T(std::forward<Args>(args)...));
}

template<typename T, typename... Args>
MyUnique<T> Make_MyUnique(Args&&... args) {
    return MyUnique<T>(new T(std::forward<Args>(args)...));
}

int main() {
    auto p1 = Make_MyUnique<MyPoint>(10, 20);
    p1->print();

    auto p2 = std::move(p1);
    if (!p1.get()) {
        std::cout << "p1 is now empty" << std::endl;
    }
    p2->print();

    (*p2).print();
    
    
    auto sp1 = Make_MyShared<MyPoint>(30, 40);
    sp1->print();
    std::cout << "Use count: " << sp1.use_count() << std::endl;

    auto sp2 = sp1;
    sp2->print();
    std::cout << "Use count sp1: " << sp1.use_count() << std::endl;
    std::cout << "Use count sp2: " << sp2.use_count() << std::endl;

    auto sp3 = std::move(sp2);
    sp3->print();
    std::cout << "Use count sp1: " << sp1.use_count() << std::endl;
    std::cout << "Use count sp2: " << sp2.use_count() << std::endl;
    std::cout << "Use count sp3: " << sp3.use_count() << std::endl;

    return 0;
}
