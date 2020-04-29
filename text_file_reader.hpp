#ifndef TEXT_FILE_READER_HPP_INCLUDED
#define TEXT_FILE_READER_HPP_INCLUDED

#include "string.hpp"

class Text_File_Reader
{
public:
    Text_File_Reader() = delete;
    Text_File_Reader(const Text_File_Reader&) = delete;
    Text_File_Reader(Text_File_Reader&&) = delete;
    Text_File_Reader& operator =(const Text_File_Reader&) = delete;
    Text_File_Reader& operator =(Text_File_Reader&&) = delete;

    Text_File_Reader(const char* fileName);
    Text_File_Reader(DS::string& fileName);

    virtual ~Text_File_Reader();

    DS::string read();

private:
    FILE* file = NULL;
};

#endif // TEXT_FILE_READER_HPP_INCLUDED
