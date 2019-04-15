#include <iostream>
#include "MyString.h"

int main()
{
    MyString obj1, obj2("test");
    std::cout << "Marimea sirului din obj2 este: " << obj2.GetSize() << std::endl;
    obj1.Set("test");
    obj2.Set("test123");
    MyString obj3, obj4("test");
    obj3.Set(obj1);
    obj4.Set(obj2);
    obj4.Add("alttest");
    obj3.Add(obj4);
    std::cout << obj4.GetText() << std::endl;
    MyString * obj5 = obj3.SubString(1, 5);
    std::cout << obj5->GetText() << std::endl;
    obj5->Delete(2, 2);
    std::cout << obj5->GetText() << std::endl;
    std::cout << obj5->Compare("ese") << ' ' << obj5->Compare("es") << ' ' << obj5->Compare("esea") << std::endl;
    MyString objs1("ese"), objs2("es"), objs3("esea");
    std::cout << obj5->Compare(objs1) << ' ' << obj5->Compare(objs2) << ' ' << obj5->Compare(objs3) << std::endl;
    std::cout << objs3.GetChar(2) << std::endl;
    MyString obj6("abcdefg");
    obj6.Insert(1, "xyz");
    std::cout << obj6.GetText() << std::endl;
    MyString obj7("abcdefg"), obj8("xyz");
    obj7.Insert(1, obj8);
    std::cout << obj7.GetText() << std::endl;
    MyString obj9("axybcxydcv");
    std::cout << obj9.Find("xy") << std::endl;
    std::cout << obj9.FindLast("xy") << std::endl;
    std::cout << obj9.Find("asdasda") << std::endl;
    return 0;
}
