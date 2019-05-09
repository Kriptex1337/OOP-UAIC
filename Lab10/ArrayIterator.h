#pragma once

template <typename T>
class ArrayIterator
{
private:
    T** Pointer;
    int Current;
public:
    ArrayIterator();
    ArrayIterator(T**, int);
    ArrayIterator<T>& operator++();
    ArrayIterator<T>& operator--();
    bool operator=(ArrayIterator<T>);
    bool operator!=(ArrayIterator<T>);
    T* GetElement();
};

template <typename T>
ArrayIterator<T>::ArrayIterator(){}

template <typename T>
ArrayIterator<T>::ArrayIterator(T** List, int index): Pointer(List), Current(index){}

template <typename T>
ArrayIterator<T>& ArrayIterator<T>::operator++()
{
    Pointer[Current]++;
    Current++;
    return *this;
}

template <typename T>
ArrayIterator<T>& ArrayIterator<T>::operator--()
{
    Pointer[Current]--;
    Current--;
    return *this;
}

template <typename T>
bool ArrayIterator<T>::operator=(ArrayIterator<T> obj)
{
    Pointer = obj.Pointer;
    Current = obj.Current;
    return true;
}

template <typename T>
bool ArrayIterator<T>::operator!=(ArrayIterator<T> obj)
{
    if (Current != obj.Current) return true;
    return false;
}

template <typename T>
T* ArrayIterator<T>::GetElement()
{
    return Pointer[Current];
}
