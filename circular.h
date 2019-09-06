#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"

template <typename T>
class CircularLinkedList : public List<T> {
    public:
        CircularLinkedList() : List<T>() {}

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
//                newNode->next = this->head;
//                this->head->prev = newNode;
//                this->head = newNode;
//                this->tail = this->head;
//                this->head = this->tail;
            }


        }

        void push_back(T value) {
            // TO DO
            auto newNode = new Node<T>{value, nullptr, nullptr};

            if ( empty() ) {
                this->head = newNode;
                this->tail = newNode;
            } else {

            }


        }

        void pop_front() {
            // TO DO
            if ( empty() ) { throw runtime_error("Empty list!"); }

            auto keepNode = this->head->next;

//            this->head->killSelf();
//            this->head = keepNode;
//            this->head->prev = nullptr;
//            this->tail = this->head;
//            this->head = this->tail;

        }

        void pop_back() {
            // TO DO
            if ( empty() ) { throw runtime_error("Empty list!"); }

            auto keepNode = this->tail->prev;



        }

        T operator[](int index) {
            // TO DO



        }

        bool empty() {
            // TO DO
            return this->head == nullptr && this->tail == nullptr;
        }

        int size() {
            // TO DO
            int counter = 0;

            for (auto pNode = this->head; pNode != nullptr ; pNode = pNode->next) {
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

        }

        string name() {
            return "Circular Linked List";
        }

        BidirectionalIterator<T> begin() {
            // TO DO
        }

	    BidirectionalIterator<T> end() {
            // TO DO
        }

        void merge(CircularLinkedList<T> list) {
            // TO DO
        }
};

#endif