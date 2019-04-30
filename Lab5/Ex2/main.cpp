#include <iostream>
#include "List.h"
#include "Integer.h"

int main()
{
    List<int> Lista1;

    Lista1.Add(5);
    Lista1.Add(-3);
    Lista1.Add(12);
    Lista1.Add(0);
    Lista1.Add(30);
    Lista1.Add(-5);
    Lista1.Add(22);
    Lista1.Add(-17);

    for (int i = 0; i < Lista1.GetSize(); i++) std::cout << Lista1[i] << ' ';
    std::cout << std::endl;

    Lista1.Sort();

    for (int i = 0; i < Lista1.GetSize(); i++) std::cout << Lista1[i] << ' ';
    std::cout << std::endl;

    std::cout << std::endl;

    List<Integer> Lista2;

    Lista2.Add(Integer(9));
    Lista2.Add(Integer(-7));
    Lista2.Add(Integer(3));
    Lista2.Add(Integer(12));
    Lista2.Add(Integer(70));
    Lista2.Add(Integer(-12));
    Lista2.Add(Integer(22));
    Lista2.Add(Integer(-30));

    for (int i = 0; i < Lista1.GetSize(); i++) std::cout << Lista2[i].GetElement() << ' ';
    std::cout << std::endl;

    Lista2.Sort();

    for (int i = 0; i < Lista1.GetSize(); i++) std::cout << Lista2[i].GetElement() << ' ';
    std::cout << std::endl;
    return 0;
}
