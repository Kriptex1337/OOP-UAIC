#pragma once
#include <utility>
#include <string>
#include <initializer_list>
#define MAX(a, b) ((a > b) ? (a) : (b))

template <typename T>
class MyMap
{
    std::pair<std::string, T> *Container;
    int Size, Allocated;
public:
    MyMap();
    std::pair<std::string, T>* begin();
    std::pair<std::string, T>* end();
    bool operator()(std::string);
    T& operator[](std::string);
    MyMap(std::initializer_list<std::pair<std::string, T>>);
    explicit operator int();
    bool insert(std::pair<std::string, T>);
    bool remove(std::string);
    template <typename U>
    friend MyMap<U> operator&(MyMap<U>, MyMap<U>);
    template <typename U>
    friend MyMap<U> operator|(MyMap<U>, MyMap<U>);
};

template <typename T>
MyMap<T>::MyMap() : Size(0), Allocated(100)
{
    Container = new std::pair<std::string, T>[Allocated];
}

template <typename T>
std::pair<std::string, T>* MyMap<T>::begin()
{
    return &Container[0];
}

template <typename T>
std::pair<std::string, T>* MyMap<T>::end()
{
    return &Container[Size];
}

template <typename T>
bool MyMap<T>::operator()(std::string key)
{
    for (int i = 0; i < Size; i++)
        if (Container[i].first == key)
            return true;
    return false;
}

template <typename T>
T& MyMap<T>::operator[](std::string key)
{
    int i;
    if (!operator()(key)) insert(std::pair<std::string, T>(key, (T)0));
    for (i = 0; i < Size; i++)
        if (Container[i].first == key)
            break;
    return Container[i].second;
}

template <typename T>
MyMap<T>::MyMap(std::initializer_list<std::pair<std::string, T>> list) : Size(0), Allocated(100)
{
    Container = new std::pair<std::string, T>[Allocated];
    for (auto i : list) insert(i);
}

template <typename T>
MyMap<T>::operator int()
{
    return Size;
}

template <typename T>
bool MyMap<T>::insert(std::pair<std::string, T> obj)
{
    if (operator()(obj.first))
    {
        operator[](obj.first) = obj.second;
        return true;
    }
    if (Size + 1 > Allocated)
    {
        Allocated *= 2;
        std::pair<std::string, T>* copyContainer = new std::pair<std::string, T>[Allocated];
        for (int i = 0; i < Size; i++) copyContainer[i] = Container[i];
        delete[] Container;
        Container = copyContainer;
    }
    Container[Size++] = obj;
    return true;
}

template <typename T>
bool MyMap<T>::remove(std::string key)
{
    if (!operator()(key)) return false;
    int i;
    for (i = 0; i < Size; i++)
        if (Container[i].first == key)
            break;
    for (int k = i; k < Size; k++) Container[k] = Container[k + 1];
    Size--;
    return true;
}

template<typename T>
MyMap<T> operator&(MyMap<T> obj1, MyMap<T> obj2)
{
    MyMap<T> And;
    for (auto i : obj1) And.insert(i);
    for (auto i : obj2)
        if (And(i.first)) And[i.first] = MAX(And[i.first], i.second);
        else And.insert(i);
    return And;
}

template<typename T>
MyMap<T> operator|(MyMap<T> obj1, MyMap<T> obj2)
{
    MyMap<T> Or;
    for (auto i : obj1)
        if (obj2(i.first))
            Or[i.first] = MAX(obj1[i.first], obj2[i.first]);
    return Or;
}
