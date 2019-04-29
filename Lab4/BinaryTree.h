#pragma once
#include "Container.h"
#include "BTNode.h"

class BinaryTree : public Container
{
    BTNode * Root;
    int Length;
public:
    BinaryTree();
    bool Add(int);
    bool Del(int);
    int Count(int);
    bool Exists(int);
    int* GetSortedArray();
    int GetCount();
};
