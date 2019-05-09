#pragma once
#include "Compare.h"

template <typename T>
class Comparator2 : public Compare
{
public:
    int CompareElements(void*, void*);
};

template <typename T>
int Comparator2<T>::CompareElements(void* e1, void* e2)
{
    return ((*(T*)e1 == *(T*)e2) ? (1) : (0));
}
