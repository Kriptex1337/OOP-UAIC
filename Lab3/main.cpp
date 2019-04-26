#include <iostream>
#include "BigNumber.h"

int main()
{
    BigNumber objs;
    std::cout << objs << std::endl;
    BigNumber obji(1337);
    std::cout << obji << std::endl;
    BigNumber objc("2000");
    std::cout << objc << std::endl;
    BigNumber objcp(obji);
    std::cout << objcp << std::endl;

    BigNumber objset;
    if (!objset.Set(-123)) std::cout << "ERROR: Negative numbers aren't allowed!" << std::endl;
    else std::cout << objset << std::endl;
    if (!objset.Set(123)) std::cout << "ERROR: Negative numbers aren't allowed!" << std::endl;
    else std::cout << objset << std::endl;

    if (!objset.Set("-312")) std::cout << "ERROR: Negative numbers aren't allowed!" << std::endl;
    else std::cout << objset << std::endl;
    if (!objset.Set("312")) std::cout << "ERROR: Negative numbers aren't allowed!" << std::endl;
    else std::cout << objset << std::endl;

    BigNumber s1(312), s2(188), rezSum, rezProd, rezDif, rezImp;
    rezSum = s1 + s2;
    std::cout << rezSum << std::endl;
    rezProd = s1 * s2;
    std::cout << rezProd << std::endl;
    rezDif = s1 - s2;
    std::cout << rezDif << std::endl;
    rezImp = s1 / s2;
    std::cout << rezImp << std::endl;

    BigNumber nr1, nr2;
    nr1.Set(1034);
    nr2.Set(324);
    if (!(nr1 == nr2)) std::cout << "The numbers are NOT equal!" << std::endl;
    else std::cout << "The numbers are equal!" << std::endl;
    nr1.Set(104);
    nr2.Set(402);
    if (!(nr1 == nr2)) std::cout << "The numbers are NOT equal!" << std::endl;
    else std::cout << "The numbers are equal!" << std::endl;
    nr1.Set(300);
    nr2.Set(300);
    if (!(nr1 == nr2)) std::cout << "The numbers are NOT equal!" << std::endl;
    else std::cout << "The numbers are equal!" << std::endl;

    nr1.Set(123);
    nr2.Set(1234);
    if (nr1 < nr2) std::cout << "nr1 is lower than nr2" << std::endl;
    else std::cout << "nr1 isn't lower than nr2" << std::endl;
    nr1.Set(1234);
    nr2.Set(123);
    if (nr1 < nr2) std::cout << "nr1 is lower than nr2" << std::endl;
    else std::cout << "nr1 isn't lower than nr2" << std::endl;
    nr1.Set(123);
    nr2.Set(123);
    if (nr1 < nr2) std::cout << "nr1 is lower than nr2" << std::endl;
    else std::cout << "nr1 isn't lower than nr2" << std::endl;
    nr1.Set(1134);
    nr2.Set(1234);
    if (nr1 < nr2) std::cout << "nr1 is lower than nr2" << std::endl;
    else std::cout << "nr1 isn't lower than nr2" << std::endl;

    nr1.Set(123);
    nr2.Set(1234);
    if (nr1 > nr2) std::cout << "nr1 is bigger than nr2" << std::endl;
    else std::cout << "nr1 isn't bigger than nr2" << std::endl;
    nr1.Set(1234);
    nr2.Set(123);
    if (nr1 > nr2) std::cout << "nr1 is bigger than nr2" << std::endl;
    else std::cout << "nr1 isn't bigger than nr2" << std::endl;
    nr1.Set(123);
    nr2.Set(123);
    if (nr1 > nr2) std::cout << "nr1 is bigger than nr2" << std::endl;
    else std::cout << "nr1 isn't bigger than nr2" << std::endl;
    nr1.Set(1234);
    nr2.Set(1134);
    if (nr1 > nr2) std::cout << "nr1 is bigger than nr2" << std::endl;
    else std::cout << "nr1 isn't bigger than nr2" << std::endl;

    BigNumber objint("5123");
    std::cout << (int)objint << std::endl;

    std::cout << objint[2] << " CHAR: " << (int)objint[6] << std::endl;

    BigNumber objBig("123456789"), objSmall;
    objSmall = objBig(-3, 2);
    std::cout << objSmall << std::endl;
    objSmall = objBig(4, 12);
    std::cout << objSmall << std::endl;
    objSmall = objBig(0, 4);
    std::cout << objSmall << std::endl;
    return 0;
}
