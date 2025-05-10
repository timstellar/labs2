#include "BSTree.hpp"
#include "Node.hpp"
#include <fstream>
#include <ostream>

bool BSTree::add_element(int value) {
    Node** current = &nodeList;
    
    while (*current != nullptr) {
        if (value > (*current)->val) {
            current = &(*current)->right;
        } else if (value < (*current)->val) {
            current = &(*current)->left;
        } else {
            return false;
        }
    }
    *current = new Node(value);
    return true;
}

bool BSTree::delete_element(int value) {
    Node** current = &nodeList;
    
    while (*current != nullptr) {
        if (value > (*current)->val) {
            current = &(*current)->right;
        } else if (value < (*current)->val) {
            current = &(*current)->left;
        } else {
            Node* toDelete = *current;
            
            if (toDelete->left == nullptr && toDelete->right == nullptr) {
                *current = nullptr;
                delete toDelete;
            } else if (toDelete->left == nullptr) {
                *current = toDelete->right;
                delete toDelete;
            } else if (toDelete->right == nullptr) {
                *current = toDelete->left;
                delete toDelete;
            } else {
                Node** successor = &toDelete->right;
                while ((*successor)->left != nullptr) {
                    successor = &(*successor)->left;
                }
    
                toDelete->val = (*successor)->val;
                
                Node* temp = *successor;
                *successor = (*successor)->right;
                delete temp;
            }
            
            return true;
        }
    }
    return false;
}

bool BSTree::find_element(int value) {
    Node** current = &nodeList;
    
    while (*current != nullptr) {
        if (value > (*current)->val) {
            current = &(*current)->right;
        } else if (value < (*current)->val) {
            current = &(*current)->left;
        } else {
            return true;
        }
    }
    return false;
}

void printNode(const Node* node) {
    
    if (node == nullptr) {
        std::cout << "null";
        return;
    }
    
    std::cout << node->val << " -> {";
    
    if (node->left) {
        std::cout << "L:" << node->left->val;
    } else {
        std::cout << "L:null";
    }
    
    std::cout << ", ";
    
    if (node->right) {
        std::cout << "R:" << node->right->val;
    } else {
        std::cout << "R:null";
    }
    
    std::cout << "}";
}

void printTree(const Node* root) {
    if (root == nullptr) {
        std::cout << "Tree is empty" << std::endl;
        return;
    }
    
    printNode(root);
    std::cout << std::endl;
    
    if (root->left) {
        printTree(root->left);
    }
    if (root->right) {
        printTree(root->right);
    }
}

void BSTree::print() {
    printTree(nodeList);
}

void writeNode(const Node* node, std::ofstream& File) {
    
    if (node == nullptr) {
        return;
    }
    
    File << node->val << ' ';
    
    if (node->left) {
        File << node->left->val << ' ';
    }
    
    if (node->right) {
        File << node->right->val << ' ';
    }
}

void writeTree(const Node* root, std::ofstream& File) {
    if (root == nullptr) {
        return;
    }
    
    writeNode(root, File);
    
    if (root->left) {
        writeTree(root->left, File);
    }
    if (root->right) {
        writeTree(root->right, File);
    }
}

bool BSTree::save_to_file(const std::string& path) {
    std::ofstream File(path);
    if (!File) {
        throw std::runtime_error("Cannot open output file");
    }
    writeTree(nodeList, File);
    File.close();
    return true;
}

bool BSTree::load_from_file(const std::string& path) {
    std::ifstream File(path);
    if (!File) {
        throw std::runtime_error("Cannot open input file");
    }
    std::string line;
    while (std::getline(File, line, ' ')) {
        add_element(std::stoi(line));
    }
    
    return true;
}
