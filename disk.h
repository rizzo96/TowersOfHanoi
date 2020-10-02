// DISK CLASS that involves each and every single disk of the rod.
// FUNCTION DEFINITIONS FOR DISK CLASS

#ifndef DISK_H
#define DISK_H

#include <iostream>

class disk
{
public:
    disk(); // default constructor

    // Big 3:
    ~disk(); // destructor
    disk(const disk &other); // copy constructor
    disk& operator=(const disk &other); // assignment operator

    friend
    std::ostream& operator<<(std::ostream &out, const disk &d); // overloading insertion operator

    friend
    bool operator>(const disk &x, const disk &y); // operator for greater than

    friend
    bool operator<(const disk &x, const disk &y); // operator for less than

    int whoAmIvalue(); // return value for whoAmI

private:
    unsigned int whoAmI;
    static int lastIssued;
};

#endif // DISK_H
