#include <iostream>

class BigNumber
{
private:
    char Number[256];
    int CharactersCount;
public:
    BigNumber();
    BigNumber(int);
    BigNumber(const char *);
    BigNumber(const BigNumber&);
    bool Set(int);
    bool Set(const char *);
    BigNumber operator+(const BigNumber&);
    BigNumber operator*(const BigNumber&);
    BigNumber operator-(const BigNumber&);
    BigNumber operator/(const BigNumber&);
    friend bool operator==(const BigNumber&, const BigNumber&);
    friend bool operator!=(const BigNumber&, const BigNumber&);
    friend bool operator<(const BigNumber&, const BigNumber&);
    friend bool operator>(const BigNumber&, const BigNumber&);
    friend bool operator>=(const BigNumber&, const BigNumber&);
    friend bool operator<=(const BigNumber&, const BigNumber&);
    friend std::ostream& operator<<(std::ostream&, const BigNumber&);
    operator int();
    char operator[](int);
    BigNumber operator()(int,int);
};
