#include "Integer.h"

Integer::Integer(){}

Integer::Integer(int value)
{
    Element = value;
}

Integer::Integer(const Integer &obj)
{
    Element = obj.Element;
}

Integer::GetElement()
{
    return Element;
}

bool Integer::operator<(const Integer &obj)
{
    return (Element < obj.Element);
}
