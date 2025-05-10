#pragma once
    
struct Node {
    Node* left;
    Node* right;
    int val;
    
    Node(int value) : val(value), left(nullptr), right(nullptr) {};
};
