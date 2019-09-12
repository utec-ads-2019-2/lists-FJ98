#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"

template <typename T>
class CircularLinkedList : public List<T> {
    public:
        CircularLinkedList() : List<T>() {}

        T front() { // TO DO

            if ( empty() ) { throw runtime_error("Empty list!\n"); }

            return this->head->data;

        }

        T back() { // TO DO

            if ( empty() ) { throw runtime_error("Empty list!\n"); }

            return this->head->prev->data;

        }

        void push_front(T value) { // TO DO

            auto newNode = new Node<T>{value, nullptr, nullptr};

            if ( empty() ) {
                this->head = newNode;
                this->head->prev = newNode;
                this->head->next = newNode;
            } else {
                this->head->prev = newNode;
                newNode->next = this->head;
                newNode->prev = this->tail;
                this->head = newNode;
                this->tail->next = newNode;
            }

        }

        void push_back(T value) { // TO DO

            auto newNode = new Node<T>{value, nullptr, nullptr};

            if ( empty() ) {
                this->head = newNode;
                this->tail = newNode;
                newNode->next = this->head;
                newNode->prev = this->tail;
            } else {
                newNode->prev = this->tail;
                this->tail->next = newNode;
                newNode->next = this->head;
                this->head->prev = newNode;
                this->tail = newNode;
            }

        }

        void pop_front() { // TO DO

            if (empty()) return;

            auto keepNode = this->head->next;

            delete this->head;
            this->head = keepNode;
            this->head->prev = this->tail;
            this->tail->next = this->head;

        }

        void pop_back() { // TO DO

            if (!this->head) return;

            auto keepNode = this->tail->prev;

            delete this->tail;
            this->tail = keepNode;
            this->head->prev = this->tail;
            this->tail->next = this->head;

        }

        T operator[](int index) { // TO DO

            if ( index < 0 ) throw std::runtime_error("Index should be zero or positive!\n");
            if ( index > size() - 1 ) throw std::runtime_error("Index is bigger than the list!\n");

            index = index % this->size();
            auto pNode = this->head;

            while (index--) {
                pNode = pNode->next;
            }

            return pNode->data;
        }

        bool empty() { // TO DO
            return this->head == nullptr && this->tail == nullptr;
        }

        int size() { // TO DO

            int counter = 0;
            Node<T>* start = this->head;

            if( empty() ) { return 0; }

            ++counter;
            start = start->next;

            while(start != this->head){
                ++counter;
                start = start->next;
            }

            return counter;

        }

        void clear() { // TO DO

            this->tail->next = nullptr;
            this->head->prev = nullptr;

            this->head->killSelf();

            this->tail = nullptr;
            this->head = nullptr;

        }

        void sort() { // TO DO

            if ( empty() || this->head->next == this->head) { throw std::runtime_error("List already sorted!"); }

            for (auto i = this->head; i->next != this->head; i = i->next) {
                for (auto j = i->next; j != this->head; j = j->next) {
                    if (i->data > j->data) {
                        T temp = i->data;
                        i->data = j->data;
                        j->data = temp;
                    }
                }
            }

        }
    
        void reverse() { // TO DO

            if ( empty() ) { throw std::runtime_error("Empty list!\n"); }

            Node<T> *next = nullptr;
            auto current = this->head;

             do {
                next = current->next;
                current->next = current->prev;
                current->prev = next;

                current = next;

            } while (current != this->head);

            current = this->head;
            this->head = this->tail;
            this->tail = current;

        }

        string name() { return "Circular Linked List"; }

        BidirectionalIterator<T> begin() { // TO DO
            return BidirectionalIterator<T>(this->head);
        }

	    BidirectionalIterator<T> end() { // TO DO
            return BidirectionalIterator<T>(this->head->prev);
        }

        void merge(CircularLinkedList<T> list) { // TO DO

            if ( list.empty() ) { return; }

            Node<T> *pNode = list.head;
            do {
                this->push_back( pNode->data );
                pNode = pNode->next;
            } while ( pNode != list.head );

        }
};

#endif