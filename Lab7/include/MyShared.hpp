template<class T>
class MyShared {
    T* ptr = nullptr;
    size_t* count = nullptr;

    void release() {
        if (count && --(*count) == 0) {
            delete ptr;
            delete count;
        }
    }

public:
    explicit MyShared(T* p = nullptr) : ptr(p), count(new size_t(1)) {}

    ~MyShared() {
        release();
    }

    MyShared(const MyShared& other) : ptr(other.ptr), count(other.count) {
        if (count) (*count)++;
    }

    MyShared& operator=(const MyShared& other) {
        if (this != &other) {
            release();
            ptr = other.ptr;
            count = other.count;
            if (count) (*count)++;
        }
        return *this;
    }

    MyShared(MyShared&& other) noexcept : ptr(other.ptr), count(other.count) {
        other.ptr = nullptr;
        other.count = nullptr;
    }

    MyShared& operator=(MyShared&& other) noexcept {
        if (this != &other) {
            release();
            ptr = other.ptr;
            count = other.count;
            other.ptr = nullptr;
            other.count = nullptr;
        }
        return *this;
    }

    T* get() const {
        return ptr;
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    size_t use_count() const {
        return count ? *count : 0;
    }
};
