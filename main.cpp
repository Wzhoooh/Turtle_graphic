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

}
