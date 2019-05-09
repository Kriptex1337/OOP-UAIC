#pragma once
#include "Exceptions.h"
#include "Comparator1.h"
#include "Comparator2.h"
#include "ArrayIterator.h"

template <typename T>
class Array
{
private:
    T** List;
    int Capacity;
    int Size;
public:
    Array();
    ~Array();
    Array(int);
    Array(const Array<T>&);
    T& operator[](int) const;
    const Array<T>& operator+=(const T&);
    const Array<T>& Insert(int, const T&);
    const Array<T>& Insert(int, const Array<T>);
    const Array<T>& Delete(int);
    bool operator=(const Array<T>&);
    void Sort();
    void Sort(int(*compare)(const T&, const T&));
    void Sort(Compare*);
    int BinarySearch(const T&);
    int BinarySearch(const T&, int(*compare)(const T&, const T&));
    int BinarySearch(const T&, Compare*);
    int Find(const T&);
    int Find(const T&, int(*compare)(const T&, const T&));
    int Find(const T&, Compare*);
    int GetSize() const;
    int GetCapacity() const;
    ArrayIterator<T> GetBeginIterator();
    ArrayIterator<T> GetEndIterator();
};

template <typename T>
Array<T>::Array() : Capacity(0), Size(0) {}

template <typename T>
Array<T>::~Array()
{
    for (int i = 0; i < Size; i++) delete List[i];
    delete[] List;
}

template <typename T>
Array<T>::Array(int capacity) : Capacity(capacity), Size(0)
{
    List = new T*[Capacity];
}

template <typename T>
Array<T>::Array(const Array<T> &otherArray) : Capacity(otherArray.Capacity), Size(otherArray.Size)
{
    List = new T*[Capacity];
    for (int i = 0; i < Size; i++)
    {
        List[i] = new T;
        *List[i] = *otherArray.List[i];
    }
}

template <typename T>
T& Array<T>::operator[](int index) const
{
    try
    {
        if (index < 0 || index >= Size) throw OutOfRange();
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
        T *exObj = new T;
        return *exObj;
    }
    return *List[index];
}

template <typename T>
const Array<T>& Array<T>::operator+=(const T &newElem)
{
    if (Size + 1 > Capacity)
    {
        if (!Capacity) Capacity = 100;
        else Capacity *= 2;
        T** copyList = new T*[Capacity];
        for (int i = 0; i < Size; i++)
        {
            copyList[i] = new T;
            *copyList[i] = *List[i];
        }
        for (int i = 0; i < Size; i++) delete List[i];
        delete[] List;
        List = copyList;
    }
    List[Size] = new T;
    *List[Size++] = newElem;
    return *this;
}

template <typename T>
const Array<T>& Array<T>::Insert(int index, const T &newElem)
{
    try
    {
        if (index < 0 || index >= Size) throw OutOfRange();
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
        Array<T> *exObj = new Array<T>;
        return *exObj;
    }
    if (Size + 1 > Capacity)
    {
        if (!Capacity) Capacity = 100;
        else Capacity *= 2;
        T** copyList = new T*[Capacity];
        for (int i = 0; i < Size; i++)
        {
            copyList[i] = new T;
            *copyList[i] = *List[i];
        }
        for (int i = 0; i < Size; i++) delete List[i];
        delete[] List;
        List = copyList;
    }
    List[Size] = new T;
    for (int i = Size - 1; i >= index; i--) *List[i + 1] = *List[i];
    *List[index] = newElem;
    Size++;
    return *this;
}

template <typename T>
const Array<T>& Array<T>::Insert(int index, const Array<T> otherArray)
{
    try
    {
        if (index < 0 || index >= Size) throw OutOfRange();
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
        Array<T> *exObj = new Array<T>;
        return *exObj;
    }
    if (Size + otherArray.GetSize() > Capacity)
    {
        if (!Capacity) Capacity = Size + otherArray.GetSize();
        else Capacity = 2 * (Size + otherArray.GetSize());
        T** copyList = new T*[Capacity];
        for (int i = 0; i < Size; i++)
        {
            copyList[i] = new T;
            *copyList[i] = *List[i];
        }
        for (int i = 0; i < Size; i++) delete List[i];
        delete[] List;
        List = copyList;
    }
    for (int i = Size; i < Size + otherArray.GetSize(); i++) List[i] = new T;
    for (int i = Size - 1; i >= index; i--) *List[i + otherArray.GetSize()] = *List[i];
    for (int i = 0; i < otherArray.GetSize(); i++) *List[i + index] = otherArray[i];
    Size += otherArray.GetSize();
    return *this;
}

template <typename T>
const Array<T>& Array<T>::Delete(int index)
{
    try
    {
        if (index < 0 || index >= Size) throw OutOfRange();
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
        Array<T> *exObj = new Array<T>;
        return *exObj;
    }
    for (int i = index; i < Size - 1; i++) *List[i] = *List[i + 1];
    delete List[Size - 1];
    Size--;
    return *this;
}

template <typename T>
bool Array<T>::operator=(const Array<T> &otherArray)
{
    Size = otherArray.GetSize();
    Capacity = otherArray.GetCapacity();
    List = new T*[Capacity];
    for (int i = 0; i < Size; i++)
    {
        List[i] = new T;
        *List[i] = otherArray[i];
    }
    return true;
}

template <typename T>
void Array<T>::Sort()
{
    T aux;
    for (int i = 0; i < Size - 1; i++)
        for (int j = i + 1; j < Size; j++)
            if (*List[j] < *List[i])
            {
                aux = *List[i];
                *List[i] = *List[j];
                *List[j] = aux;
            }
}

template <typename T>
void Array<T>::Sort(int(*compare)(const T&, const T&))
{
    T aux;
    for (int i = 0; i < Size - 1; i++)
        for (int j = i + 1; j < Size; j++)
            if (compare(*List[j], *List[i]))
            {
                aux = *List[i];
                *List[i] = *List[j];
                *List[j] = aux;
            }
}

template <typename T>
void Array<T>::Sort(Compare *comparator)
{
    comparator = new Comparator1<T>;
    T aux;
    for (int i = 0; i < Size - 1; i++)
        for (int j = i + 1; j < Size; j++)
            if (comparator->CompareElements(List[j], List[i]))
            {
                aux = *List[i];
                *List[i] = *List[j];
                *List[j] = aux;
            }
}

template <typename T>
int Array<T>::BinarySearch(const T& elem)
{
    int left, right, middle;
    left = 0;
    right = Size - 1;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (*List[middle] == elem)
            return middle;
        else if (elem < *List[middle]) right = middle - 1;
        else if (elem > *List[middle]) left = middle + 1;
    }
    return -1;
}

template <typename T>
int Array<T>::BinarySearch(const T& elem, int(*compare)(const T&, const T&))
{
    int left, right, middle;
    left = 0;
    right = Size - 1;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (*List[middle] == elem)
            return middle;
        else if (compare(elem, *List[middle])) right = middle - 1;
        else if (compare(*List[middle], elem)) left = middle + 1;
    }
    return -1;
}

template <typename T>
int Array<T>::BinarySearch(const T& elem, Compare *comparator)
{
    comparator = new Comparator1<T>;
    T copyOfEl = elem;
    int left, right, middle;
    left = 0;
    right = Size - 1;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (*List[middle] == elem)
            return middle;
        else if (comparator->CompareElements(&copyOfEl, List[middle])) right = middle - 1;
        else if (comparator->CompareElements(List[middle], &copyOfEl)) left = middle + 1;
    }
    return -1;
}

template <typename T>
int Array<T>::Find(const T& elem)
{
    for (int i = 0; i < Size; i++)
        if (*List[i] == elem)
            return i;
    return -1;
}

template <typename T>
int Array<T>::Find(const T& elem, int(*compare)(const T&, const T&))
{
    for (int i = 0; i < Size; i++)
        if (compare(*List[i], elem))
        return i;
    return -1;
}

template <typename T>
int Array<T>::Find(const T& elem, Compare *comparator)
{
    comparator = new Comparator2<T>;
    T copyOfEl = elem;
    for (int i = 0; i < Size; i++)
        if (comparator->CompareElements(List[i], &copyOfEl))
            return i;
    return -1;
}

template <typename T>
int Array<T>::GetSize() const
{
    return Size;
}

template <typename T>
int Array<T>::GetCapacity() const
{
    return Capacity;
}

template <typename T>
ArrayIterator<T> Array<T>::GetBeginIterator()
{
    return ArrayIterator<T>(List, 0);
}

template <typename T>
ArrayIterator<T> Array<T>::GetEndIterator()
{
    return ArrayIterator<T>(List, Size);
}
