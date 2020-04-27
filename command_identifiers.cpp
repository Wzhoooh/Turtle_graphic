#include <string.h>
#include <cstdlib>
#include <iostream>
#include <exception>
#include "command_identifiers.hpp"
#include "composite.hpp"
#include "define_list.hpp"
#include "command_factory.hpp"
#include "primitives.hpp"

bool Move_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{
    if (*wordIt != DS::string("M"))
        return false;
    else
        ++wordIt;

    if (wordIt.isEnd())
        throw std::runtime_error("ERROR: not enough arguments for command M");

    char* index = nullptr;
    double param = std::strtod(wordIt->c_str(), &index);
    if (*index != '\0')
    {
        throw std::runtime_error("ERROR: syntax error: " + *wordIt);
    }
    ++wordIt;

    _composite->addCommand(_factory->crMove(param));
    return true;
}
int Move_Id::getNumArguments() const { return 1; }

bool Move_To_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{
    if (*wordIt != DS::string("MT"))
        return false;

    ++wordIt;

    if (wordIt.isEnd())
        throw std::runtime_error("ERROR: not enough arguments for command MT");

    char* index = nullptr;
    double param[2];
    for (size_t i = 0; i < 2; i++)
    {
        param[i] = std::strtod(wordIt->c_str(), &index);
        if (*index != '\0')
        {
            throw std::runtime_error("ERROR: syntax error: " + *wordIt);
        }
        ++wordIt;
    }

    _composite->addCommand(_factory->crMove_To(point_D(param[0], param[1])));
    return true;
}
int Move_To_Id::getNumArguments() const { return 2; }

bool Turn_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{
    if (*wordIt != DS::string("T"))
        return false;

    ++wordIt;

    if (wordIt.isEnd())
        throw std::runtime_error("ERROR: not enough arguments for command T");

    char* index = nullptr;
    double param;
    param = std::strtod(wordIt->c_str(), &index);
    if (*index != '\0')
    {
        throw std::runtime_error("ERROR: syntax error: " + *wordIt);
    }
    ++wordIt;

    _composite->addCommand(_factory->crTurn(param));
    return true;
}
int Turn_Id::getNumArguments() const { return 1; }

bool Turn_Left_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{
    if (*wordIt != DS::string("TL"))
        return false;

    ++wordIt;

    _composite->addCommand(_factory->crTurn_Left());
    return true;
}
int Turn_Left_Id::getNumArguments() const { return 0; }

bool Turn_Right_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{

}
int Turn_Right_Id::getNumArguments() const { return 0; }

bool Turn_South_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{

}
int Turn_South_Id::getNumArguments() const { return 0; }

bool Turn_North_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{

}
int Turn_North_Id::getNumArguments() const { return 0; }

bool Turn_West_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{

}
int Turn_West_Id::getNumArguments() const { return 0; }

bool Turn_East_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{

}
int Turn_East_Id::getNumArguments() const { return 0; }

bool Pen_Down_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{

}
int Pen_Down_Id::getNumArguments() const { return 0; }

bool Pen_Up_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{

}
int Pen_Up_Id::getNumArguments() const { return 0; }

bool Do_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{

}
int Do_Id::getNumArguments() const { return 0; }

bool Again_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{

}
int Again_Id::getNumArguments() const { return 0; }

bool Pen_Definition_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{

}
int Pen_Definition_Id::getNumArguments() const { return -1; }

bool Pen_Selection_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{

}
int Pen_Selection_Id::getNumArguments() const { return 1; }

bool Canvas_Definition_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{

}
int Canvas_Definition_Id::getNumArguments() const { return -1; }
