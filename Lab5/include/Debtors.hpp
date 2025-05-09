#include <vector>
#include <deque>
#include <algorithm>
#include <fstream>
#include "Credit.hpp"

class Debtors: {
private:
    std::vector<Credit> debts;
    std::set<Credit> debtSet;
    std::unordered_set<Credit> debtUnorderedSet;
    
public:
    
    Debtors(Credit&&... credit) {
        debts.reserve(debts.size() + sizeof...(credit));
        (debts.emplace_back(credit), ...);
        (addToSets(Credit(std::forward<Credit>(credit))), ...);
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
    }
    
    void addToSets(const Credit& credit) {
        debtSet.insert(credit);
        debtUnorderedSet.insert(credit);
    }
    
    void sortByAmount() {
        std::sort(debts.begin(), debts.end());
    }
    
    std::deque<Credit> copyToDeque() const {
        std::deque<Credit> result;
        std::copy(debts.begin(), debts.end(), std::back_inserter(result));
        return result;
    }
    
    const std::set<Credit>& getDebtSet() const {
        return debtSet;
    }
    
    const std::unordered_set<Credit>& getDebtUnorderedSet() const {
        return debtUnorderedSet;
    }
    
    void printSet(std::ostream& os) const {
        os << "Set contents (sorted unique):\n";
        for (const auto& credit : debtSet) {
            os << credit << "\n";
        }
    }
    
    void printUnorderedSet(std::ostream& os) const {
        os << "Unordered set contents (unique):\n";
        for (const auto& credit : debtUnorderedSet) {
            os << credit << "\n";
        }
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Debtors& debtors) {
        for (const auto& credit : debtors.debts) {
            os << credit << "\n";
        }
        return os;
    }
};
