#pragma once

class Integer
{
    int el;
public:
    Integer();
    Integer(int);
    bool operator>(Integer);
    int GetElement();
};
