#include "Integer.h"

Integer::Integer() {}

Integer::Integer(int value) : el(value) {}

bool Integer::operator>(Integer obj)
{
    return el > obj.el;
}

int Integer::GetElement()
{
    return el;
}
