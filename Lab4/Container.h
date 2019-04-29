#pragma once

class Container
{
public:
    virtual bool Add(int) = 0;
    virtual bool Del(int) = 0;
    virtual int Count(int) = 0;
    virtual bool Exists(int) = 0;
    virtual int* GetSortedArray() = 0;
    virtual int GetCount() = 0;
};
