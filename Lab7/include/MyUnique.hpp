#include <utility>

template<class T>
class MyUnique {
    T* p = nullptr;

public:
    explicit MyUnique(T* ptr = nullptr) : p(ptr) {}

    ~MyUnique() {
        delete p;
    }

    MyUnique(const MyUnique&) = delete;
    MyUnique& operator=(const MyUnique&) = delete;

    MyUnique(MyUnique&& other) noexcept : p(other.p) {
        other.p = nullptr;
    }

    MyUnique& operator=(MyUnique&& other) noexcept {
        if (this != &other) {
            delete p;
            p = other.p;
            other.p = nullptr;
        }
        return *this;
    }

    T* get() const {
        return p;
    }

    T& operator*() const {
        return *p;
    }

    T* operator->() const {
        return p;
    }

    T* release() {
        T* ptr = p;
        p = nullptr;
        return ptr;
    }

    void reset(T* ptr = nullptr) {
        delete p;
        p = ptr;
    }
};
