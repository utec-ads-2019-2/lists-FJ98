#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"

template <typename T>
class ForwardList : public List<T> {
    public:
        ForwardList() : List<T>() {}

        T front() {
            // TO DO
            if ( empty() ) { throw runtime_error("Empty list!\n"); }
            return this->head->data;
        }

        T back() {
            // TO DO
            if ( empty() ) { throw runtime_error("Empty list!\n"); }

            return this->tail->data;
        }

        void push_front(T value) {
            // TO DO
            auto newNode = new Node<T>{value, nullptr, nullptr};
            if ( empty() ) {
                this->head = newNode;
                this->tail = newNode;
            } else{
                newNode->next = this->head;
                this->head = newNode;
            }

        }

        void push_back(T value) {
            // TO DO
            auto newNode = new Node<T>{value, nullptr, nullptr};
            if ( empty() ) {
                this->head = newNode;
                this->tail = newNode;
            } else {
                this->tail->next = newNode;
                this->tail = newNode;
            }
        }

        void pop_front() {
            // TO DO
            if ( empty() ) { throw runtime_error("Empty list!\n"); }

            auto popNode = this->head;
            this->head = popNode->next;
            popNode->killSelf();

        }

        void pop_back() {
            // TO DO
            if ( empty() ) { throw runtime_error("Empty list!\n"); }

            auto keepNode = this->head;
            auto popNode = this->tail;

            while (keepNode->next != this->tail) {
                keepNode = keepNode->next;
            }

            this->tail = keepNode;
            popNode->killSelf();
            this->tail->next = nullptr;

        }

        T operator[](int index) {
            // TO DO
            if ( index < 0 ) throw runtime_error("Index should be zero or positive!\n");
            if ( index > size() - 1 ) throw runtime_error("Index is bigger than the list!\n");

            auto pNode = this->head;

            while( index-- ) {
                pNode = pNode->next;
            }

            return pNode->data;
        }

        bool empty() {
            // TO DO
            return this->head == nullptr && this->tail == nullptr;
        }

        int size() {
            // TO DO
            int counter = 0;

            for (auto pNode = this->head; pNode != nullptr; pNode = pNode->next) {
                ++counter;
            }

            return counter;

        }

        void clear() {
            // TO DO
            if ( empty() ) { throw runtime_error("Empty list!\n"); }

            for (auto p =  this->head; p != nullptr; p = p->next) {
                p->killSelf();
            }

            this->tail = nullptr;
            this->head = nullptr;
        }

        void sort() {
            // TO DO
            if ( empty() ) { throw runtime_error("Empty list!\n"); }

            int swapped, i;
            Node<T>* ptr1, *lptr = nullptr;

            do{
                swapped = 0;

                for (ptr1 = this->head; ptr1->next != lptr; ptr1 = ptr1->next) {
                    if (ptr1->data > ptr1->next->data) {
                        std::swap(ptr1->data, ptr1->next->data);
                        swapped = 1;
                    }
                }
                lptr = ptr1;
            } while (swapped);
        }
    
        void reverse() {
            // TO DO
            if ( empty() ) { throw runtime_error("Empty list!\n"); }

            Node<T> *previous = nullptr, *next = nullptr;
            auto current = this->head;

            this->tail = this->head;

            while (current != nullptr) {
                next = current->next;
                current->next  = previous;
                previous = current;
                current = next;
            }

            this->head = previous;

        }

        string name() { return "Forward List"; }

        ForwardIterator<T> begin() {
            // TO DO
            return ForwardIterator<T>( this->head );
        }

	    ForwardIterator<T> end() {
            // TO DO
            return ForwardIterator<T>( nullptr );
        }

        void merge(ForwardList<T> list) {
            // TO DO
            for (auto p = list.head; p != nullptr; p = p->next) {
                this->push_back(p->data);
            }
        }
};

#endif