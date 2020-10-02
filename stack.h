// STACK CLASS that uses linked lists which involves nodes.

#ifndef STACK_H
#define STACK_H
#include <node.h>
#include <disk.h>

#include <iostream>
#include <cstddef>
using namespace std;

enum BASESTACK_ERRORS{BASE_EMPTY, BASE_FULL, BAD_STACK_SIZE};

template <typename T>
class Stack
{
public:
    Stack();
    Stack(int cap);
    ~Stack();
    Stack(const Stack& obj);
    Stack<T>& operator= (const Stack& obj);

    void push(T x);
    T pop();
    int peek();
    bool empty();
    bool full();
    int capacity();
    int size();
    void print();
    void resize(size_t newSize);


private:
    Node<T> *top;
    int sizeValue;
    int capacityValue;
};

// DEFAULT CONSTRUCTOR. initializes top to NULL and cap and size to 0.
template<typename T>
Stack<T>::Stack()
{
    top = NULL;
    capacityValue = 0;
    sizeValue = 0;
}

// CONSTRUCTOR. same as default constructor AND resizes the stack as well with the capacity provided.
template<typename T>
Stack<T>::Stack(int cap)
{
    top = NULL;
    capacityValue = 0;
    sizeValue = 0;
    resize(cap);
}

// DESTRUCTOR. Makes the top of stack equal to null and all the sizes and capacity to 0 in order to "destroy everything".
template<typename T>
Stack<T>::~Stack()
{
    top = NULL;
    sizeValue = capacityValue = 0;
}

//COPY CONSTRUCTOR. it copies each and every variable.
template<typename T>
Stack<T>::Stack(const Stack& obj)
{
    sizeValue = obj.sizeValue;
    capacityValue = obj.capacityValue;
}

// ASSIGNMENT OPERATOR. if this is not equal to the object, then create duplicates and delete.
template<typename T>
Stack<T>& Stack<T>::operator= (const Stack& obj)
{
    if(this != &obj)
    {
        capacityValue = obj.capacityValue;
        sizeValue = obj.sizeValue;
    }
    return *this;
}

// MUTATOR FUNCTION. It adds to the top of the stack. If its full, throw an exception. Increase size
// each time a new item is inputted.
template<typename T>
void Stack<T>::push(T x)
{
    Node<T> *t = new Node<T>;
    if (full())
        throw BASE_FULL;

    t-> data = x;
    t->next=top;
    top = t;
    ++sizeValue;

}

// MUTATOR FUNCTION. Removes from the top of the stack as well. It decreases the size as well.
// all the elements stay intact because only the top is removed.
template<typename T>
T Stack<T>::pop()
{
    if (empty())
        throw BASE_EMPTY;


    T x;
    x = top->data;
    Node<T>*t = top;
    top=top->next;
    delete t; // deletes the top
    --sizeValue;

    return x;  // returns what ever was below that was deleted.
}

// GETTER FUNCTION. Looks at the top of the stack and returns that item. If empty, throw exception.
template<typename T>
int Stack<T>::peek()
{
    if (empty())
        throw BASE_EMPTY ;

    disk temp = top->data;
    return temp.whoAmIvalue();
}

// FUNCTION that checks if the stack is empty.
template<typename T>
bool Stack<T>::empty()
{
    return !top;

}

// FUNCTION that checks if stack is full with size and capacity being equal.
template<typename T>
bool Stack<T>::full()
{
    return sizeValue == capacityValue;

}

// GETTER FUNCTION that returns the value of the size.
template<typename T>
int Stack<T>::size()
{

    return sizeValue;
}

// GETTER FUNCTION that returns the value of the capacity.
template<typename T>
int Stack<T>::capacity()
{
    return capacityValue;
}

// Prints each and every item of the stack
template<typename T>
void Stack<T>::print()
{
    Node<T> *p = top;

    while(p != NULL)
    {
        cout << p->data << endl;
        p = p->next; // walks to the end of the linked list.
    }
    cout<<endl;
}

// The resize function used to create the stack to have a new size if the user chooses to.
// if it is empty and the newsize is higher than the capacity, then assign newsize to capacity.
template<typename T>
void Stack<T>::resize(size_t newSize)
{
    if(newSize < 1)
        throw BAD_STACK_SIZE;
    if(!top || newSize >= capacityValue)
        capacityValue = newSize;
    else
    {
        while(sizeValue > newSize)

            capacityValue = newSize;
    }
}


#endif // STACK_H
