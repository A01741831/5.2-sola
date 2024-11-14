
#include "MyLinkedList.h"
#include "Registro.h"
#include <stdexcept>
#include <iostream>

using namespace std;

MyLinkedList::MyLinkedList() // Complejidad: O(1) (constante)
{
    sizeL=0;
    head=tail=nullptr;
}

MyNodoLL* MyLinkedList::getHead() // Complejidad: O(1)
{
    return head;
}

bool MyLinkedList::isEmpty() // Complejidad: O(1)
{
    return sizeL==0;
}

void MyLinkedList::insertFirst(string key,Registro data) // Complejidad: O(1)
{
    MyNodoLL* current=head;
    bool found=false;

    while (current!=nullptr) {
        if (current->key==key) {
            current->data.push_back(data);
            found=true;
            break;
        }
        current=current->next;
    }

    if (!found) {
        MyNodoLL* nvo=new MyNodoLL(key,data,head);
        head=nvo;
        if (sizeL==0) {
            tail=nvo;
        }
        sizeL++;
    }
}

vector<Registro> MyLinkedList::getAt(string key) // Complejidad (caso promedio): O(n)
{
    MyNodoLL* current=head;

    while (current!=nullptr) {
        if (current->key==key) {
            return current->data;
        }
        current=current->next;
    }

    throw invalid_argument("No se encontro la llave "+key+" en la tabla.");
}

void MyLinkedList::removeAt(string key) // Complejidad (caso promedio): O(n)
{
    MyNodoLL* prev;
    MyNodoLL* current=head;
    MyNodoLL* tmp;
    bool found=false;

    while (current!=nullptr) {
        if (current->key==key) {
            found=true;
            break;
        }
        prev=current;
        current=current->next;
    }

    if (current==head) {
        tmp=head;
        head=head->next;
        delete tmp;
        sizeL--;
        if (sizeL==0) {
            tail=nullptr;
        }
    } else if (found) {
        prev->next=current->next;
        delete current;
        sizeL--;
    } else {
        throw invalid_argument("No se pudo eliminar el elemento con la llave "+key+" porque no se encontro.");
    }
}

MyLinkedList::~MyLinkedList() // Complejidad: O(n)
{
    if (sizeL>0) {
        MyNodoLL* current=head;

        for (int i=0;i<sizeL;i++) {
            MyNodoLL* temp=current;
            current=current->next;
            delete temp;
        }

        head=tail=nullptr;
        sizeL=0;
    }
}
