#include <iostream>
#include <fstream>
#include <list>
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
        std::cout << "Destructor\n\n";
        delete val;
    }

    int* val;
};

std::ostream& operator <<(std::ostream& os, A source)
{
    return os << *(source.val) << "\n";
}

int main()
{
    dataStructures::list<A> list_1;
    list_1.push_back(A(33));
    list_1.push_back(A(34));
    list_1.push_front(A(0));
    list_1.push_back(A(35));
    list_1.push_front(A(1));
    list_1.push_back(A(36));
    dataStructures::list<A>::iterator it_1 = list_1.begin();
    for (; it_1 != list_1.end(); ++it_1)
        std::cout << *it_1->val << " ";

    std::cout << "\n-----------------------\n";
    dataStructures::list<A>::iterator it_2 = list_1.begin();
    it_1 = list_1.begin();
    std::cout << list_1.size() << "\n";


}
