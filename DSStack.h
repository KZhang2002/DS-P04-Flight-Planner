///Stack header file
///Contains function prototypes and definitions.
///Created by Kenny Zhang

#ifndef INC_22S_FLIGHT_PLANNER_DSSTACK_H
#define INC_22S_FLIGHT_PLANNER_DSSTACK_H

#include "DSLinkedList.h"
#include "port.h"
#include "DSString.h"

template <typename t> class DSStack {
private:
    DSLinkedList<t> *stack = new DSLinkedList<t>;
    bool isEmpty;
    int size;

public:
    //Constructors
    DSStack();
    DSStack(DSStack &arg);
    DSStack(DSLinkedList<t> list);
    ~DSStack();

    //Stack Modifiers
    void push(t& val);
    void pop();
    void swap();
    void clear();

    //Status Checkers
    t& top() { return stack->getTail()->getData(); }
    bool checkEmpty() { if (size == 0) { isEmpty = true; } return isEmpty; }
    int getSize(){ return size; }
    DSLinkedList<t>& getStack() { return *stack; }
};

//Constructors
template<typename t>
DSStack<t>::DSStack() {
    size = 0;
    isEmpty = true;
}

template<typename t>
DSStack<t>::DSStack(DSStack &arg) {
    if (arg.isEmpty()) {
        size = 0;
        isEmpty = true;
        return;
    } else {
        size = arg.size;
        isEmpty = arg.isEmpty;
        for (int i = 0; i < arg.size(); i++) {
            stack->push_front(arg.top());
            arg.pop();
        }
    }
}

template<typename t>
DSStack<t>::DSStack(DSLinkedList<t> list) {
    if (list.getNumMembers() == 0) isEmpty = true; else isEmpty = false;
    stack = list;
    size = list.getNumMembers();
}

template<typename t>
DSStack<t>::~DSStack() {
    delete stack;
}

//Stack Modifiers
/**
 * Pushes "val" to the top of the stack
 * @tparam t
 * @param val
 */
template<typename t>
void DSStack<t>::push(t& val) {
    if (size == 0) { isEmpty = false; }
    stack->push_back(val);
    size++;
}

/**
 * Pops the top of the stack.
 * @tparam t
 */
template<typename t>
void DSStack<t>::pop() {
    if (size == 0) { isEmpty = true; }
    stack->pop_back();
    size--;
}

/**
 * Clears the stack.
 * @tparam t
 */
template<typename t>
void DSStack<t>::clear() {
    for (int i = size; i > 0; i--) {
        pop();
    }
    isEmpty = true;
}


#endif //INC_22S_FLIGHT_PLANNER_DSSTACK_H
