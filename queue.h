// PRIORITY QUEUE class which is array based. Enqueues and Dequeues items.

#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <cstdlib>

enum QUEUE_ERRORS {Q_FULL, Q_EMPTY, Q_BAD_SIZE};

template<typename T>
class Queue
{
   public:
      Queue(size_t s = 10); // constructor
     ~Queue(); // destructor
      Queue(const Queue<T>& other); // copy constructor
      Queue<T>& operator=(const Queue<T>& other); // assignment operator

      bool empty(); // checks if empty
      bool full(); // checks if full
      size_t size(); // returns size
      size_t capacity(); // returns cap
      T peek(); // looks at the front
      void enqueue(T data); // adds into queue
      T dequeue(); // removes from queue
      Queue<T>& operator<<(const T& data); //enqueue
      Queue<T>& operator>>(T &data);// dequeue


      void print(); // prints each item of queue


   private:
      size_t head, tail, mySize, myCapacity;
      int priority;
      T *queue;

      void copy(const Queue<T>& other); // copying each variable. used in copy constructor
      void deleteAll(); // deleting each item in the queue. used in destructor
};

// CONSTRUCTOR. initializing variables to 0. also creates new queue so it isn't empty.
template<typename T>
Queue<T>::Queue(size_t s)
{
    if(s < 2)
        throw Q_BAD_SIZE;
    head = tail = mySize = 0;
    queue = new T[myCapacity = s];
}

// DESTRUCTOR. calls the function "DeleteALL()"
template<typename T>
Queue<T>::~Queue()
{
    deleteAll();
}

// COPY CONSTRUCTOR. calls the copy() function.
template<typename T>
Queue<T>::Queue(const Queue<T>& other)
{
    copy(other);
}

// ASSIGNMENT OPERATOR. first deletes all the variables and then copies if "this" isn't equal to the other.
template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
    if(this != &other)
    {
        deleteAll();
        copy(other);
    }
    return *this;
}

// Checks if the queue is empty by head being equal to tail.
template<typename T>
bool Queue<T>::empty()
{
   return head == tail;
}

// Checks if the queue is empty by size being equal to capacity.
template<typename T>
bool Queue<T>::full()
{
    return mySize == myCapacity;
}

// ACCESSOR FUNCTION. Returns the size of the queue.
template<typename T>
size_t Queue<T>::size()
{
    return mySize;
}

// ACCESSOR FUNCTION. Returns the capacity of the queue.
template<typename T>
size_t Queue<T>::capacity()
{
    return myCapacity;
}

// ACCESSOR FUNCTION. Returns the front of the queue.
template<typename T>
T Queue<T>::peek()
{
    return queue[head];
}

// MUTATOR FUNCTION. Adding data to the end of the queue. If its empty, increase the size to 1 and start from there
                     // this is used to check priority . If the priority is lower, then the items will get shifted to the left
                     // and then added to the appropriate location
                     // size is always being incremented each time
template<typename T>
void Queue<T>::enqueue(T data)
{
   if(full())
       throw Q_FULL;

      int check = 0;
      T temp;

            priority = data.whoAmIvalue();
            if(empty())
    {
            queue[0] = data;
            mySize++;
            tail++;
            return;
}

            for(int i = 0; i <= mySize; i++)
    {

        if(i == mySize)
        {
            queue[i] = data;
            mySize++;
            tail++;
            return;
        }

        check = queue[i].whoAmIvalue();

        if(priority < check)
        {

            for (int j = tail; j >= i ; j--)
            {
                queue[j+1] = queue[j];
            }

            queue[i] = data;

            mySize++;
            tail++;
            return;
        }
    }



}

// MUTATOR FUNCTION. Removes the head of the queue and shifts to the left.
template<typename T>
T Queue<T>::dequeue()
{
    if(empty())
        throw Q_EMPTY;

    T data = queue[head];

    head = (head + 1)%(myCapacity + 1); // shifting to right
    mySize--;

    return data;
}

// OVERLOADED insertion operator used for enqueue.
template<typename T>
Queue<T>& Queue<T>::operator<<(const T& data)
{
    enqueue(data);
    return *this;
}

// OVERLOADED insertion operator used for dequeue.
template<typename T>
Queue<T>& Queue<T>::operator>>(T &data)
{
    dequeue(data);
    return *this;
}

// COPY FUNCTION USED FOR COPY CONSTRUCTOR. All it does is copies each variable and the items and makes duplicates
template<typename T>
void Queue<T>::copy(const Queue<T>& other)
{
    mySize = other.mySize;
    queue = new T[myCapacity = other.myCapacity];
    head = other.head;
    tail = other.tail;
    for(size_t i = head; i != tail; i = ++i%myCapacity )
            queue[i] = other.queue[i];
}

// DELETE FUNCTION USED FOR DESTRUCTOR. Deletes each and every item in the queue. Basically 'nukes'.
template<typename T>
void Queue<T>::deleteAll()
{
     for(size_t i = 0; i < myCapacity;++i)
         queue[i] = T();
     mySize = myCapacity = head = tail = 0;
     delete [] queue;
}

// Prints each item of the queue since it is array based.
template<typename T>
void Queue<T>::print()
{
    for (int i = head+1; i<=tail; i++)
    {
        cout << queue[i]<<endl;
    }
}

#endif // QUEUE_H
