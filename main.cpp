#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <malloc.h>
#include "list.hpp"

class A
{
public:
    A(int source = -11): val(new int(source))
    {
        std::cout << "Simple constructor " << *val << "\n";
    }
    A(const A& s)
    {
        val = new int(*(s.val));
        std::cout << "Copy constructor " << *val << "\n";
    }
    A(A&& s)
    {
        val = s.val;
        std::cout << "Move constructor " << *val << "\n";
    }
    ~A()
    {
        std::cout << "Destructor\n";
        delete val;
    }

    int* val;
};

std::ostream& operator <<(std::ostream& os, A& source)
{
    return os << *(source.val) << "\t";
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

int main()
{
    size_t size1 = GetHeapSize();
    {
        dataStructures::list<A> list_1;
        A obj(33);
        //list_1.push_back(obj);
        list_1.push_back(A(34));
        list_1.push_front(A(0));
        list_1.push_back(A(35));
        list_1.push_front(A(1));
        list_1.push_back(A(36));
        dataStructures::list<A>::iterator it_1 = list_1.begin();
        for (; it_1 != list_1.end(); ++it_1)
            std::cout << *it_1 << " ";

        std::cout << "\n-----------------------\n";
        it_1 = list_1.begin();
        list_1.pop_back();
        list_1.pop_back();
        list_1.pop_front();
        it_1 = list_1.begin();
        for (; it_1 != list_1.end(); ++it_1)
            std::cout << *it_1 << " ";

        std::cout << "\n-----------------------\nlist_2:\n";

        dataStructures::list<A> list_2(std::move(list_1));
        list_2.push_front(A(90));
        list_2.push_back(A(100));
        for (dataStructures::list<A>::iterator it_2 = list_2.begin(); it_2 != list_2.end(); ++it_2)
            std::cout << *it_2 << " ";

        std::cout << "\n-----------------------\n";

//        dataStructures::list<A> list_2 = list_1;
//        for (dataStructures::list<A>::iterator it_2 = list_2.begin(); it_2 != list_2.end(); ++it_2)
//            std::cout << *it_2->val << " ";
//
//        std::cout << "\n-----------------------\n";
    }
    std::cout << GetHeapSize() - size1;
}
