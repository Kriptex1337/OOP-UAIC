#include <iostream>
#include "SimpleLinkedList.h"
#include "BinaryTree.h"

void PrintList(SimpleLinkedList List)
{
    int * sortedList = List.GetSortedArray();
    for (int i = 0; i < List.GetCount(); i++)
        std::cout << sortedList[i] << ' ';
    std::cout << std::endl;
}

void PrintTree(BinaryTree Tree)
{
    int * sortedTree = Tree.GetSortedArray();
    for (int i = 0; i < Tree.GetCount(); i++)
        std::cout << sortedTree[i] << ' ';
    std::cout << std::endl;
}

int main()
{
    SimpleLinkedList List;

    List.Add(5);
    List.Add(3);
    List.Add(10);
    List.Add(10);
    List.Add(0);
    List.Add(-7);
    List.Add(20);
    List.Add(5);
    List.Add(10);
    List.Add(10);
    PrintList(List);
    std::cout << "Elementul [10] apare de: " << List.Count(10) << " ori!" << std::endl;

    if (!List.Del(10)) std::cout << "Elementul [10] NU exista!" << std::endl;
    if (!List.Del(-3)) std::cout << "Elementul [-3] NU exista!" << std::endl;
    PrintList(List);

    std::cout << "Elementul [10] apare de: " << List.Count(10) << " ori!" << std::endl;
    if (List.Exists(10)) std::cout << "Elementul [10] exista in List!" << std::endl;
    else std::cout << "Elementul [10] NU exista in List!" << std::endl;
    if (List.Exists(-3)) std::cout << "Elementul [-3] exista in List!" << std::endl;
    else std::cout << "Elementul [-3] NU exista in List!" << std::endl;

    int *sortedArray1 = List.GetSortedArray();
    for (int i = 0; i < List.GetCount(); i++)
        std::cout << sortedArray1[i] << ' ';
    std::cout << std::endl;

    std::cout << "In List sunt " << List.GetCount() << " elemente." << std::endl;

    std::cout << std::endl << std::endl;

    BinaryTree Tree;

    Tree.Add(10);
    Tree.Add(11);
    Tree.Add(9);
    Tree.Add(7);
    Tree.Add(15);
    Tree.Add(19);
    Tree.Add(12);
    Tree.Add(10);
    Tree.Add(10);
    PrintTree(Tree);

    std::cout << "Elementul [10] apare de: " << Tree.Count(10) << " ori!" << std::endl;
    if (!Tree.Del(10)) std::cout << "Elementul [10] NU exista!" << std::endl;
    if (!Tree.Del(2)) std::cout << "Elementul [2] NU exista!" << std::endl;
    PrintTree(Tree);

    std::cout << "Elementul [10] apare de: " << Tree.Count(10) << " ori!" << std::endl;
    if (Tree.Exists(10)) std::cout << "Elementul [10] exista in Tree!" << std::endl;
    else std::cout << "Elementul [10] NU exista in Tree!" << std::endl;
    if (List.Exists(-3)) std::cout << "Elementul [-3] exista in Tree!" << std::endl;
    else std::cout << "Elementul [-3] NU exista in Tree!" << std::endl;

    int *sortedArray2 = Tree.GetSortedArray();
    for (int i = 0; i < Tree.GetCount(); i++)
        std::cout << sortedArray2[i] << ' ';
    std::cout << std::endl;

    std::cout << "In Tree sunt " << Tree.GetCount() << " elemente." << std::endl;
    return 0;
}
