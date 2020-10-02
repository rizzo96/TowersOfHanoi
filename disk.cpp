// FUNCTION IMPLEMENTATIONS FOR DISK CLASS

#include "disk.h"

#include <iostream>

int disk::lastIssued = -1;

// DEFAULT CONSTRUCTOR. WhoAMI is initialized to lastIssued plus one.
disk::disk()
{
    whoAmI = ++lastIssued;
}

// DESTRUCTOR. Lastissued is decremented
disk::~disk()
{
    --lastIssued;
}

// COPY CONSTRUCTOR. Creates duplicates for each variable
disk::disk(const disk &other)
{
    whoAmI = other.whoAmI;
}

// ASSIGNMENT Operator. Creates copies of the variable if "this" is not equal to the object
disk& disk::operator=(const disk &other)
{
    if(this != &other)
        whoAmI = other.whoAmI;
    return *this;
}

// OVERLOADING INSERTION OPERATOR that displays the DISKS inside the rods
std::ostream& operator<<(std::ostream &out, const disk &d)
{
    out<<"Disk: "<<d.whoAmI+1<<" ";
    return out;
}

// OVERLOADING OPERATOR COMPARING LEFT HAND SIDE if greater than RIGHT HAND SIDE
bool operator >(const disk &x, const disk &y)
{
    if ((x.whoAmI > y.whoAmI) && (x.lastIssued > y.lastIssued))
        return true;

    return false;
}

// OVERLOADING OPERATOR COMPARING LEFT HAND SIDE if lesser than RIGHT HAND SIDE
bool operator <(const disk &x, const disk &y)
{
    if ((x.whoAmI < y.whoAmI) && (x.lastIssued < y.lastIssued))
        return true;

    return false;
}

// ACCESSOR FUNCTION THAT ACCESS THE "WHOAMI" variable since it is private.
int disk::whoAmIvalue()
{
    return whoAmI;
}
