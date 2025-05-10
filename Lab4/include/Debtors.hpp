#include <vector>
#include <deque>
#include <algorithm>
#include <fstream>
#include "Credit.hpp"

class Debtors: {
private:
    std::vector<Credit> debts;
    
public:
    
    Debtors(Credit&&... credit) {
        debts.reserve(debts.size() + sizeof...(credit));
        (debts.emplace_back(credit), ...);
    };
    
    void readFromFile(const std::string& filename) {
        std::ifstream inFile(filename);
        if (!inFile) {
            throw std::runtime_error("Cannot open input file");
        }
        
        std::string name, type;
        float summ, rate;
        while (inFile >> name >> type >> summ >> rate) {
            debts.emplace_back(name, type, summ, rate);
        }
        inFile.close();
    }
    
    void sortByAmount() {
        std::sort(debts.begin(), debts.end());
    }
    
    std::deque<Credit> copyToDeque() const {
        std::deque<Credit> result;
        std::copy(debts.begin(), debts.end(), std::back_inserter(result));
        return result;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Debtors& debtors) {
        for (const auto& credit : debtors.debts) {
            os << credit << "\n";
        }
        return os;
    }
};
