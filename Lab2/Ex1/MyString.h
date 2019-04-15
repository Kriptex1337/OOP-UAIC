#pragma once

class MyString
{
    char *sir;
    unsigned int AllocatedSize;
    unsigned int Size;
public:
    MyString();
    MyString(const char *);
    ~MyString();
    unsigned int GetSize();
    void Set(const char *);
    void Set(MyString &);
    void Add(const char *);
    void Add(MyString &);
    const char* GetText();
    MyString* SubString(unsigned int, unsigned int);
    bool Delete(unsigned int, unsigned int);
    int Compare(const char *);
    int Compare(MyString &);
    char GetChar(unsigned int);
    bool Insert(unsigned int, const char*);
    bool Insert(unsigned int, MyString &);
    int Find(const char *);
    int FindLast(const char *);
};
