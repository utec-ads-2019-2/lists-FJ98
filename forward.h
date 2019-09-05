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
            if (empty()) { throw runtime_error("Empty list!\n"); }

            auto popNode = this->head;   // Podria ser : auto popNode = this->head->next; ?
            this->head = popNode->next;  // Podria ser : this->head->killSelf(); ?
            popNode->killSelf();         // Podria ser : this->head = popNode; ?

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
            popNode->killSelf(); // Podria ser keepNode->next->killSelf()?
            this->tail->next = nullptr;

//            Podria ser ?
//            this->tail->killSelf();
//            this->tail=keepNode;
//            this->tail->next=nullptr;

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

//            Podria ser solo esto: return this->nodes; ???
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

        string name() { return "Forward List"; }

        ForwardIterator<T> begin() {
            // TO DO
            return ForwardIterator<T>(this->head);
        }

	    ForwardIterator<T> end() {
            // TO DO
            return nullptr;
        }

        void merge(ForwardList<T> list) {
            // TO DO

        }
};

#endif