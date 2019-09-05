#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node(): data{0}, next{nullptr}, prev{nullptr} {}

    void killSelf() {
        // TO DO
        delete this;
    }
};

#endif