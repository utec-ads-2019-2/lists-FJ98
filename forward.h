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

            for (auto pNode = this->head; pNode != nullptr ; pNode = pNode->next) {
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

//-------------------------------------------------------------------------------------------------
//            int swapped;
//            Node<T> *pNode, *lptr = nullptr;
//            do{
//                swapped = 0;
//
//                for (pNode = this->head; pNode->next != lptr; pNode = pNode->next) {
//                    if (pNode->data > pNode->next->data) {
//                        std::swap(pNode->data, pNode->next->data);
//                        swapped = 1;
//                    }
//                }
//                lptr = pNode;
//            } while (swapped);
//--------------------------------------------------------------------------------------------------

        }
    
        void reverse() {
            // TO DO
            if ( empty() ) { throw runtime_error("Empty list!\n"); }

            Node<T> *previous = nullptr;
            auto current = this->head;
            Node<T> *next = nullptr;

             do {
                next = current->next;
                current->next  = previous;
                previous = current;
                current = next;
            } while (current != nullptr);

            current = this->head;
            this->head = this->tail;
            this->tail = current;

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
            Node<T> *pNode = list.head;
            do {
                push_back( pNode->data );
                pNode = pNode ->next;
            } while ( pNode != nullptr );

//-------------------------------------------------------------------------
//            for (auto p = list.head; p != nullptr; p = p->next) {
//                this->push_back(p->data);
//            }

//            for (int i = 0; i < list.size(); ++i) {
//                this->push_back(list[i]);
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