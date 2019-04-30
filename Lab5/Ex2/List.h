#include <iostream>
template<typename T>
class List
{
    T *Elemente;
    int Count, Allocated;
public:
    List();
    ~List();
    bool Add(const T&);
    T& operator[](int);
    void Sort();
    int GetSize();
};

template<typename T>
List<T>::List()
{
    Allocated = 100;
    Elemente = new T[Allocated];
    Count = 0;
}

template<typename T>
List<T>::~List()
{
    delete Elemente;
}

template<typename T>
bool List<T>::Add(const T& obj)
{
    if (Count + 1 > Allocated)
    {
        Allocated *= 2;
        T *copyList = new T[Allocated];
        for (int i = 0; i < Count; i++) copyList[i] = Elemente[i];
        delete[] Elemente;
        Elemente = copyList;
    }
    Elemente[Count++] = obj;
    return true;
}

template<typename T>
T& List<T>::operator[](int index)
{
    return Elemente[index];
}

template<typename T>
void List<T>::Sort()
{
    T aux;
    for (int i = 0; i < Count - 1; i++)
        for (int j = i + 1; j < Count; j++)
            if (Elemente[j] < Elemente[i])
            {
                aux = Elemente[i];
                Elemente[i] = Elemente[j];
                Elemente[j] = aux;
            }
}

template<typename T>
int List<T>::GetSize()
{
    return Count;
}
