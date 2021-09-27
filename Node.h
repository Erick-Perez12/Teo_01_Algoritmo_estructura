#pragma once
#ifndef __NODE_H__
#define __NODE_H__

template <class T>
class Node;

template <class T>
std::ostream& operator<<(std::ostream& out, const Node<T>& node);

template <class T>
class Node {
private:
    T value;
    Node<T>* next;

public:
    Node(T _value = 0, Node<T>* _next = nullptr) :
        value(_value), next(_next) {}

    T getValue() const;
    void setValue(T);

    Node<T>* getNext() const;
    void setNext(Node<T>*);
    friend std::ostream& operator<<<T>(std::ostream& out, const Node& node);
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Node<T>& node)
{
    out << node.value;
    return out;
}

template<typename T>
void Node<T>::setValue(T _value) {
    this->value = _value;
}

template<typename T>
T Node<T>::getValue() const {
    return value;
}

template<typename T>
void Node<T>::setNext(Node<T>* _next) {
    this->next = _next;
}

template<typename T>
Node<T>* Node<T>::getNext() const {
    return next;
}

//#include "Node.cpp"
#endif 
