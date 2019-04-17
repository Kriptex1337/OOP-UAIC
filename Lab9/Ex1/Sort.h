#pragma once

#include <vector>
#include <stack>
#include "MyNumber.h"

template <class T>
void Sort(std::vector<T> &lista, int(*Compare)(T &e1, T &e2))
{
	std::stack<int> IndexStack;
	int left, right, pivot, i;
	void(*Swap)(T &e1, T &e2) = [](T &e1, T &e2) { T aux = e1; e1 = e2; e2 = aux; };

	IndexStack.push(0);
	IndexStack.push(lista.size() - 1);

	while (IndexStack.size() > 0)
	{
		right = IndexStack.top();
		IndexStack.pop();
		left = IndexStack.top();
		IndexStack.pop();

		i = left - 1;

		for (int j = left; j <= right - 1; j++)
		{
			if (Compare(lista[j], lista[right]))
			{
				i++;
				Swap(lista[i], lista[j]);
			}
		}

		i++;

		Swap(lista[i], lista[right]);

		pivot = i;

		if (pivot - 1 > left)
		{
			IndexStack.push(left);
			IndexStack.push(pivot - 1);
		}

		if (pivot + 1 < right)
		{
			IndexStack.push(pivot + 1);
			IndexStack.push(right);
		}
	}
}
