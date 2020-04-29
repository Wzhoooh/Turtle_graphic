#include <string.h>
#include "canvas.hpp"
#include "string.hpp"

#pragma pack(1)

const int BYTESPERPIXEL = 3;

struct BITMAPFILEHEADER
{
    char type1;                    // 'B'
    char type2;                    // 'M'
    unsigned long fileSize;        // ������ ����� � ������
    short reserved1;               // 0
    short reserved2;               // 0
    unsigned long pixelsOffset;    // �������� ������� �������� ������������ ������ ����� � ������
};

struct BITMAPCOREHEADER
{
    unsigned long structureSize;   // 12
    unsigned short widthPixels;    // ������ �������� � ��������
    unsigned short heightPixels;   // ������ �������� � ��������
    unsigned short numberOfPlanes; // 1
    unsigned short bitsPerPixel;   // ��� �� ������� (� ��� 24)
};

// ������� ������������ ��������; ������ ����� ������ ���������� � ������
// �������� 4 ����� (������ ������� ������� �� 0)
// ������ ������������ ��-�������, ������� � ������ (������������� Height)
// ������ � ������� (������������� Height) �� �������������� � ���� ������� ���������
// ����� ������������ � �������: Blue, Green, Red

#pragma pack()

void Bit_Map::uploadToBmp(const char* fileName)
{
    static const char bmpExt[] = ".bmp";
    size_t extLen = strlen(bmpExt);
    size_t strLen = strlen(fileName);
    // ��� ����� ��� �����
    char buf[strLen+extLen+1];

    // ��������� ������������ �� ��� �� �������� ����������
    if ((strLen < extLen) ||
        (strcmp(fileName+strLen-extLen, bmpExt) != 0))
    {
        // ��������� ���������� � ����� �����
        strcpy(buf, fileName);
        strcat(buf, bmpExt);
        fileName = buf;
    }

    FILE* file = fopen(fileName, "wb");
    if (NULL == file)
        throw std::runtime_error("ERROR: can't open file " + DS::string(fileName));

    static_assert(sizeof(rgb) == BYTESPERPIXEL, "Only three bytes per pixel possible");

    // ���������� ��������� �����
    struct BITMAPFILEHEADER header1;
    struct BITMAPCOREHEADER header2;
    static const unsigned char zeroPadding[4] = { 0 };

    // ����� ����� ������ � ������
    size_t rowSize = BYTESPERPIXEL*_size.x;
    // ������ ���������� � ������
    size_t paddingSize = (4 - rowSize%4) % 4;
    // ����� ����� ������ � ������ ������ � �����������
    size_t rowSizeWithPadding = rowSize+paddingSize;

    // ��������� ���������
    header1.type1 = 'B';
    header1.type2 = 'M';
    header1.reserved1 = 0;
    header1.reserved2 = 0;
    header1.pixelsOffset = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPCOREHEADER);
    header1.fileSize = header1.pixelsOffset + rowSizeWithPadding*_size.y;

    header2.structureSize = 12;
    header2.widthPixels = _size.x;
    header2.heightPixels = _size.y;
    header2.numberOfPlanes = 1;
    header2.bitsPerPixel = 24;

    if ((1 != fwrite(&header1, sizeof(header1), 1, file)) ||
        (1 != fwrite(&header2, sizeof(header2), 1, file)))
        throw std::runtime_error("ERROR: can't write file header");

    for (unsigned int i = 0; i < _size.y; i++)
    {
        if ((1 != fwrite(_buffer+_size.x*i, rowSize, 1, file)) ||
            (paddingSize != fwrite(zeroPadding, 1, paddingSize, file)))
            throw std::runtime_error("ERROR: can't write file data");
    }

    fclose(file);
}
