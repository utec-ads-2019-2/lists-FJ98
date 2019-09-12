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
            } else {
                this->head->prev = newNode;
                newNode->next = this->head;
                this->head = newNode;
                newNode->prev = nullptr;
            }

        }

        void push_back(T value) {
            // TO DO
            auto newNode = new Node<T>{value, nullptr, nullptr};
            if ( empty() ) {
                this->head = newNode;
                this->tail = newNode;
                newNode->next = nullptr;
                newNode->prev = nullptr;
            } else {
                this->tail->next = newNode;
                newNode->prev = this->tail;
                this->tail = newNode;
                newNode->next = nullptr;
            }
        }

        void pop_front() {
            // TO DO
            if ( empty() ) { throw runtime_error("Empty list!"); }

            auto popNode = this->head;

            this->head = this->head->next;
            delete popNode;
            this->head->prev = nullptr;
        }

        void pop_back() {
            // TO DO
            if ( empty() ) { throw runtime_error("Empty list!"); }

            auto keepNode = this->tail->prev;

            delete this->tail;
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

            for (auto pNode = this->head; pNode != nullptr ; pNode = pNode->next) {
                ++counter;
            }

            return counter;
        }

        void clear() {
            // TO DO
            this->head->killSelf();
            this->tail = nullptr;
            this->head = nullptr;
        }

        Node<T> *doMerge(Node<T> *leftSide, Node<T> *rightSide) {

            auto sortedTmp = new Node<T>{0, nullptr, nullptr};

            while (leftSide != nullptr && rightSide != nullptr) {
                if (leftSide->data < rightSide->data) {
                    sortedTmp->next = leftSide;
                    leftSide = leftSide->next;
                } else {
                    sortedTmp->next = rightSide;
                    rightSide = rightSide->next;
                }
                sortedTmp = sortedTmp->next;
            }

            while (leftSide != nullptr) {
                sortedTmp->next = leftSide;
                leftSide = leftSide->next;
            }

            while (rightSide != nullptr) {
                sortedTmp->next = rightSide;
                rightSide = rightSide->next;
            }

            return sortedTmp->next;
        }

        Node<T> *mergeSort(Node<T> *startFirstHalf) {

            if (startFirstHalf->next == nullptr) { return startFirstHalf; } // base case to avoid infinite loop in the recursion

            auto endFirstHalf = startFirstHalf;
            auto startSecondHalf = startFirstHalf;
            auto endSecondHalf = startFirstHalf;

            while (endSecondHalf != nullptr && endSecondHalf->next != nullptr) {
                endFirstHalf = startSecondHalf;
                startSecondHalf = startSecondHalf->next;
                endSecondHalf = endSecondHalf->next->next;
            }

            endFirstHalf->next = nullptr;

            auto leftSide = mergeSort(startFirstHalf);
            auto rightSide = mergeSort(startSecondHalf);

            return doMerge(leftSide, rightSide);

        }

        void sort() {
            // TO DO
            if ( empty() || this->head->next == nullptr) { throw std::runtime_error("List already sorted!"); }
            mergeSort(this->head);
        }
    
        void reverse() {
            // TO DO
            if ( empty() ) { throw std::runtime_error("Empty list!\n"); }

            Node<T> *next = nullptr;
            auto current = this->head;

            do {
                next = current->next;
                current->next = current->prev;
                current->prev = next;

                current = next;

            } while (current != nullptr);

            current = this->head;
            this->head = this->tail;
            this->tail = current;

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
            return BidirectionalIterator<T>(nullptr);
        }

        void merge(LinkedList<T> list) {
            // TO DO

            Node<T> *pNode = list.head;
            while ( pNode != nullptr ) {
                push_back( pNode->data );
                pNode = pNode ->next;
            }

//------------------------------------------------------------------------------
//            for (auto p = list.head; p != nullptr; p = p->next) {
//                this->push_back(p->data);
//            }

//            auto tmpNode = list.head;
//            do {
//                this->push_back(tmpNode->data);
//                tmpNode = tmpNode->next;
//            } while (tmpNode != nullptr);
//------------------------------------------------------------------------------

        }
};

#endif