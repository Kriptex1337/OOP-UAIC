#include "Prieten.h"
#include <iostream>

Prieten::Prieten()
{
    PersonName = "NONE";
    BirthDate = "NONE";
    PhoneNumber = "NONE";
    Address = "NONE";
    ContactType = 0;
}

Prieten::Prieten(std::string name, std::string bd, std::string pn, std::string adr)
{
    PersonName = name;
    BirthDate = bd;
    PhoneNumber = pn;
    Address = adr;
    ContactType = 0;
}

std::string Prieten::GetPersonName()
{
    return PersonName;
}

std::string Prieten::GetBirthDate()
{
    return BirthDate;
}

std::string Prieten::GetPhoneNumber()
{
    return PhoneNumber;
}

std::string Prieten::GetAddress()
{
    return Address;
}

void Prieten::PrintContactDetails()
{
    std::cout << "TIP: PRIETEN" << std::endl;
    std::cout << "NUME: " << PersonName << std::endl;
    std::cout << "DATA NASTERE: " << BirthDate << std::endl;
    std::cout << "NUMAR TELEFON: " << PhoneNumber << std::endl;
    std::cout << "ADRESA: " << Address << std::endl << std::endl;
}
