// STRUCT for NODE (Linked-List) that will be used for Stacks

#ifndef NODE_H
#define NODE_H


template <typename T>
struct Node
{
    Node(); // constructor
    T data; // data
    Node *next; // link
};

template <typename T>
Node<T>::Node()
{

}

#endif // NODE_H
