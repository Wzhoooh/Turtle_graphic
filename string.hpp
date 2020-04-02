#ifndef STRING_HPP_INCLUDED
#define STRING_HPP_INCLUDED

#include <iostream>

namespace dataStructures
{

    class string
    {
    public:
        string();
        string(const char* s);
        string(const string&);
        string(string&&);
        string& operator =(const string&);
        string& operator =(string&&);
        ~string();

        size_t size() const noexcept;
        void clear() noexcept;
        const char* c_str() const noexcept;
        const char* data() const noexcept;

        char& operator[] (size_t pos);
        char operator[] (size_t pos) const;
        string& operator +=(const string&);
        string& operator +=(char);
        string& operator +=(const char*);
        bool operator ==(const string&);

    private:
        size_t _size;
        size_t _capasity;
        char* _buffer;
    };

    std::ostream& operator <<(std::ostream& os, const string& str);

};

#endif // STRING_HPP_INCLUDED
