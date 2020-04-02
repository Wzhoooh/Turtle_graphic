#include <string.h>
#include <cstdlib>
#include "command_identifiers.hpp"

void nullBuffer(char* str, int size)
{
    for (int i = 0; i < size; i++)
        str[i] = 0;
}

int getSizeOfWord(const char* str)
{
    int i = 0;
    for (; str[i] != ' ' && str[i] != '\n' && str[i] != '\0'; i++)
        ;

    return i;
}

void copyWord(char* strFrom, char* strTo)
{
    int i = 0;
    for (; strFrom[i] != ' ' && strFrom[i] != '\n' && strFrom[i] != '\0'; i++)
        strTo[i] = strFrom[i];

    strTo[i] = '\0';
}

bool Move_Id::pushCommand(const char* str)
{

}
bool Move_To_Id::pushCommand(const char* str)
{

}
bool Turn_Id::pushCommand(const char* str)
{

}
bool Turn_Left_Id::pushCommand(const char* str)
{

}
bool Turn_Right_Id::pushCommand(const char* str)
{

}
bool Turn_South_Id::pushCommand(const char* str)
{

}
bool Turn_North_Id::pushCommand(const char* str)
{

}
bool Turn_West_Id::pushCommand(const char* str)
{

}
bool Turn_East_Id::pushCommand(const char* str)
{

}
bool Pen_Down_Id::pushCommand(const char* str)
{

}
bool Pen_Up_Id::pushCommand(const char* str)
{

}
bool Do_Id::pushCommand(const char* str)
{

}
bool Pen_Definition_Id::pushCommand(const char* str)
{

}
bool Pen_Selection_Id::pushCommand(const char* str)
{

}
bool Canvas_Definition_Id::pushCommand(const char* str)
{

}
