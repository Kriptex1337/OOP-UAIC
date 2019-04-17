#include <iostream>
#include "Sort.h"

int main()
{
	std::vector<int> lista;

	lista.push_back(10);
	lista.push_back(80);
	lista.push_back(30);
	lista.push_back(90);
	lista.push_back(40);
	lista.push_back(50);
	lista.push_back(70);

	Sort<int>(lista, [](int &e1, int &e2) { return (int)(e1 <= e2); });

	std::cout << "Lista<int> sortata este: " << std::endl;
	for (auto i : lista)
		std::cout << i << ' ';
	std::cout << std::endl << std::endl;

	std::vector<MyNumber> lista2;

	lista2.push_back(MyNumber(10));
	lista2.push_back(MyNumber(80));
	lista2.push_back(MyNumber(30));
	lista2.push_back(MyNumber(90));
	lista2.push_back(MyNumber(40));
	lista2.push_back(MyNumber(50));
	lista2.push_back(MyNumber(70));

	Sort<MyNumber>(lista2, [](MyNumber &e1, MyNumber &e2) { return (int)(e1.GetNumber() <= e2.GetNumber()); });

	std::cout << "Lista<MyNumber> sortata este: " << std::endl;
	for (auto i : lista2)
		std::cout << i.GetNumber() << ' ';
	std::cout << std::endl;

	return 0;
}
