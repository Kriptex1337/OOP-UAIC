#include <iostream>
#include "MyMap.h"
#include <utility>
#include <string>
#include "Integer.h"

int main()
{
    MyMap<int> IntMap;

    IntMap.insert(std::pair<std::string, int>("text1", 1));
    IntMap.insert(std::pair<std::string, int>("text2", 2));
    IntMap.insert(std::pair<std::string, int>("text3", 3));
    IntMap.insert(std::pair<std::string, int>("text4", 4));
    IntMap.insert(std::pair<std::string, int>("text5", 5));
    IntMap["text6"] = 6;
    IntMap["text7"] = 7;
    IntMap["text8"] = 8;
    IntMap["text9"] = 9;
    IntMap["text10"] = 10;

    if (IntMap("text6")) std::cout << "Elementul text6 exista in map!" << std::endl;
    else std::cout << "Elementul text6 NU exista in map!" << std::endl;
    if (IntMap("text20")) std::cout << "Elementul text20 exista in map!" << std::endl;
    else std::cout << "Elementul text20 NU exista in map!" << std::endl;

    for (auto i : IntMap) std::cout << i.first << ' ' << i.second << std::endl;

    std::cout << "IntMap are " << (int)IntMap << " elemente." << std::endl;

    if (IntMap.remove("text20")) std::cout << "Elementul text20 a fost sters cu succes!" << std::endl;
    else std::cout << "Stergerea elementului text20 a esuat!" << std::endl;
    if (IntMap.remove("text8")) std::cout << "Elementul text8 a fost sters cu succes!" << std::endl;
    else std::cout << "Stergerea elementului text8 a esuat!" << std::endl;

    for (auto i : IntMap) std::cout << i.first << ' ' << i.second << std::endl;

    MyMap<int> Mul1 = {{"text1", 1}, {"text2", 2}, {"text3", 3}}, Mul2 = {{"text2", 2}, {"text3", 3}, {"text5", 5}};

    MyMap<int> And, Or;

    And = Mul1 & Mul2;
    Or = Mul1 | Mul2;

    std::cout << "AND: " << std::endl;
    for (auto i : And) std::cout << i.first << ' ' << i.second << std::endl;

    std::cout << "OR: " << std::endl;
    for (auto i : Or) std::cout << i.first << ' ' << i.second << std::endl;

    MyMap<Integer> MulI1 = {{"text1", 1}, {"text2", 2}, {"text3", 3}}, MulI2 = {{"text2", 2}, {"text3", 3}, {"text5", 5}};

    MyMap<Integer> AndI, OrI;

    AndI = MulI1 & MulI2;
    OrI = MulI1 | MulI2;

    std::cout << "AND: " << std::endl;
    for (auto i : AndI) std::cout << i.first << ' ' << i.second.GetElement() << std::endl;

    std::cout << "OR: " << std::endl;
    for (auto i : OrI) std::cout << i.first << ' ' << i.second.GetElement() << std::endl;
    return 0;
}
