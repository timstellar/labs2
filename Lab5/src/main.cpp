
#include <iostream>
#include <fstream>
#include "Debtors.hpp"

int main() {
    try {
            Debtors debtors;
            debtors.readFromFile("input.txt");
            
            debtors.addCredits(
                Credit("StudentLoan", "USD", 15000, 5.5),
                Credit("Mortgage", "EUR", 200000, 3.5)
            );
            
            std::ofstream outFile("output.txt");
            
            outFile << "Original vector:\n" << debtors << "\n";
            outFile << "\n";
            
            debtors.printSet(outFile);
            outFile << "\n";
            
            debtors.printUnorderedSet(outFile);
            
        } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
