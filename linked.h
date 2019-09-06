#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

template <typename T>
class LinkedList : public List<T> {
    public:
        LinkedList() : List<T>() {}

        T front() {
            // TO DO
            return this->head->data;
        }

        T back() {
            // TO DO
            return this->tail->data;
        }

        void push_front(T value) {
            // TO DO
            auto newNode = new Node<T>{value, nullptr, nullptr};

            if ( empty() ) {
                this->head = newNode;
                this->tail = newNode;
            } else {
                newNode->next = this->head;
                this->head->prev = newNode;
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
                newNode->prev = this->head;
                this->head->next = newNode;
            }
        }

        void pop_front() {
            // TO DO
            if ( empty() ) { throw runtime_error("Empty list!"); }

            auto keepNode = this->head->next;

            this->head->killSelf();
            this->head = keepNode;
            this->head->prev = nullptr;
        }

        void pop_back() {
            // TO DO
            if ( empty() ) { throw runtime_error("Empty list!"); }

            auto keepNode = this->tail->prev;

            this->tail->killSelf();
            this->tail = keepNode;
            this->tail->next = nullptr;

        }

        T operator[](int index) {
            // TO DO
            if ( index < 0 ) throw runtime_error("Index should be zero or positive!\n");
            if ( index > size() - 1 ) throw runtime_error("Index is bigger than the list!\n");

            auto pNode = this->head;

            while (index--) {
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
        }

        void sort() {
            // TO DO
        }
    
        void reverse() {
            // TO DO
            for (auto p = this->tail; p != nullptr ; p = p->prev) {

            }
        }

        string name() {
            return "Linked List";
        }

        BidirectionalIterator<T> begin() {
            // TO DO
            return BidirectionalIterator<T>(this->head);
        }

	    BidirectionalIterator<T> end() {
            // TO DO
            return nullptr;
        }

        void merge(LinkedList<T> list) {
            // TO DO
        }
};

#endif