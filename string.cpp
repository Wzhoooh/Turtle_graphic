#include <iostream>
#include <string.h>
#include "string.hpp"

using namespace DS;

const size_t SIZE_NULL_CAPACITY = 15;

size_t getCapacity(size_t size)
{
    return size * 3 / 2;
}

string::string(): _size(0), _capacity(SIZE_NULL_CAPACITY), _buffer(nullptr)
{
    _buffer = new char[_capacity];
}
string::string(const char* s): _size(strlen(s)), _capacity(SIZE_NULL_CAPACITY)
{
    if (_size > SIZE_NULL_CAPACITY)
        _capacity = getCapacity(_size);

    _buffer = new char[_capacity];
    for (size_t i = 0; i < _size; i++)
        _buffer[i] = s[i];
}
string::string(const char* s, size_t n): _size(n), _capacity(SIZE_NULL_CAPACITY)
{
    if (_size > SIZE_NULL_CAPACITY)
        _capacity = getCapacity(_size);

    _buffer = new char[_capacity];
    for (size_t i = 0; i < _size; i++)
        _buffer[i] = s[i];
}
string::string(const string& s): _size(s._size), _capacity(s._capacity)
{
    _buffer = new char[_capacity];
    for (size_t i = 0; i < _size; i++)
        _buffer[i] = s[i];
}
string::string(string&& s): _size(s._size), _capacity(s._capacity)
{
    _buffer = s._buffer;
    s._size = 0;
    s._capacity = 0;
}
string& string::operator =(const string& s)
{
    if (_capacity < s._size)
    {
        delete [] _buffer;
        _capacity = getCapacity(s._size);
        _buffer = new char[_capacity];
    }

    _size = s._size;
    for (size_t i = 0; i < _size; i++)
        _buffer[i] = s[i];
}
string& string::operator =(string&& s)
{
    _size = s._size;
    _capacity = s._capacity;
    delete [] _buffer;
    _buffer = s._buffer;

    s._size = 0;
    s._capacity = 0;
}
string::~string()
{
    delete [] _buffer;
}

size_t string::size() const noexcept
{
    return _size;
}
size_t string::capacity() const noexcept
{
    return _capacity;
}
void string::clear() noexcept
{
    delete [] _buffer;
    _size = 0;
    _capacity = 0;
}
const char* string::c_str() const noexcept
{
    char* str = new char[_size+1];
    for (size_t i = 0; i < _size; i++)
        str[i] = _buffer[i];

    str[_size] = '\0';
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
    if (_size + s.size() > _capacity)
    {
        string copy(*this);
        delete [] _buffer;
        _capacity = getCapacity(_size + s.size());
        _buffer = new char[_capacity];

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
    if (_size + 1 > _capacity)
    {
        string copy(*this);
        delete [] _buffer;
        _capacity = getCapacity(_size + 1);
        _buffer = new char[_capacity];

        for (size_t i = 0; i < _size; i++)
            _buffer[i] = copy[i];
    }

    _buffer[_size] = c;

    _size += 1;
    return *this;
}
string& string::operator +=(const char* s)
{
    size_t sizeS = strlen(s);

    if (_size + sizeS > _capacity)
    {
        string copy(*this);
        delete [] _buffer;
        _capacity = getCapacity(_size + sizeS);
        _buffer = new char[_capacity];

        for (size_t i = 0; i < _size; i++)
            _buffer[i] = copy[i];
    }

    for (size_t i = 0; i < sizeS; i++)
        _buffer[_size+i] = s[i];

    _size += sizeS;
    return *this;
}
bool string::operator ==(const string& s) const
{
    if (_size != s.size())
        return false;

    for (size_t i = 0; i < _size; i++)
        if (_buffer[i] != s[i])
            return false;

    return true;
}

bool string::operator !=(const string& s) const
{
    return !(*this == s);
}

std::ostream& operator <<(std::ostream& os, const string& str)
{
    for (size_t i = 0; i < str.size(); i++)
        os << str[i];

    return os;
}





