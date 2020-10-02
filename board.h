// BOARD CLASS that modifies the items in the rods.


#ifndef BOARD_H
#define BOARD_H
#include <stack.h>
#include <queue.h>
#include <disk.h>

template <typename T, typename QS>
class Board
{
public:
    Board(int size); // construtor
    void solve(); // solve for stacks
    void queueSolve(); //  solve for queues
    void printTowers(QS& rod1, QS& rod2, QS & rod3, int move); // prints all the rods
    void printTower(QS& rod1); // prints the first rod which this function will be used in "PrintTowers"
    void moveBetweenTowers(Stack<disk>& rod1, Stack<disk>& rod2); //  controls how to move between rods in STACKS
    void moveBetweenTowersQueue(Queue<disk>& rod1, Queue<disk>& rod2); // controls how to move between rods in QUEUES.

private:
    int theSize;
};

// constructor for the board that initializes the size.
template <typename T, typename QS>
Board<T, QS>::Board(int size)
{
    theSize = size;
}

// FUNCTION FOR STACKS. Creates only 3 rods. Disks can be however much the user wants.
//                     Each disk is inputted into the initial rod.
//                     The algorithm  for the even number of discs and odd number of discs is made.
//                     "Move" is a counter so each time a move is made, it increases the amount of moves
//                     A smaller item cannot be placed on top of a bigger item, but vice versa is mandatory.
template <typename T, typename QS>
void Board<T,QS>::solve()
{
    Stack<T> rod1(theSize);
    Stack<T> rod2(theSize);
    Stack<T> rod3(theSize);
    int move=0;

    disk disks[theSize];

    for(int i = theSize - 1; i >= 0; i--)
    {
        rod1.push(disks[i]);
    }

    printTowers(rod1, rod2, rod3, move);

    while (1)
    {
        /*
       make the legal move between pegs A and B (in either direction),
       make the legal move between pegs A and C (in either direction),
       make the legal move between pegs B and C (in either direction),
       repeat until complete.
       */
        if ((theSize %2) == 0) { // Even discs
            //make the legal move between pegs A and B (in either direction)
            moveBetweenTowers(rod1, rod2);
            move++;
            printTowers(rod1, rod2, rod3,  move);
            if ((rod1.size() <= 0) && (rod2.size() <= 0))
                break;

            //make the legal move between pegs A and C (in either direction)
            moveBetweenTowers(rod1, rod3);
            move++;
            printTowers(rod1, rod2, rod3, move);
            if ((rod1.size() <= 0) && (rod2.size() <= 0))
                break;

            //make the legal move between pegs B and C (in either direction)
            moveBetweenTowers(rod2,rod3);
            move++;
            printTowers(rod1, rod2, rod3, move);
            if ((rod1.size() <= 0) && (rod2.size() <= 0))
                break;

        }
        else
        { // Odd discs

            /*
         make the legal move between pegs A and C (in either direction),
         make the legal move between pegs A and B (in either direction),
         make the legal move between pegs B and C (in either direction),
         repeat until complete.
         */

            //make the legal move between pegs A and C (in either direction)
            moveBetweenTowers(rod1, rod3);
            move++;
            printTowers(rod1, rod2, rod3, move);
            if ((rod1.size() <= 0) && (rod2.size() <= 0))
                break;

            //make the legal move between pegs A and B (in either direction)
            moveBetweenTowers(rod1, rod2);
            move++;
            printTowers(rod1, rod2, rod3, move);
            if ((rod1.size() <= 0) && (rod2.size() <= 0))
                break;

            //make the legal move between pegs B and C (in either direction)
            moveBetweenTowers(rod2,rod3  );
            move++;
            printTowers(rod1, rod2, rod3, move);
            if ((rod1.size() <= 0) && (rod2.size() <= 0))
                break;
        }
    }
    cout << "It took " << move << " moves to solve this game (:" << endl;
}

// FUNCTION FOR QUEUE. Creates only 3 rods. Disks can be however much the user wants.
//                     Each disk is inputted into the initial rod.
//                     The algorithm  for the even number of discs and odd number of discs is made.
//                     "Move" is a counter so each time a move is made, it increases the amount of moves
//                     A smaller item cannot be placed on top of a bigger item, but vice versa is mandatory.
template <typename T, typename QS>
void Board<T,QS>::queueSolve()
{
    Queue<T> rod1(theSize);
    Queue<T> rod2(theSize);
    Queue<T> rod3(theSize);
    int move=0;

    disk disks[theSize];

    for(int i = 0; i < theSize; i++)
    {
        rod1.enqueue(disks[i]);
    }

    printTowers(rod1, rod2, rod3, move);
    while (1)
    {
        /*
       make the legal move between pegs A and B (in either direction),
       make the legal move between pegs A and C (in either direction),
       make the legal move between pegs B and C (in either direction),
       repeat until complete.
       */
        if ((theSize %2) == 0) { // Even discs
            //make the legal move between pegs A and B (in either direction)
            moveBetweenTowersQueue(rod1, rod2);
            move++;
            printTowers(rod1, rod2, rod3,  move);
            if ((rod1.size() <= 0) && (rod2.size() <= 0))
                break;

            //make the legal move between pegs A and C (in either direction)
            moveBetweenTowersQueue(rod1, rod3  );
            move++;
            printTowers(rod1, rod2, rod3, move);
            if ((rod1.size() <= 0) && (rod2.size() <= 0))
                break;

            //make the legal move between pegs B and C (in either direction)
            moveBetweenTowersQueue(rod2,rod3  );
            move++;
            printTowers(rod1, rod2, rod3, move);
            if ((rod1.size() <= 0) && (rod2.size() <= 0))
                break;

        }
        else
        { // Odd discs

            /*
         make the legal move between pegs A and C (in either direction),
         make the legal move between pegs A and B (in either direction),
         make the legal move between pegs B and C (in either direction),
         repeat until complete.
         */

            //make the legal move between pegs A and C (in either direction)
            moveBetweenTowersQueue(rod1, rod3);
            move++;
            printTowers(rod1, rod2, rod3, move);
            if ((rod1.size() <= 0) && (rod2.size() <= 0))
                break;

            //make the legal move between pegs A and B (in either direction)
            moveBetweenTowersQueue(rod1, rod2);
            move++;
            printTowers(rod1, rod2, rod3, move);
            if ((rod1.size() <= 0) && (rod2.size() <= 0))
                break;

            //make the legal move between pegs B and C (in either direction)
            moveBetweenTowersQueue(rod2,rod3);
            move++;
            printTowers(rod1, rod2, rod3, move);
            if ((rod1.size() <= 0) && (rod2.size() <= 0))
                break;
        }
    }


}

// This prints all the 3 RODS to display to the screen.
template <typename T, typename QS>
void Board<T,QS>::printTowers(QS& rod1, QS& rod2, QS& rod3, int move)
{
    if (!move)
        cout << "Initial Rods:  " << endl;
    else
    {
        cout << "---------------------------------------" << endl;
        cout << "After " << move << " move:  " << endl;
    }

    cout << "Rod A:  " << endl;
    printTower(rod1);
    cout << endl;

    cout << "Rod B:  " << endl;
    printTower(rod2);
    cout << endl;

    cout << "Rod C:  " << endl;
    printTower(rod3);
    cout << endl;
    cout << endl;

}

// This prints each rod INDIVIDUALLY which will be called in the "PrintTowers" function
template <typename T, typename QS>
void Board<T,QS>::printTower(QS& rod1)
{
    rod1.print();
}

// THIS FUNCTION for STACK allows the movement of items between each rod. it pushes and pops
//                when it is appropriate and prevents smaller items from going on top of bigger ones.
template <typename T, typename QS>
void Board<T,QS>::moveBetweenTowers(Stack<disk>& rod1, Stack<disk>& rod2)
{
    if ((rod1.size() > 0) && (!rod2.size()))
    { // Move from 1 to 2
        rod2.push(rod1.pop()); //
    }
    else if ((rod2.size() > 0) && (!rod1.size()))
    {           // Move from 2 to 1
        rod1.push(rod2.pop());
    }
    else if (rod2.peek() > rod1.peek())
    { // Move from 1 to 2
        rod2.push(rod1.pop());;
    }
    else
    {                                     // Move from 2 to 1
        rod1.push(rod2.pop());
    }
}

// THIS FUNCTION for Queues allows the movement of items between each rod. it enqueues and dequeues
//                when it is appropriate and prevents smaller items from going on top of bigger ones.
template <typename T, typename QS>
void Board<T,QS>::moveBetweenTowersQueue(Queue<disk>& rod1, Queue<disk>& rod2)
{
    if ((rod1.size() > 0) && (!rod2.size()))
    { // Move from 1 to 2
        rod2.enqueue(rod1.dequeue());
    }
    else if ((rod2.size() > 0) && (!rod1.size()))
    {           // Move from 2 to 1
        rod1.enqueue(rod2.dequeue());
    }
    else if (rod2.peek() > rod1.peek())
    { // Move from 1 to 2
        rod2.enqueue(rod1.dequeue());;
    }
    else
    {                                     // Move from 2 to 1
        rod1.enqueue(rod2.dequeue());
    }
}

#endif // BOARD_H
