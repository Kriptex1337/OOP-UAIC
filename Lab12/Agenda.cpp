#include "Agenda.h"

Agenda::Agenda(){}

Contact* Agenda::FindContact(std::string name)
{
    unsigned int i;
    for (i = 0; i < ContactList.size(); i++)
        if (ContactList[i]->GetPersonName() == name)
            break;
    return ContactList[i];
}

std::vector<Prieten*> Agenda::FriendsList()
{
    std::vector<Prieten*> ListaPrieteni;
    for (unsigned int i = 0; i < ContactList.size(); i++)
        if (ContactList[i]->GetContactType() == 0)
            ListaPrieteni.push_back(dynamic_cast<Prieten*>(ContactList[i]));
    return ListaPrieteni;
}

bool Agenda::DeleteContact(std::string nume)
{
    for (unsigned int i = 0; i < ContactList.size(); i++)
        if (ContactList[i]->GetPersonName() == nume)
        {
            for (unsigned int j = i; j < ContactList.size() - 1; j++)
                ContactList[j] = ContactList[j + 1];
            ContactList.pop_back();
            return true;
        }
    return false;
}

bool Agenda::AddContact(Contact* obj)
{
    ContactList.push_back(obj);
    return true;
}
