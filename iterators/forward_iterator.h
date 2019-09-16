#ifndef FORWARD_ITERATOR_H
#define FORWARD_ITERATOR_H

#include "../iterator.h"

template <typename T> 
class ForwardIterator : public Iterator<T> {
    public:
        ForwardIterator() : Iterator<T>() {};
        explicit ForwardIterator(Node<T> *node) : Iterator<T>(node) {};

        ForwardIterator<T> operator=(ForwardIterator<T>* other) {
            // TO DO
            // Estás creando un nuevo iterador
            ForwardIterator<T> assignNode(other->current);
            return assignNode;
        }

        bool operator!=(ForwardIterator<T> other) {
            // TO DO
            return this->current != other.current;
        }

        ForwardIterator<T> operator++() {
            // TO DO
            if(this->current == nullptr)
                throw runtime_error("Invalid Operation!");

            this->current = this->current->next;
            return *this;
        }

        T operator*() {
            // TO DO
            if(this->current == nullptr)
                throw runtime_error("Invalid Operation!");

            return this->current->data;
        }
};

#endif