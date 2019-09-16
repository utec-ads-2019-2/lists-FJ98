#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

#include "../iterator.h"

template <typename T> 
class BidirectionalIterator : public Iterator<T> {
    public:
        BidirectionalIterator() : Iterator<T>() {};
        explicit BidirectionalIterator(Node<T> *node) : Iterator<T>(node) {};


        BidirectionalIterator<T>& operator=(BidirectionalIterator<T> other) { // TO DO
        // Falta igualar
            return *this;
        }


        bool operator!=(BidirectionalIterator<T> other) { // TO DO
            return this->current != other.current;
        }


        BidirectionalIterator<T> operator++() { // TO DO

            if (this->current == nullptr)
                throw runtime_error("Invalid Operation!");

            this->current = this->current->next;
            return *this;

        }


        BidirectionalIterator<T> operator--() {
            // TO DO
            if(this->current == nullptr)
                throw runtime_error("Invalid Operation!");

            this->current = this->current->prev;
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