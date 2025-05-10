#include <iostream>
#include "BSTree.hpp"

int main() {
    BSTree* tree = new BSTree({4, 2, 5});
    tree->add_element(1);
    tree->delete_element(2);
    tree->load_from_file("file.txt");
    tree->save_to_file("file.txt");
    tree->print();
    return 0;
}
