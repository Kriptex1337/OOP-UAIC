#include "SimpleLinkedList.h"

SimpleLinkedList::SimpleLinkedList() : Root(nullptr), Length(0){}

bool SimpleLinkedList::Add(int value)
{
    LLNode * newNode = new LLNode;
    newNode->Info = value;
    newNode->Next = nullptr;
    if (!Length) Root = newNode;
    else
    {
        LLNode * Parc = Root;
        while(Parc->Next != nullptr) Parc = Parc->Next;
        Parc->Next = newNode;
    }
    Length++;
    return true;
}

bool SimpleLinkedList::Del(int value)
{
    if (Length == 0) return false;
    if (Length == 1)
    {
        if (Root->Info == value)
        {
            delete Root;
            Root = nullptr;
            Length--;
            return true;
        }
        else
            return false;
    }
    LLNode * Parc = Root;
    while (Parc->Next != nullptr)
    {
        if (Parc->Next->Info == value)
        {
            if (Parc->Next->Next != nullptr)
            {
                LLNode * auxNode = Parc->Next;
                Parc->Next = Parc->Next->Next;
                delete auxNode;
                Length--;
                return true;
            }
            else
            {
                delete Parc->Next;
                Parc->Next = nullptr;
                Length--;
                return true;
            }
        }
        Parc = Parc->Next;
    }
    return false;
}

int SimpleLinkedList::Count(int value)
{
    LLNode * Parc = Root;
    int Count = 0;
    while (Parc != nullptr)
    {
        if (Parc->Info == value)
            Count++;
        Parc = Parc->Next;
    }
    return Count;
}

bool SimpleLinkedList::Exists(int value)
{
    return ((Count(value) == 0) ? (false) : (true));
}

int* SimpleLinkedList::GetSortedArray()
{
    int *Array, Size = 0;
    Array = new int[Length];
    LLNode * Parc = Root;
    while (Parc != nullptr)
    {
        Array[Size++] = Parc->Info;
        Parc = Parc->Next;
    }
    for (int i = 0; i < Size - 1; i++)
        for (int j = i + 1; j < Size; j++)
            if (Array[j] < Array[i])
            {
                Array[i] = Array[i] + Array[j];
                Array[j] = Array[i] - Array[j];
                Array[i] = Array[i] - Array[j];
            }
    return Array;
}

int SimpleLinkedList::GetCount()
{
    return Length;
}
