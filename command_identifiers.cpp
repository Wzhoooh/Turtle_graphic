#include <string.h>
#include <cstdlib>
#include <iostream>
#include <exception>
#include "command_identifiers.hpp"
#include "composite.hpp"
#include "define_list.hpp"
#include "command_factory.hpp"

bool Move_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{
    if (*wordIt != DS::string("Move_Id"))
        return false;
    else
        wordIt++;

    char* index = nullptr;
    double n = std::strtod(wordIt->c_str(), &index);
    if (index[0] == '\0')
    {
        _composite->addCommand(_factory->crMove(n));
        wordIt++;
    }
    else
    {
        DS::string errorMessage("ERROR: syntax error: ");
        errorMessage += wordIt->c_str();
        throw std::runtime_error(errorMessage.c_str());
    }
}
int Move_Id::getNumArguments() const { return 1; }

bool Move_To_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{

}
int Move_To_Id::getNumArguments() const { return 2; }

bool Turn_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{

}
int Turn_Id::getNumArguments() const { return 1; }

bool Turn_Left_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{

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
