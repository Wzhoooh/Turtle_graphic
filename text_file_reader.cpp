#include "text_file_reader.hpp"

Text_File_Reader::Text_File_Reader(const char* fileName)
{
    file = fopen(fileName, "rb");
    if (NULL == file)
        throw std::runtime_error("can't open file " + DS::string(fileName));
}

Text_File_Reader::Text_File_Reader(DS::string& fileName):
    Text_File_Reader(fileName.data()){}

Text_File_Reader::~Text_File_Reader()
{
    if (NULL != file)
        fclose(file);
}

DS::string Text_File_Reader::read()
{
    if (fseek(file, 0, SEEK_END))
        throw std::runtime_error("can't seek the file");
    long fileLen = ftell(file);
    if (fileLen == -1)
        throw std::runtime_error("can't get file length");

    rewind(file);

    long bufLen = fileLen+1;
    char *buf = new char[bufLen];

    fileLen = fread(buf, 1, bufLen, file);

    if (ferror(file) || !feof(file))
        throw std::runtime_error("Can't read file");

    // remove '\0'  and '\n'
    for (long i = 0; i < fileLen; ++i)
    {
        if (buf[i] == '\0' || buf[i] == 13 || buf[i] == '\n' || buf[i] == 9 || buf[i] == '\t')
            buf[i] = ' ';
    }

    buf[fileLen] = '\0';
    DS::string str(buf);
    delete[] buf;
    return str;
}
