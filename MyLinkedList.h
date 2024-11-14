#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H
#include "Registro.h"
#include <iostream>
#include <vector>

using namespace std;

struct MyNodoLL {
    string key;
    vector<Registro> data;
    MyNodoLL* next;

    MyNodoLL(string key, Registro reg, MyNodoLL* next) { // Complejidad: O(1) (constante)
        this->key=key;
        //this->data=data;
        data.push_back(reg);
        this->next=next;
    }

    MyNodoLL(string key, Registro reg):MyNodoLL(key, reg, nullptr) {} // Complejidad: O(1)

    //! ??? p mergeIterativo
    MyNodoLL(Registro reg):MyNodoLL("", reg, nullptr) {}
};

class MyLinkedList
{
    private:
        int sizeL;
        MyNodoLL* head;
        MyNodoLL* tail;
        /*MyNodoLL* mergeIterativo(MyNodoLL* head);
        MyNodoLL* split(MyNodoLL* head, int step);
        MyNodoLL* mergeLists(MyNodoLL* prev, MyNodoLL* left, MyNodoLL* right);*/

    public:
        MyLinkedList();

        MyNodoLL* getHead();
        bool isEmpty();
        void insertFirst(string key,Registro data);
        vector<Registro> getAt(string key);
        void removeAt(string key);
        //void mergeSort();

        virtual ~MyLinkedList();
};

#endif // MYLINKEDLIST_H
