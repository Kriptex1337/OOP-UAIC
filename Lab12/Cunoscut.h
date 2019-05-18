#pragma once
#include "Contact.h"

class Cunoscut : public Contact
{
    std::string PhoneNumber;
public:
    Cunoscut();
    Cunoscut(std::string, std::string);
    std::string GetPersonName();
    std::string GetPhoneNumber();
    void PrintDetails();
    void PrintContactDetails();
};
