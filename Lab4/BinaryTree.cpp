#include "BinaryTree.h"
#include <queue>
#include <utility>

BinaryTree::BinaryTree() : Root(nullptr), Length(0){}

bool BinaryTree::Add(int value)
{
    BTNode *newNode = new BTNode;
    newNode->Info = value;
    newNode->Left = nullptr;
    newNode->Right = nullptr;

    if (!Length)
    {
        Root = newNode;
        Length++;
        return true;
    }

    BTNode *Parc;
    std::queue<BTNode*> treeQueue;
    treeQueue.push(Root);

    while (!treeQueue.empty())
    {
        Parc = treeQueue.front();
        treeQueue.pop();

        if (!Parc->Left)
        {
            Parc->Left = newNode;
            Length++;
            return true;
        }
        else treeQueue.push(Parc->Left);

        if (!Parc->Right)
        {
            Parc->Right = newNode;
            Length++;
            return true;
        }
        else treeQueue.push(Parc->Right);
    }
    return false;
}

bool BinaryTree::Del(int value)
{
    if (!Length) return false;

    BTNode *delNode;
    std::queue<BTNode*> treeQueue1;

    treeQueue1.push(Root);
    while (!treeQueue1.empty())
    {
        delNode = treeQueue1.front();
        treeQueue1.pop();

        if (delNode->Info == value) break;
        else if (delNode->Left != nullptr) treeQueue1.push(delNode->Left);
        else if (delNode->Right != nullptr) treeQueue1.push(delNode->Right);
    }

    if (delNode->Info != value) return false;

    BTNode *rightNode, *Father;
    std::queue<std::pair<BTNode*, BTNode*>> treeQueue2;

    treeQueue2.push(std::pair<BTNode*, BTNode*>(nullptr, Root));
    while (!treeQueue2.empty())
    {
        rightNode = treeQueue2.front().second;
        Father = treeQueue2.front().first;
        treeQueue2.pop();

        if (rightNode->Left) treeQueue2.push(std::pair<BTNode*, BTNode*>(rightNode, rightNode->Left));
        if (rightNode->Right) treeQueue2.push(std::pair<BTNode*, BTNode*>(rightNode, rightNode->Right));
    }

    delNode->Info = rightNode->Info;
    if (Father->Left == rightNode) Father->Left = nullptr;
    else if (Father->Right == rightNode) Father->Right = nullptr;
    delete rightNode;
    Length--;
    return true;
}

int BinaryTree::Count(int value)
{
    int Count = 0;
    BTNode *Parc;
    std::queue<BTNode*> treeQueue;
    treeQueue.push(Root);
    while (!treeQueue.empty())
    {
        Parc = treeQueue.front();
        treeQueue.pop();

        if (Parc->Info == value) Count++;
        if (Parc->Left) treeQueue.push(Parc->Left);
        if (Parc->Right) treeQueue.push(Parc->Right);
    }
    return Count;
}

bool BinaryTree::Exists(int value)
{
    return ((Count(value) == 0)?(false):(true));
}

int* BinaryTree::GetSortedArray()
{
    int *Array = new int[Length];
    int Count = 0;

    BTNode *Parc;
    std::queue<BTNode*> treeQueue;
    treeQueue.push(Root);
    while (!treeQueue.empty())
    {
        Parc = treeQueue.front();
        treeQueue.pop();

        Array[Count++] = Parc->Info;
        if (Parc->Left) treeQueue.push(Parc->Left);
        if (Parc->Right) treeQueue.push(Parc->Right);
    }

    for (int i = 0; i < Count - 1; i++)
        for (int j = i + 1; j < Count; j++)
            if (Array[j] < Array[i])
            {
                Array[i] = Array[i] + Array[j];
                Array[j] = Array[i] - Array[j];
                Array[i] = Array[i] - Array[j];
            }

    return Array;
}

int BinaryTree::GetCount()
{
    return Length;
}
