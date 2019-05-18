#pragma once
#include "Contact.h"
#include "Prieten.h"
#include "vector"

class Agenda
{
    std::vector<Contact*> ContactList;
public:
    Agenda();
    Contact* FindContact(std::string);
    std::vector<Prieten*> FriendsList();
    bool DeleteContact(std::string);
    bool AddContact(Contact*);
};
