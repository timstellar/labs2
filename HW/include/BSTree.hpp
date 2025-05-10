#include <iostream>
#include "Node.hpp"
#include <initializer_list>

class BSTree {
private:
    Node* nodeList;
    
public:
    BSTree() : nodeList(nullptr) {}; // конструктор по умолчанию.
    BSTree(std::initializer_list<int> list) : nodeList(nullptr) {
        if (list.size() == 0) return;
        nodeList = new Node(*list.begin());
        auto lists = list.begin();
        ++lists;
        for (; lists != list.end(); ++lists) {
            add_element(*lists);
        }
    };
    
    bool add_element(int value); // функция добавления
    bool delete_element(int value); // функция удаления
    bool find_element(int value); // функция поиска элемента
    void print(); // функция вывода дерева в консоль
    bool save_to_file(const std::string& path); // функция сохранения в файл
    bool load_from_file(const std::string& path); // функция загрузки из файла
    
    ~BSTree(); //деструктор

};
