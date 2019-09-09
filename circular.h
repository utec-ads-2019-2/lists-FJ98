#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"

template <typename T>
class CircularLinkedList : public List<T> {
    public:
        CircularLinkedList() : List<T>() {}

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
                newNode->next = this->head;
                newNode->prev = this->tail;
            } else {
                this->head->prev = newNode;
                newNode->next = this->head;
                newNode->prev = this->tail;
                this->head = newNode;
                this->tail->next = newNode;
            }


        }

        void push_back(T value) {
            // TO DO
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

        void pop_front() {
            // TO DO
            if ( empty() ) { throw runtime_error("Empty list!"); }

            auto keepNode = this->head->next;

            this->head->killSelf();
            this->head = keepNode;
            this->head->prev = this->tail;
            this->tail->next = this->head;

//------------------------------------------------------------------------------
//            auto popNode = this->head;
//            this->head = this->head->next;
//            popNode->killSelf();
//            this->head->prev = this->tail;
//            this->tail->next = this->head;
//------------------------------------------------------------------------------

        }

        void pop_back() {
            // TO DO
            if ( empty() ) { throw runtime_error("Empty list!"); }

            auto keepNode = this->tail->prev;

            this->tail->killSelf();
            this->tail = keepNode;
            this->head->prev = this->tail;
            this->tail->next = this->head;

//------------------------------------------------------------------------------
//            auto popNode = this->tail;
//
//            this->tail = this->tail->prev;
//            popNode->killSelf();
//            this->tail->next = this->head;
//            this->head->prev = this->tail;
//------------------------------------------------------------------------------

        }

        T operator[](int index) {
            // TO DO
            if ( index < 0 ) throw std::runtime_error("Index should be zero or positive!\n");
            if ( index > size() - 1 ) throw std::runtime_error("Index is bigger than the list!\n");

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

        void clear() {
            // TO DO
            if ( empty() ) { throw runtime_error("Empty list!\n"); }

            for (auto p =  this->head; p->next != this->head; p = p->next) {
                p->killSelf();
            }

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

            if (startFirstHalf->next == this->head) { return startFirstHalf; } // base case to avoid infinite loop in the recursion

            auto endFirstHalf = startFirstHalf;
            auto startSecondHalf = startFirstHalf;
            auto endSecondHalf = startFirstHalf;

            while (endSecondHalf != nullptr && endSecondHalf->next != this->head) {
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
//            mergeSort(this->head);

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

            } while (current != this->head);

            current = this->head;
            this->head = this->tail;
            this->tail = current;

        }

        string name() {
            return "Circular Linked List";
        }

        BidirectionalIterator<T> begin() {
            // TO DO
            return BidirectionalIterator<T>(this->head);
        }

	    BidirectionalIterator<T> end() {
            // TO DO
            return BidirectionalIterator<T>(this->tail);
        }

        void merge(CircularLinkedList<T> list) {
            // TO DO
            Node<T> *pNode = list.head;
            do {
                push_back( pNode->data );
                pNode = pNode ->next;
            } while ( pNode != list.head );

//------------------------------------------------------------------------------
//            for (auto p = list.head; p->next != this->head; p = p->next) {
//                this->push_back(p->data);
//            }

//            for (int i = 0; i < list.size(); ++i) {
//                this->push_back(list[i]);
//            }

//            Node<T>* temp = list.head;
//
//            push_back(temp->data);
//            temp = temp ->next;
//
//            while (temp != list.head ){
//                push_back(temp->data);
//                temp = temp ->next;
//            }
//------------------------------------------------------------------------------

        }
};

#endif