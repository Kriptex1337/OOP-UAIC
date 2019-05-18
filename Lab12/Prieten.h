#pragma once
#include "Contact.h"

class Prieten : public Contact
{
    std::string BirthDate;
    std::string PhoneNumber;
    std::string Address;
public:
    Prieten();
    Prieten(std::string, std::string, std::string, std::string);
    std::string GetPersonName();
    std::string GetBirthDate();
    std::string GetPhoneNumber();
    std::string GetAddress();
    void PrintContactDetails();
};
