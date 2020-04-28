#include <iostream>
#include <string>
#include <malloc.h>
#include "../list.hpp"

class A
{
public:
    A(const std::string& source): str(source)
    {
        std::cout << "Simple constructor " << str << "\n";
    }
    A(std::string&& source): str(std::move(source))
    {
        std::cout << "Simple constructor " << str << "\n";
    }
    A(const A& s): str(s.str)
    {
        std::cout << "Copy constructor " << str << "\n";
    }
    A(A&& s): str(std::move(s.str))
    {
        std::cout << "Move constructor " << str << "\n";
    }
    A& operator =(const A& s)
    {
        str = s.str;
        std::cout << "operator(const A&) " << str << "\n";
        return *this;
    }
    A& operator =(A&& s)
    {
        str = std::move(s.str);
        std::cout << "operator(A&&) " << str << "\n";
        return *this;
    }
    ~A()
    {
        std::cout << "Destructor\n";
    }

    std::string str;
};

std::ostream& operator <<(std::ostream& os, A& source)
{
    return os << source.str << "\t";
}

size_t GetHeapSize(void)
{
    struct _heapinfo hi = { 0 };
    size_t total = 0;
    while (_heapwalk(&hi) == _HEAPOK)
    {
        if (hi._useflag != _FREEENTRY)
            total += hi._size;
    }
    return total;
}

int list_tester()
{
    DS::list<A*> list;
    list.push_back(new A("11"));
    list.push_back(new A("12"));
    list.pop_front();
    list.push_back(new A("13"));
    list.push_back(new A("14"));
    for (auto i : list)
        std::cout << i << " ";

    size_t size1 = GetHeapSize();
    {
        DS::list<A> list_1;
        const A obj("33");
        list_1.push_back(obj);
        list_1.push_back(A("34"));
        list_1.push_front(A("0"));
        list_1.push_back(A("35"));
        list_1.push_front(A("1"));
        list_1.push_back(A("36"));
        list_1.push_front(obj);
        DS::list<A>::iterator it_1 = list_1.begin();
        for (; it_1 != list_1.end(); ++it_1)
            std::cout << *it_1 << " ";

        std::cout << "\n---1--------------------\n";
        it_1 = list_1.begin();
        list_1.pop_back();
        list_1.pop_back();
        list_1.pop_front();
        it_1 = list_1.begin();
        for (auto&& i : list_1)
            std::cout << i << " ";

        std::cout << "\n---2--------------------\n";

        DS::list<A> list_2((list_1));
        list_2.push_front(A("90"));
        list_2.push_back(A("100"));
        for (auto&& i : list_2)
            std::cout << i << " ";

        std::cout << "\n---3--------------------\n";
        DS::list<A>::iterator it_3 = list_2.begin();
        it_3++;it_3++;
        it_3 = list_2.insert(it_3, A("0000"));
        A ob_2("1111");
        it_3 = list_2.insert(it_3, ob_2);
        for (auto&& i : list_2)
            std::cout << i << " ";

        std::cout << "\nlast iterator: " << *it_3 << "\n";
        it_3++;
        it_3 = list_2.erase(it_3);

        for (auto&& i : list_2)
            std::cout << i << " ";

        std::cout << "\n---4--------------------\n";
        std::cout << "\nlast iterator: " << *it_3 << "\n";
        it_3 = list_2.erase(it_3);
        std::cout << "\nlast iterator: " << *it_3 << "\n";
        it_3 = list_2.erase(it_3);
        std::cout << "\nlast iterator: " << *it_3 << "\n";
        for (auto&& i : list_2)
            std::cout << i << " ";

        std::cout << "\n---5--------------------\n";
        DS::list<A> list_3;
        list_3 = list_2;
        for (auto&& i : list_3)
            std::cout << i << " ";

        std::cout << "\n";
        list_3 = list_1;
        for (auto&& i : list_3)
            std::cout << i << " ";

        std::cout << "\n-----------------------\n";
    }
    std::cout << "\nMEMORY LEAK: " << GetHeapSize() - size1 << "\n";
}
