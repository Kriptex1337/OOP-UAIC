#include <iostream>
#include "Array.h"
#include "Compare.h"
#include "Comparator1.h"
#include "ArrayIterator.h"

int Less(const int &x, const int &y)
{
    return ((x < y) ? (1) : (0));
}

int Equal(const int &x, const int &y)
{
    return ((x == y) ? (1) : (0));
}

int main()
{
    Array<int> sArr, iArr(10);

    for (int i = 0; i < 10; i++) iArr += (i * 10);

    iArr.Insert(5, 69);

    for (int i = 0; i < iArr.GetSize(); i++) std::cout << iArr[i] << ' ';

    Array<int> cArr(iArr);

    iArr.Insert(3, cArr);
    std::cout << std::endl;
    for (int i = 0; i < iArr.GetSize(); i++) std::cout << iArr[i] << ' ';

    std::cout << std::endl;
    for (int i = 0; i < cArr.GetSize(); i++) std::cout << cArr[i] << ' ';
    cArr.Delete(7);
    std::cout << std::endl;
    for (int i = 0; i < cArr.GetSize(); i++) std::cout << cArr[i] << ' ';

    sArr = iArr;
    std::cout << std::endl;
    for (int i = 0; i < cArr.GetSize(); i++) std::cout << cArr[i] << ' ';

    Array<int> sortArr(6);

    sortArr += 4;
    sortArr += 2;
    sortArr += 7;
    sortArr += 0;
    sortArr += 3;
    sortArr += 3;

    std::cout << std::endl;
    for (int i = 0; i < sortArr.GetSize(); i++) std::cout << sortArr[i] << ' ';
    sortArr.Sort();
    std::cout << std::endl;
    for (int i = 0; i < sortArr.GetSize(); i++) std::cout << sortArr[i] << ' ';

    Array<int> sortArr1(6);

    sortArr1 += 4;
    sortArr1 += 2;
    sortArr1 += 7;
    sortArr1 += 0;
    sortArr1 += 3;
    sortArr1 += 3;

    sortArr1.Sort(Less);
    std::cout << std::endl;
    for (int i = 0; i < sortArr1.GetSize(); i++) std::cout << sortArr1[i] << ' ';

    Array<int> sortArr2(6);

    sortArr2 += 4;
    sortArr2 += 2;
    sortArr2 += 7;
    sortArr2 += 0;
    sortArr2 += 3;
    sortArr2 += 3;

    Compare *Less1 = nullptr;
    sortArr2.Sort(Less1);
    std::cout << std::endl;
    for (int i = 0; i < sortArr2.GetSize(); i++) std::cout << sortArr2[i] << ' ';
    std::cout << std::endl;

    Array<int> searchArr(5);

    searchArr += 1;
    searchArr += 2;
    searchArr += 3;
    searchArr += 4;
    searchArr += 5;

    std::cout << searchArr.BinarySearch(3) << std::endl;
    std::cout << searchArr.BinarySearch(-2) <<std::endl;
    std::cout << searchArr.BinarySearch(3, Less) << std::endl;
    std::cout << searchArr.BinarySearch(-2, Less) <<std::endl;
    std::cout << searchArr.BinarySearch(3, Less1) << std::endl;
    std::cout << searchArr.BinarySearch(-2, Less1) <<std::endl;
    std::cout << std::endl;
    std::cout << searchArr.Find(1) << std::endl;
    std::cout << searchArr.Find(-7) << std::endl;
    std::cout << searchArr.Find(1, Equal) << std::endl;
    std::cout << searchArr.Find(-7, Equal) << std::endl;
    std::cout << searchArr.Find(1, Equal) << std::endl;
    std::cout << searchArr.Find(-7, Equal) << std::endl;

    Compare *Equal1 = nullptr;
    std::cout << searchArr.Find(1, Equal1) << std::endl;
    std::cout << searchArr.Find(-7, Equal1) << std::endl;


    std::cout << std::endl << "Test Iterator:" << std::endl;

    ArrayIterator<int> it;
    for (it = searchArr.GetBeginIterator(); it != searchArr.GetEndIterator(); ++it)
        std::cout << *it.GetElement() << ' ';

    return 0;
}
