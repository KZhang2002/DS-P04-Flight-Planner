///DSLinkedList header file
///Contains function prototypes and definitions.
///Created by Kenny Zhang

#ifndef INC_22S_FLIGHT_PLANNER_DSLINKEDLIST_H
#define INC_22S_FLIGHT_PLANNER_DSLINKEDLIST_H

#include <iostream>
#include <ostream>
#include <istream>
#include "node.h"

//Namespace declarations
using std::ostream;
using std::cout;
using std::endl;

template <typename t> class DSLinkedList {
private:
    //nodes
    node<t> *head = nullptr;
    node<t> *tail = nullptr;
    node<t> *iterator = nullptr;

    //list details
    int numMembers = 0; //Does not include head and tail node
    bool isEmpty;

public:
    //constructors
    DSLinkedList();
    DSLinkedList(const DSLinkedList<t>& arg);
    DSLinkedList(t* arr, int size);
    ~DSLinkedList();

    //get functions
    node<t> *getHead() { return head; }
    node<t> *getTail() { return tail; }
    int getNumMembers() { return numMembers; }

    //set functions
    void setHead(node<t> arg) { head = *arg; }
    void setTail(node<t> arg) { tail = *arg; }
    void setIterator(node<t>* arg) { iterator = arg; }
    void setNumMembers(int num) { numMembers = num; } //not sure why you would ever need to use this

    //iterator getters
    node<t> *getIterator() { return iterator; }
    t *getItrData() { return iterator->getData(); }
    node<t> *getItrNext() { return iterator->getNext(); }
    node<t> *getItrPrev() { return iterator->getPrev(); }
    node<t> *at(int index);

    //iterator functions
    void resetIterator() { iterator = head; }
    void incrementIterator();
    void decrementIterator();
    void printAll();
    void printIterator();

    //operator overloads
    node<t>& operator[](int index);
    DSLinkedList& operator=(const DSLinkedList& arg);


    ///LIST FUNCTIONS

    //List modifiers
    t pop_front();
    t pop_back();
    t pop_at(int index);
    void push_front(t data);
    void push_back(const t& data);
    void push_at(t data, int index);
    void swap(int index1, int index2);

    //List getters
    t get_front();
    t get_back();
    t &get_at(int index);
};

//Constructors
template<typename t>
DSLinkedList<t>::DSLinkedList() {
    head = nullptr;
    tail = nullptr;
    iterator = head;
    numMembers = 0;
    isEmpty = true;
}

template<typename t>
DSLinkedList<t>::DSLinkedList(const DSLinkedList<t>& arg) {
    isEmpty = arg.isEmpty;
    iterator = arg.head;
    numMembers = 0;

    for (int i = 0; i < arg.numMembers; i++) {
        push_back(iterator->getData());
        incrementIterator();
    }

    resetIterator();
}

template<typename t>
DSLinkedList<t>::DSLinkedList(t *arr, int size) {
    if (size == 0) {
        head = nullptr;
        tail = nullptr;
        numMembers = 0;
        isEmpty = true;
        return;
    }

    for (int i = 0; i < size; i++) {
        this->push_back(arr[i]);
    }

    iterator = head;
}

template<typename t>
DSLinkedList<t>::~DSLinkedList() {
    resetIterator();
    for (int i = 0; i < numMembers; i++) {
        node<t> *temp = iterator->getNext();
        delete iterator;
        iterator = temp;
    }

    head = nullptr;
    tail = nullptr;
    iterator = nullptr;
}

//Iterator Getters
template<typename t>
void DSLinkedList<t>::incrementIterator() {
    if (iterator == tail) {
        return;
    } else {
        iterator = iterator->getNext();
    }
}

template<typename t>
void DSLinkedList<t>::decrementIterator() {
    if (iterator == head) {
        return;
    } else {
        iterator = iterator->getPrev();
    }
}

template<typename t>
node<t> *DSLinkedList<t>::at(int index) {
    node<t> *temp = iterator;
    for (int i = 0; i < index; i++) {
        temp = temp->getNext();
    }
    return temp;
}

//Iterator Functions
/**
 * Prints all elements in list. Use for debugging.
 * @tparam t
 */
template<typename t>
void DSLinkedList<t>::printAll() {
    resetIterator();

    for (int i = 0; i < numMembers ; i++) {
        cout << i << ": ";
        printIterator();
        cout << endl;
        incrementIterator();
    }

    resetIterator();
}
/**
 * Prints element, iterator points to. Use for debugging.
 * @tparam t
 */
template<typename t>
void DSLinkedList<t>::printIterator() {
    cout << iterator->getData();
}

//Operator Overloads
/**
 * Returns nth element of list, where n = index.
 * @tparam t
 * @param index
 * @return
 */
template<typename t>
node<t>& DSLinkedList<t>::operator[](int index) {
    resetIterator();
    for (int i = 0; i < index; i++) { incrementIterator(); }
    return iterator;
}

/**
 * Assigns arg to this.
 * @tparam t
 * @param arg
 * @return
 */
template<typename t>
DSLinkedList<t>& DSLinkedList<t>::operator=(const DSLinkedList<t> &arg) {
    //if (this == arg) { return *this; }
    numMembers = 0;
    iterator = arg.head;

    for (int i = arg.numMembers; i < arg.numMembers; i++) {
        this->push_back(iterator->getData());
        incrementIterator();
    }

    resetIterator();
    return *this;
}

//List Modifiers
/**
 * Pops the front element of the list.
 * @tparam t
 * @return
 */
template<typename t>
t DSLinkedList<t>::pop_front() {
    t tempVal = head->getData();
    numMembers--;

    if (numMembers == 0) {
        delete tail;
        head = nullptr;
        tail = nullptr;
        iterator = head;
    } else {
        head = head->getNext();
        delete head->getPrev();
        head->setPrev(nullptr);
    }

    return tempVal;
}

/**
 * Pops the last element of the list.
 * @tparam t
 * @return
 */
template<typename t>
t DSLinkedList<t>::pop_back() {
    /*node<t> *temp = iterator->getNext();
    delete iterator;
    iterator = temp;*/

    t tempVal = tail->getData();
    numMembers--;

    if (numMembers == 0) {
        delete tail;
        head = nullptr;
        tail = nullptr;
        iterator = head;
    } else {
        node<t>* temp = tail;
        tail = tail->getPrev();
        delete temp;
        tail->setNext(nullptr);
    }

    return tempVal;
}

/**
 * Pops element at num index
 * @tparam t
 * @param index
 * @return
 */
template<typename t>
t DSLinkedList<t>::pop_at(int index) {
    node<t> *temp = at(index);
    t tempVal = temp->getData();

    temp->getPrev()->setNext(temp->getNext());
    temp->getNext()->setPrev(temp->getPrev());
    delete temp;
    numMembers--;

    return tempVal;
}

/**
 * Pushes "data" to the front of the list.
 * @tparam t
 * @param data
 */
template<typename t>
void DSLinkedList<t>::push_front(t data) {
    node<t> *temp = new node<t>(data);
    if (numMembers == 0) {
        head = temp;
        tail = temp;
        iterator = head;
        isEmpty = false;
    } else {
        head->setPrev(temp);
        temp->setNext(head);
        head = temp;
    }
    numMembers++;
}

/**
 * Pushes "data" to the back of the list.
 * @tparam t
 * @param data
 */
template<typename t>
void DSLinkedList<t>::push_back(const t& data) {
    node<t> *temp = new node<t>(data);
    if (numMembers == 0) {
        head = temp;
        tail = temp;
        iterator = head;
        isEmpty = false;
    } else {
        tail->setNext(temp);
        temp->setPrev(tail);
        tail = temp;
    }
    numMembers++;
}

/**
 * Pushes "data" to index "index" of the list.
 * @tparam t
 * @param data
 * @param index
 */
template<typename t>
void DSLinkedList<t>::push_at(t data, int index) {
    node<t> *temp = new node<t>(data);
    if (numMembers == 0) {
        head = temp;
        tail = temp;
        iterator = head;
    } else if (index == 0) {
        push_front(data);
    } else if (index == numMembers) {
        push_back(data);
    } else {
        node<t> *nodePtr = at(index);
        temp->setNext(nodePtr);
        temp->setPrev(nodePtr->getPrev());
        nodePtr->setPrev(temp);
        temp->getPrev()->setNext(temp);
    }
    numMembers++;
}

/**
 * Swaps elements at indexes "index1" and "index2"
 * @tparam t
 * @param index1
 * @param index2
 */
template<typename t>
void DSLinkedList<t>::swap(int index1, int index2) {
    if (index2 == index1 || at(index1) == nullptr || at(index1)->getNext() == nullptr) return;

    node<t> *n1 = at(index1);
    node<t> *n2 = at(index2);
    node<t> *temp;

    temp = n1->getNext();
    n1->getNext() = n2->getNext();
    n2->getNext() = temp;

    if (n1->getNext() != nullptr) n1->getNext()->getPrev() = n1;
    if (n2->getNext() != nullptr) n2->getNext()->getPrev() = n2;

    temp = n1->getPrev();
    n1->getPrev() = n2->getPrev();
    n2->getPrev() = temp;

    if (n1->getPrev() != nullptr) n1->getPrev()->getNext() = n1;
    if (n2->getPrev() != nullptr) n2->getPrev()->getNext() = n2;

    if (head == n1) { head = n2; }
    else if (head == n2) { head = n1; }

    if (tail == n1) { tail = n2; }
    else if (tail == n2) { tail = n1; }
    /*head = at(0);
    tail = at(numMembers);*/

    iterator = head;
}

//List Getters
template<typename t>
t DSLinkedList<t>::get_front() {
    return head->getData();
}

template<typename t>
t DSLinkedList<t>::get_back() {
    return tail->getData();
}

template<typename t>
t &DSLinkedList<t>::get_at(int index) {
    return at(index)->getData();
}

#endif //INC_22S_FLIGHT_PLANNER_DSLINKEDLIST_H
