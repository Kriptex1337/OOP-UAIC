#pragma once
#include "Contact.h"

class Coleg : public Contact
{
    std::string PhoneNumber;
    std::string JobName;
    std::string Address;
public:
    Coleg();
    Coleg(std::string, std::string, std::string, std::string);
    std::string GetPersonName();
    std::string GetPhoneNumber();
    std::string GetJobName();
    std::string GetAddress();
    void PrintContactDetails();
};
