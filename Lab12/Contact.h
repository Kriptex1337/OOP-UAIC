#pragma once
#include <string>

class Contact
{
protected:
    std::string PersonName;
    int ContactType;
public:
    int GetContactType();
    virtual std::string GetPersonName() = 0;
    virtual void PrintContactDetails() = 0;
};
