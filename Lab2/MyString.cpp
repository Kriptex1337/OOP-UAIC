#include "MyString.h"
#include <iostream>
#include <cstring>

MyString::MyString() : AllocatedSize(16), Size(0)
{
    sir = new char[AllocatedSize];
}

MyString::MyString(const char *text)
{
    Size = strlen(text);
    AllocatedSize = Size + 1;
    sir = new char[AllocatedSize];
    strcpy(sir, text);
}

MyString::~MyString()
{
    delete[] sir;
}

unsigned int MyString::GetSize()
{
    return Size;
}

void MyString::Set(const char *text)
{
    Size = strlen(text);
    if (Size + 1 > AllocatedSize)
    {
        AllocatedSize = Size + 1;
        sir = new char[AllocatedSize];
    }
    strcpy(sir, text);
}

void MyString::Set(MyString &m)
{
    Set(m.sir);
}

void MyString::Add(const char *text)
{
    Size += strlen(text);
    if (Size + 1 > AllocatedSize)
    {
        AllocatedSize = Size + 1;
        char *copySir = new char[AllocatedSize];
        strcpy(copySir, sir);
        sir = copySir;
    }
    strcat(sir, text);
}

void MyString::Add(MyString &m)
{
    Add(m.sir);
}

const char* MyString::GetText()
{
    return sir;
}

MyString* MyString::SubString(unsigned int start, unsigned int size)
{
    if (start + size >= Size) return nullptr;
    char *str = new char[Size - start + 1];
    strcpy(str, sir + start);
    str[size] = 0;
    MyString *obj = new MyString(str);
    return obj;
}

bool MyString::Delete(unsigned int start, unsigned int size)
{
    if (start + size > Size) return false;
    Size -= size;
    strcpy(sir + start, sir + start + size);
    return true;
}

int MyString::Compare(const char *text)
{
    return strcmp(sir, text);
}

int MyString::Compare(MyString &m)
{
    return Compare(m.sir);
}

char MyString::GetChar(unsigned int index)
{
    if (index >= Size) return 0;
    return sir[index];
}

bool MyString::Insert(unsigned int index, const char *text)
{
    if (index >= Size) return false;
    unsigned int SizeOfText = strlen(text);
    if (Size + SizeOfText + 1 > AllocatedSize)
    {
        AllocatedSize = Size + SizeOfText + 1;
        char * copySir = new char[AllocatedSize];
        strcpy(copySir, sir);
        sir = copySir;
    }
    for (unsigned int i = Size; i >= index; i--)
        sir[i + SizeOfText] = sir[i];
    for (unsigned int i = index; i < index + SizeOfText; i++)
        sir[i] = text[i - index];
    Size += SizeOfText;
    return true;
}

bool MyString::Insert(unsigned int index, MyString &m)
{
    return Insert(index, m.sir);
}

int MyString::Find(const char *text)
{
    char *subStr = strstr(sir, text);
    if (!subStr) return -1;
    unsigned int SizeOfText = strlen(text), i;
    for (i = 0; i < SizeOfText; i++)
        if (sir + i == subStr)
            break;
    return i;
}

int MyString::FindLast(const char *text)
{
    char *subStr = strstr(sir, text);
    if (!subStr) return -1;
    unsigned int SizeOfText = strlen(text);
    unsigned int i, it = 0, index;
    for (i = 0; i < Size; i++)
        if (sir[i] == text[it])
        {
            it++;
            if (it == SizeOfText)
                index = i - SizeOfText + 1;
        }
        else
            it = 0;
    return index;
}
