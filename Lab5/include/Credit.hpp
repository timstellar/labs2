#include <iostream>
#include <string>
#include <functional>

class Credit {
public:
    std::string name;
    std::string type;
    float summ;
    float rate;
    
    Credit() : name(""), type(""), summ(0.0f), rate(0.0f) {};
    Credit(std::string creditName, std::string currencyType, float creditSumm, float creditRate)
            : name(creditName), type(currencyType), summ(creditSumm), rate(creditRate) {};
    Credit(const Credit& credit)
            : name(credit.name), type(credit.type) summ(credit.summ), rate(credit.rate) {};
    Credit(const Credit& credit) noexcept
            : name(credit.name), type(credit.type) summ(credit.summ), rate(credit.rate) {
        credit.name = "";
        credit.type = "";
        credit.summ = 0.0f;
        credit.rate = 0.0f;
    };
    
    Credit& operator=(const Credit& credit) {
        if (this != &credit) {
            name = credit.name;
            type = credit.type;
            summ = credit.summ;
            rate = credit.rate;
        }
        return *this;
    }
    
    Credit& operator=(Credit&& credit) noexcept {
        if (this != &credit) {
            name = std::move(credit.name);
            type = std::move(credit.type);
            summ = credit.summ;
            rate = credit.rate;
            credit.summ = 0.0f;
            credit.rate = 0.0f;
        }
        return *this;
    }
    
    ~Credit();
    
    friend std::ostream& operator<<(std::ostream& os, const Credit& credit) {
        os << "Credit: " << credit.name
           << ", Amount: " << credit.summ << " " << credit.type
           << ", Rate: " << credit.rate << "%";
        return os;
    }
    
    bool operator<(const Credit& other) const {
        return summ < other.summ;
    }
    
    bool operator==(const Credit& other) const {
        return name == other.name &&
               type == other.type &&
               summ == other.summ &&
               rate == other.rate;
    }
};

namespace std {
    template<>
    struct hash<Credit> {
        size_t operator()(const Credit& credit) const {
            return hash<string>()(credit.name) ^
                   hash<string>()(credit.type) ^
                   hash<float>()(credit.summ) ^
                   hash<float>()(credit.rate);
        }
    };
}
