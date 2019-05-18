#include "Coleg.h"
#include <iostream>

Coleg::Coleg()
{
    PersonName = "NONE";
    PhoneNumber = "NONE";
    JobName = "NONE";
    Address = "NONE";
    ContactType = 2;
}

Coleg::Coleg(std::string name, std::string pn, std::string jn, std::string adr)
{
    PersonName = name;
    PhoneNumber = pn;
    JobName = jn;
    Address = adr;
    ContactType = 2;
}

std::string Coleg::GetPersonName()
{
    return PersonName;
}

std::string Coleg::GetPhoneNumber()
{
    return PhoneNumber;
}

std::string Coleg::GetJobName()
{
    return JobName;
}

std::string Coleg::GetAddress()
{
    return Address;
}

void Coleg::PrintContactDetails()
{
    std::cout << "TIP: COLEG" << std::endl;
    std::cout << "NUME: " << PersonName << std::endl;
    std::cout << "NUMAR TELEFON: " << PhoneNumber << std::endl;
    std::cout << "FIRMA: " << JobName << std::endl;
    std::cout << "ADRESA: " << Address << std::endl << std::endl;
}
