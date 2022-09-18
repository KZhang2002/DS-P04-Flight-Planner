///Node header file
///Contains function prototypes and definitions.
///Created by Kenny Zhang

#ifndef INC_22S_FLIGHT_PLANNER_NODE_H
#define INC_22S_FLIGHT_PLANNER_NODE_H


template <typename t> class node {
private:
    node *prev = nullptr;
    node *next = nullptr;
    t data;
public:
    //constructors
    node();
    node(const node<t>& arg);
    explicit node(t val);
    ~node();

    //get functions
    t& getData() { return data; }
    node* &getNext() { return next; }
    node* &getPrev() { return prev; }

    //set functions
    void setData(t val) { data = val; }
    void setNext(node<t>* ptr) { next = ptr; }
    void setPrev(node<t>* ptr) { prev = ptr; }

    //operator overloads
    node& operator=(const node& arg);
};

//Constructors
template<typename t>
node<t>::node() = default;

template<typename t>
node<t>::node(const node<t> &arg) {
    data = arg.data;
    prev = arg.prev;
    next = arg.next;
}

template<typename t>
node<t>::node(t val) {
    data = val;
}

template<typename t>
node<t>::~node() = default;

//Operator Overloads
/**
 * Assigns arg's values to this
 * @tparam t
 * @param arg
 * @return
 */
template<typename t>
node<t>& node<t>::operator=(const node &arg) {
    if (this == arg) { return *this; }

    next = arg.next;
    prev = arg.prev;
    data = arg.data;

    return *this;
}

#endif //INC_22S_FLIGHT_PLANNER_NODE_H
