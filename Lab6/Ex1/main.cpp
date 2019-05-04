#include <iostream>
#include <fstream>
#include <string.h>
#include <set>

int StringToInt(std::string str)
{
    int Number = 0;
    for (int i = 0; i < str.length(); i++) Number = Number * 10 + (str[i] - '0');
    return Number;
}

int main()
{
    std::ifstream file("fisier.txt");
    std::string line;
    std::set<int> IntegerSet;

    int start, length;
    while(file >> line)
    {
        start = 0;
        length = 0;
        for (int i = 0; i <= line.length(); i++)
            if (line[i] >= '0' && line[i] <= '9')
            {
                if (length == 0) start = i;
                length++;
            }
            else if (length != 0)
            {
                IntegerSet.insert(StringToInt(line.substr(start, length)));
                length = 0;
            }
    }

    for (auto i : IntegerSet) std::cout << i << ' ';
    return 0;
}
