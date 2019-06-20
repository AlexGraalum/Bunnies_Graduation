#include "bunny.h"

bunny::bunny()
{
    Setage(0);
    Setfur(static_cast<FurType>(rand()%SPOTTED));
    Setsex(static_cast<SexType>(rand()%FEMALE));

}

bunny::~bunny()
{
    //dtor
}

bunny::bunny(const bunny& other)
{
    //copy ctor
}

bunny& bunny::operator=(const bunny& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
