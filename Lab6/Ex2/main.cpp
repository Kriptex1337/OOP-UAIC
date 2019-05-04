#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility>
#include <algorithm>

std::map<std::string, int> wordFreq;
std::multimap<int, std::string> sortedWF;

void OpenAndReadFromFile(const char*);
void StringParsing(std::string);
std::pair<int, std::string> SwapPair(std::pair<std::string, int>);
void SortElements();
void PrintSortedMap();

int main()
{
    OpenAndReadFromFile("fisier.txt");
    SortElements();
    PrintSortedMap();

    return 0;
}

void OpenAndReadFromFile(const char *fileName)
{
    std::ifstream file(fileName);
    std::string line;

    while (file >> line) StringParsing(line);

    file.close();
}

void StringParsing(std::string line)
{
    int start = 0, length = 0;

    for (int i = 0; i <= line.length(); i++)
        if (line[i] >= 'a' && line[i] <= 'z' || line[i] >= 'A' && line[i] <= 'Z')
        {
            if (!length) start = i;
            length++;
        }
        else if (length)
        {
            wordFreq[line.substr(start, length)]++;
            length = 0;
        }
}

std::pair<int, std::string> SwapPair(std::pair<std::string, int> obj)
{
    return std::pair<int, std::string>(obj.second, obj.first);
}

void SortElements()
{
    for (auto i : wordFreq) sortedWF.insert(SwapPair(i));
}

void PrintSortedMap()
{
    int count = 0;
    for (auto i = sortedWF.rbegin(); i != sortedWF.rend() && count < 10; i++, count++)
        std::cout << i->second << ' ' << i->first << std::endl;
}
