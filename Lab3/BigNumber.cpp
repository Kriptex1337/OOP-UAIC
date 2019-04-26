#include "BigNumber.h"
#include <cstring>

void StringReverse(char source[256], char dest[256])
{
    unsigned int size = strlen(source), i;
    for (i = 0; i < size; i++) dest[i] = source[size - i - 1];
    dest[size] = 0;
}

BigNumber::BigNumber()
{
    Number[0] = '0';
    Number[1] = 0;
    CharactersCount = 1;
}

BigNumber::BigNumber(int value)
{
    CharactersCount = 0;
    char desc[256];
    while (value > 0)
    {
        desc[CharactersCount++] = value % 10 + '0';
        value /= 10;
    }
    desc[CharactersCount] = 0;
    StringReverse(desc, Number);
}

BigNumber::BigNumber(const char * number)
{
    strcpy(Number, number);
    CharactersCount = strlen(number);
}

BigNumber::BigNumber(const BigNumber& number)
{
    strcpy(Number, number.Number);
    CharactersCount = number.CharactersCount;
}

bool BigNumber::Set(int value)
{
    if (value < 0) return false;
    CharactersCount = 0;
    char desc[256];
    while (value > 0)
    {
        desc[CharactersCount++] = value % 10 + '0';
        value /= 10;
    }
    desc[CharactersCount] = 0;
    StringReverse(desc, Number);
    return true;
}

bool BigNumber::Set(const char * number)
{
    if (atoi(number) < 0) return false;
    strcpy(Number, number);
    CharactersCount = strlen(number);
    return true;
}

BigNumber BigNumber::operator+(const BigNumber& obj)
{
    int nmb1, nmb2, sum;
    BigNumber copyConst(obj);
    nmb1 = (int)*this;
    nmb2 = (int)copyConst;
    sum = nmb1 + nmb2;
    return BigNumber(sum);
}

BigNumber BigNumber::operator*(const BigNumber& obj)
{
    int nmb1, nmb2, prod;
    BigNumber copyConst(obj);
    nmb1 = (int)*this;
    nmb2 = (int)copyConst;
    prod = nmb1 * nmb2;
    return BigNumber(prod);
}

BigNumber BigNumber::operator-(const BigNumber& obj)
{
    int nmb1, nmb2, dif;
    BigNumber copyConst(obj);
    nmb1 = (int)*this;
    nmb2 = (int)copyConst;
    dif = nmb1 - nmb2;
    return BigNumber(dif);
}

BigNumber BigNumber::operator/(const BigNumber& obj)
{
    int nmb1, nmb2, imp;
    BigNumber copyConst(obj);
    nmb1 = (int)*this;
    nmb2 = (int)copyConst;
    imp = nmb1 / nmb2;
    return BigNumber(imp);
}

bool operator==(const BigNumber& nr1, const BigNumber& nr2)
{
    if (nr1.CharactersCount != nr2.CharactersCount) return false;
    for (int i = 0; i < nr1.CharactersCount; i++)
        if (nr1.Number[i] != nr2.Number[i])
            return false;
    return true;
}

bool operator!=(const BigNumber& nr1, const BigNumber& nr2)
{
    return !(nr1 == nr2);
}

bool operator<(const BigNumber& nr1, const BigNumber& nr2)
{
    if (nr1.CharactersCount > nr2.CharactersCount) return false;
    if (nr1.CharactersCount < nr2.CharactersCount) return true;
    for (int i = 0; i < nr1.CharactersCount; i++)
        if (nr1.Number[i] > nr2.Number[i]) return false;
        else if (nr1.Number[i] < nr2.Number[i]) return true;
    return false;
}

bool operator>(const BigNumber& nr1, const BigNumber& nr2)
{
    if (nr1.CharactersCount < nr2.CharactersCount) return false;
    if (nr1.CharactersCount > nr2.CharactersCount) return true;
    for (int i = 0; i < nr1.CharactersCount; i++)
        if (nr1.Number[i] < nr2.Number[i]) return false;
        else if (nr1.Number[i] > nr2.Number[i]) return true;
    return false;
}

bool operator>=(const BigNumber& nr1, const BigNumber& nr2)
{
    return !(nr1 < nr2);
}

bool operator<=(const BigNumber& nr1, const BigNumber& nr2)
{
    return !(nr1 > nr2);
}

std::ostream& operator<<(std::ostream& out, const BigNumber& number)
{
    out << "STR: " << number.Number << "| SIZE: " << number.CharactersCount;
    return out;
}

BigNumber::operator int()
{
    if (CharactersCount > 10) return -1;
    int number = 0;
    for (int i = 0; i < CharactersCount; i++) number = number * 10 + Number[i] - '0';
    return number;
}

char BigNumber::operator[](int index)
{
    if (index < 0 || index >= CharactersCount) return 0;
    return Number[index];
}

BigNumber BigNumber::operator()(int start ,int end)
{
    BigNumber newObj;
    if ((start < 0 || start >= CharactersCount) || (end < 0 || end >= CharactersCount)) return newObj;
    char nmb[256];
    int c = 0;
    for (int i = start; i <= end; i++) nmb[c++] = Number[i];
    nmb[c] = 0;
    newObj.Set(nmb);
    return newObj;
}
