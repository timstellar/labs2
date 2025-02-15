
#include <iostream>
#include <fstream>
#include "Debtors.hpp"

int main() {
    try {
        // Create debtors and read from file
        Debtors debtors;
        debtors.readFromFile("input.txt");
        
        // Open output file
        std::ofstream outFile("output.txt");
        if (!outFile) {
            throw std::runtime_error("Cannot open output file");
        }
        
        // Write original data
        outFile << "Original credits (vector):\n";
        outFile << debtors << "\n";
        
        // Sort and write sorted data
        debtors.sortByAmount();
        outFile << "Sorted by amount (vector):\n";
        outFile << debtors << "\n";
        
        // Copy to deque and write
        auto creditDeque = debtors.copyToDeque();
        outFile << "Copied to deque:\n";
        for (const auto& credit : creditDeque) {
            outFile << credit << "\n";
        }
        
        std::cout << "Processing completed. Results saved to output.txt\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
