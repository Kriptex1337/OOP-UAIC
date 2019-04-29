#pragma once
#include "Container.h"
#include "LLNode.h"

class SimpleLinkedList : public Container
{
    LLNode * Root;
    int Length;
public:
    SimpleLinkedList();
    bool Add(int);
    bool Del(int);
    int Count(int);
    bool Exists(int);
    int* GetSortedArray();
    int GetCount();
};
