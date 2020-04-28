#ifndef STRING_HPP_INCLUDED
#define STRING_HPP_INCLUDED

#include <iostream>

namespace DS // DataStructures
{
    class string
    {
    public:
        string();
        string(const char* s);
//        string(const char* s, size_t n);
        string(const string&);
        string(string&&);
        string& operator =(const string&);
        string& operator =(string&&);
        ~string();

        size_t size() const noexcept;
        size_t capacity() const noexcept;
        void clear() noexcept;
        const char* c_str() const noexcept;
        const char* data() noexcept;

        char& operator[] (size_t pos);
        char operator[] (size_t pos) const;
        string& operator +=(const string&);
        string& operator +=(char);
        string& operator +=(const char*);
        bool operator ==(const string&) const;
        bool operator !=(const string&) const;
        bool operator ==(const char*) const;
        bool operator !=(const char*) const;
        operator const char*();

    private:
        size_t _size;
        size_t _capacity;
        char* _buffer;
    };
};
DS::string operator +(DS::string str, const char* buf);
std::ostream& operator <<(std::ostream& os, const DS::string& str);

#endif // STRING_HPP_INCLUDED
