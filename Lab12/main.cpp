#include <iostream>
#include "Prieten.h"
#include "Cunoscut.h"
#include "Coleg.h"
#include "Agenda.h"
#include <vector>

int main()
{
    Agenda agenda;
    Contact *pr = new Prieten("Ghita Pristanda", "12 mai 1800", "0762318521", "Str. Mortilor, Nr. 6");
    Contact *pr1 = new Prieten("Ion Gicu", "31 dec 2003", "0754047281", "Str. Soarelui, Nr. 5");
    Contact *pr2 = new Prieten("Gigel Hulea", "2 oct 1999", "0783953210", "Str. Nuferilor, Nr. 37");
    Contact *cum = new Cunoscut("Telespan Adrian", "0745824013");
    Contact *col = new Coleg("Barbu Nicolae", "0232712534", "AMAZON S.R.L", "Bvd. Republicii Nr. 8");

    agenda.AddContact(pr);
    agenda.AddContact(pr1);
    agenda.AddContact(pr2);
    agenda.AddContact(cum);
    agenda.AddContact(col);

    std::vector<Prieten*> ListaPrieteni = agenda.FriendsList();

    for (unsigned int i = 0; i < ListaPrieteni.size(); i++)
        ListaPrieteni[i]->PrintContactDetails();

    agenda.FindContact("Telespan Adrian")->PrintContactDetails();
    agenda.FindContact("Barbu Nicolae")->PrintContactDetails();

    return 0;
}
