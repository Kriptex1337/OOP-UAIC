#include <iostream>

int numbers[1000], countNum = 0;

void ReadFromFile(const char * fileName)
{
    FILE * pFile = fopen(fileName, "r");
    char line[10];
    while (fgets(line, sizeof(line), pFile))
    {
        numbers[countNum++] = atoi(line);
    }
}

void SortNumbers()
{
    for (int i = 0; i < countNum - 1; i++)
        for (int j = i + 1; j < countNum; j++)
            if (numbers[i] > numbers[j])
            {
                numbers[i] += numbers[j];
                numbers[j] = numbers[i] - numbers[j];
                numbers[i] -= numbers[j];
            }
}

void WriteResult()
{
    for (int i = 0; i < countNum; i++)
        std::cout << numbers[i] << ' ';
    std::cout << std::endl;
}

int main()
{
    ReadFromFile("fisier.txt");
    SortNumbers();
    WriteResult();
    return 0;
}
