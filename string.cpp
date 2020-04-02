#include <string.h>
#include "string.hpp"

using namespace dataStructures;

string::string(): _size(0), _capasity(0), _buffer(nullptr){}
string::string(const char* s): _size(0), _capasity(0)
{
    for (size_t i = 0; s[i] != '\0'; i++)
        _size++;

    _capasity = _size * 2;
    _buffer = new char(_capasity);
    for (size_t i = 0; i < _size; i++)
        _buffer[i] = s[i];
}
string::string(const string& s): _size(s._size), _capasity(s._capasity)
{
    _buffer = new char(_capasity);
    for (size_t i = 0; i < _size; i++)
        _buffer[i] = s[i];
}
string::string(string&& s): _size(s._size), _capasity(s._capasity)
{
    _buffer = s._buffer;
    delete [] s._buffer;
    s._size = 0;
    s._capasity = 0;
}
string& string::operator =(const string& s)
{
    _size = s._size;
    _capasity = s._capasity;
    delete [] _buffer;
    _buffer = new char(_capasity);
    for (size_t i = 0; i < _size; i++)
        _buffer[i] = s[i];
}
string& string::operator =(string&& s)
{
    _size = s._size;
    _capasity = s._capasity;
    delete [] _buffer;
    _buffer = s._buffer;
    delete [] s._buffer;
    s._size = 0;
    s._capasity = 0;
}
string::~string()
{
    delete [] _buffer;
}

size_t string::size() const noexcept
{
    return _size;
}
void string::clear() noexcept
{
    delete [] _buffer;
    _size = 0;
    _capasity = 0;
}
const char* string::c_str() const noexcept
{
    char* str = new char(_size+1);
    for (size_t i = 0; i < _size; i++)
        str[i] = _buffer[i];

    str[_size+1] = '\0';
    return str;
}
const char* string::data() const noexcept
{
    return _buffer;
}

char& string::operator[] (size_t pos)
{
    return _buffer[pos];
}
char string::operator[] (size_t pos) const
{
    return _buffer[pos];
}

string& string::operator +=(const string& s)
{
    if (_size + s.size() >= _capasity)
    {
        string copy(*this);
        delete [] _buffer;
        _capasity = (_size + s.size()) * 2;
        _buffer = new char(_capasity);

        for (size_t i = 0; i < _size; i++)
            _buffer[i] = copy[i];
    }

    for (size_t i = 0; i < s.size(); i++)
        _buffer[_size+i] = s[i];

    _size += s.size();
    return *this;
}
string& string::operator +=(char c)
{
     if (_size + 1 >= _capasity)
    {
        string copy(*this);
        delete [] _buffer;
        _capasity = (_size + 1) * 2;
        _buffer = new char(_capasity);

        for (size_t i = 0; i < _size; i++)
            _buffer[i] = copy[i];
    }

    _buffer[_size] = c;

    _size += 1;
    return *this;
}
string& string::operator +=(const char* s)
{
    size_t sizeS = 0;
    for (; s[sizeS] != '\0'; sizeS++)
        ;

    if (_size + sizeS >= _capasity)
    {
        string copy(*this);
        delete [] _buffer;
        _capasity = (_size + sizeS) * 2;
        _buffer = new char(_capasity);

        for (size_t i = 0; i < _size; i++)
            _buffer[i] = copy[i];
    }

    for (size_t i = 0; i < sizeS; i++)
        _buffer[_size+i] = s[i];

    _size += sizeS;
    return *this;
}
bool string::operator ==(const string& s)
{
    if (_size != s.size())
        return false;

    for (size_t i = 0; i < _size; i++)
        if (_buffer[i] != s[i])
            return false;

    return true;
}

std::ostream& operator <<(std::ostream& os, const string& str)
{
    for (size_t i = 0; i < str.size(); i++)
        os << str[i];

    return os;
}





