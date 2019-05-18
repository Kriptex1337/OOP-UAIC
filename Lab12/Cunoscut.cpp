#include "Cunoscut.h"
#include <iostream>

Cunoscut::Cunoscut()
{
    PersonName = "NONE";
    PhoneNumber = "NONE";
    ContactType = 1;
}

Cunoscut::Cunoscut(std::string name, std::string pn)
{
    PersonName = name;
    PhoneNumber = pn;
    ContactType = 1;
}

std::string Cunoscut::GetPersonName()
{
    return PersonName;
}

std::string Cunoscut::GetPhoneNumber()
{
    return PhoneNumber;
}

void Cunoscut::PrintContactDetails()
{
    std::cout << "TIP: CUNOSCUT" << std::endl;
    std::cout << "NUME: " << PersonName << std::endl;
    std::cout << "NUMAR TELEFON: " << PhoneNumber << std::endl << std::endl;
}
