/* Names: Mahamadsaad Sheikh and Rizwan Vazifdar
   Contribution: Mahamadsaad Sheikh: disk.h/disk.cpp and queue.h
                 Rizwan Vazifdar: board.h and stack.h
 */

#include <board.h>
#include <iostream>
#include <ctime> // to use clock()
using namespace std;

int main()
{
    int stackdisks = 0;
    int queuedisks = 0;

    cout << "Let's play Towers of Hanoi"<<endl;
    cout << "How many disks would you like for stacks version of this game? (Minimum 3)"<< endl;
    cin >> stackdisks;
   // cout << "How many disks would you like for a queue version of this game? (Minimum 3)"<< endl << endl;
   // cin >> queuedisks;


    // This is how you solve with stack

    int start_s = clock(); // this is used to time the executable time
    Board<disk, Stack<disk> > gameStack(stackdisks);
    gameStack.solve();
    int stop_s = clock(); // to the end of the program
    cout << endl;
    cout << "Executable time (in seconds): " << ((stop_s-start_s)/double(CLOCKS_PER_SEC)*1000) * 0.001 << endl;
    cout << endl;

    // -------------------------------------------------------------------------------------------

/*  This is how you solve with queue (partially works)
    int start = clock(); // this is used to time the executable time
    Board<disk, Queue<disk> > gameQueue(queuedisks);
    gameQueue.queueSolve();
    int stop = clock(); // to the end of the program
    cout << endl;
    cout << "Executable time (in seconds): " << ((stop-start)/double(CLOCKS_PER_SEC)*1000) * 0.001 << endl;
    cout << endl;
*/




}

/*
NOTES:
Stacks is more effecient because it took 0.153 seconds for 3 discs to happen in 7 moves.
Queues is a little bit slower.


OUTPUT:
Let's play Towers of Hanoi
How many disks would you like for stacks version of this game? (Minimum 3)
3
How many disks would you like for a queue version of this game? (Minimum 3)
3

Initial Rods:
Rod A:
Disk: 1
Disk: 2
Disk: 3


Rod B:


Rod C:



---------------------------------------
After 1 move:
Rod A:
Disk: 2
Disk: 3


Rod B:


Rod C:
Disk: 1



---------------------------------------
After 2 move:
Rod A:
Disk: 3


Rod B:
Disk: 2


Rod C:
Disk: 1



---------------------------------------
After 3 move:
Rod A:
Disk: 3


Rod B:
Disk: 1
Disk: 2


Rod C:



---------------------------------------
After 4 move:
Rod A:


Rod B:
Disk: 1
Disk: 2


Rod C:
Disk: 3



---------------------------------------
After 5 move:
Rod A:
Disk: 1


Rod B:
Disk: 2


Rod C:
Disk: 3



---------------------------------------
After 6 move:
Rod A:
Disk: 1


Rod B:


Rod C:
Disk: 2
Disk: 3



---------------------------------------
After 7 move:
Rod A:


Rod B:


Rod C:
Disk: 1
Disk: 2
Disk: 3



It took 7 moves to solve this game (:

Executable time (in seconds): 0.153

Press <RETURN> to close this window...

*/
