#pragma once
#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <iostream>
#include "Node.h"

using namespace std;
template <typename T>
class LinkedList;

template<typename T>
std::ostream& operator<<(std::ostream& salida1, const LinkedList<T>& C);

template <typename T>
class LinkedList {
    int size;

public:
    Node<T>* head;
    Node<T>* fin;

    LinkedList();
    LinkedList(T);
    LinkedList(const LinkedList&);

    ~LinkedList();

    void pushFront(T);
    //problema 1
    int Minimum();
    //problema 2
    void Insertk(T,int);
    //probelma 3
    void Ordenado();
    //Problema 4
    bool IsElement(T);
    //problema 5
    void Reverse();
    //problema 7
    void SortedInserter(T);
    //problema 8
    void InsertTail(T);



    friend std::ostream& operator<<<T>(std::ostream& salida1, const LinkedList& C);
};

template<typename T>
LinkedList<T>::LinkedList() {
    this->size = 0;
    this->head = nullptr;
    this->fin = nullptr;
}

template<typename T>
LinkedList<T>::LinkedList(T value) {
    this->size = 1;
    this->head = new Node<T>(value);
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& o) {
    this->size = 0;
    this->head = nullptr;
    Node<T>* actual_o = o.head;
    while (actual_o)
    {
        this->InsertTail(actual_o->getValue());
        actual_o = actual_o->getNext();
    }
}

template<typename T>
std::ostream& operator<<(std::ostream& salida1, const LinkedList<T>& C) {
    Node<T>* aux = C.head;
    while (aux != nullptr) {
        salida1 << "[" << aux->getValue() << "]->";
        aux = aux->getNext();
    }
    return salida1;
}

template <typename T>
void LinkedList<T>::pushFront(T value) {
    head = new Node<T>(value, head);
    size++;
}

//problema 1
template<typename T>
int LinkedList<T>::Minimum() {
    Node<T>* aux = head;
    int min = aux->getValue();
    while (aux != nullptr) {
        if (min > aux->getValue()) {
            min = aux->getValue();
        }
        aux = aux->getNext();
    }
    return min;
}

//problema 2
template<typename T>
void LinkedList<T>::Insertk(T value, int pos) {
    Node<T>* newNode = new Node<T>(value);
    Node<T>* tmp = head;
    int i = 0;
    if (head == nullptr) {
        head = newNode;
    }
    else {
        while (i<pos-1)
        {
            if (tmp != nullptr) {
                tmp = tmp->getNext();
            }
            i++;
           
        }
        if (tmp != nullptr) {
            newNode->setNext(tmp->getNext());
            tmp->setNext(newNode);

        }
    }
    size++;
}

//problema 3
template<typename T>
void LinkedList<T>::Ordenado() {
    Node<T>* ant = head;
    int i = 0;
    while (ant->getNext() != nullptr) {
        if (ant->getNext()->getValue() > ant->getValue()) {
            std::cout << "true"<<endl;
            break;
        }
        else {
            std::cout << "false"<<endl;
            break;
        }
    }
}

//problema 4
template <typename T>
bool LinkedList<T>::IsElement(T value) {
    Node<T>* actual = head;
    if (size - 1 != 0) {
        int i = 0;
        while (actual != nullptr) {
            if (value == actual->getValue()) {
                return true;
                break;
            }

            else {
                actual = actual->getNext();
                i++;
            }

        }
    }
}

//problema 5
template<typename T>
void LinkedList<T>::Reverse() {
    Node<T>* ini = head;
    Node<T>* final = nullptr, * sig = nullptr;
    while (ini != nullptr) {
        sig = ini->getNext();
        ini->setNext(final);
        final = ini;
        ini = sig;
    }
    head = final;
}

//preoblema 6
template<typename T>
LinkedList<T> operator +(LinkedList<T>& L1, LinkedList<T>& L2) {
    Node<T>* aux1 = L1.head;
    Node<T>* aux2 = L2.head;
    LinkedList<T> L3;

    if (aux1 == nullptr) {
        aux1 = aux2;
    }

    else {
        while (aux2->getNext() != nullptr) {
            while (aux1->getNext() != nullptr) {
                L3.InsertTail(aux1->getValue());
                aux1 = aux1->getNext();
            }
            L3.InsertTail(aux2->getValue());
            aux2 = aux2->getNext();
        }
        L3.InsertTail(aux2->getValue());
    }
    return L3;
}
//problema 7
template<typename T>
void LinkedList<T>::SortedInserter(T elemento) {
    Node<T>* newNode = new Node<T>(elemento);
    Node<T>* tmp = head;
    if (!head) {
        head = newNode;
    }
    else {
        if (head->getValue() > elemento) {
            newNode->setNext(head);
            head = newNode;
        }
        else {
            while ((tmp->getNext() != nullptr) && (tmp->getNext()->getValue() < elemento)) {
                tmp = tmp->getNext();
            }
            newNode->setNext(tmp->getNext());
            tmp->setNext(newNode);
        }
    }
    size++;
}
//problema 8
template<typename T>
void LinkedList<T>::InsertTail(T value) {
    Node<T>* newNode = new Node<T>(value);
    Node<T>* tmp = head;
    if (head == nullptr) {
        head = newNode;
    }
    else {
        while (tmp->getNext() != nullptr)
        {
            tmp = tmp->getNext();
        }
        newNode->setNext(tmp->getNext());
        tmp->setNext(newNode);
    }
    size++;
}


template<typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* actual;
    while (head != nullptr) {
        actual = head->getNext();
        delete head;
        head = actual;
    }
    delete head;
}

#endif
