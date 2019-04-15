#include <iostream>

bool Convert(unsigned int number, unsigned int toBase, char * result, unsigned int resultMaxSize)
{
    if (toBase < 2 || toBase > 16) return false;
    const char * characters = "0123456789ABCDEF";
    char primResult[resultMaxSize];
    int n = 0;
    while (number > 0)
    {
        primResult[n++] = characters[number % toBase];
        number /= toBase;
    }
    for (int i = 0; i < n; i++)
        result[i] = primResult[n - i - 1];
    result[n] = '\0';
    return true;
}

int main()
{
    unsigned int resultSize = 100;
    char * result = new char[resultSize + 1];
    Convert(20, 2, result, resultSize);
    puts(result);
    return 0;
}
