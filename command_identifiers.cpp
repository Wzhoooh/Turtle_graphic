#include <cstdlib>
#include <iostream>
#include <exception>
#include "command_identifiers.hpp"
#include "composite.hpp"
#include "define_list.hpp"
#include "command_factory.hpp"
#include "primitives.hpp"

void increaseIt(DS::list<DS::string>::iterator& wordIt)
{
    auto copy = wordIt;
    ++copy;
    if (copy.isEnd())
    {
        char* index;
        for (; index != '\0'; --wordIt)
            std::strtod(wordIt->data(), &index);

        throw std::runtime_error("ERROR: no enough arguments for last command " + *wordIt);
    }
    else
        ++wordIt;
}

bool Move_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{
    if (*wordIt != "M")
        return false;

    increaseIt(wordIt);
    char* index = nullptr;
    double param = std::strtod(wordIt->data(), &index);
    if (*index != '\0')
        throw std::runtime_error("ERROR: syntax error: " + *wordIt);

    ++wordIt;

    _composite.addCommand(_factory.crMove(param));
    return true;
}

bool Move_To_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{
    if (*wordIt != "MT")
        return false;

    char* index = nullptr;
    double param[2];
    for (size_t i = 0; i < 2; ++i)
    {
        increaseIt(wordIt);
        param[i] = std::strtod(wordIt->data(), &index);
        if (*index != '\0')
            throw std::runtime_error("ERROR: syntax error: " + *wordIt);
    }

    ++wordIt;

    _composite.addCommand(_factory.crMove_To(point_D(param[0], param[1])));
    return true;
}

bool Turn_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{
    if (*wordIt != "TA")
        return false;

    increaseIt(wordIt);
    char* index = nullptr;
    double param;
    param = std::strtod(wordIt->data(), &index);
    if (*index != '\0')
        throw std::runtime_error("ERROR: syntax error: " + *wordIt);

    ++wordIt;

    _composite.addCommand(_factory.crTurn(param));
    return true;
}

bool Turn_Left_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{
    if (*wordIt != "TL")
        return false;

    ++wordIt;

    _composite.addCommand(_factory.crTurn_Left());
    return true;
}

bool Turn_Right_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{
    if (*wordIt != "TR")
        return false;

    ++wordIt;

    _composite.addCommand(_factory.crTurn_Right());
    return true;
}

bool Turn_South_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{
    if (*wordIt != "TS")
        return false;

    ++wordIt;

    _composite.addCommand(_factory.crTurn_South());
    return true;
}

bool Turn_North_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{
    if (*wordIt != "TN")
        return false;

    ++wordIt;

    _composite.addCommand(_factory.crTurn_North());
    return true;
}

bool Turn_West_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{
    if (*wordIt != "TW")
        return false;

    ++wordIt;

    _composite.addCommand(_factory.crTurn_West());
    return true;
}

bool Turn_East_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{
    if (*wordIt != "TE")
        return false;

    ++wordIt;

    _composite.addCommand(_factory.crTurn_East());
    return true;
}

bool Pen_Down_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{
    if (*wordIt != "PD")
        return false;

    ++wordIt;

    _composite.addCommand(_factory.crPen_Down());
    return true;
}

bool Pen_Up_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{
    if (*wordIt != "PU")
        return false;

    ++wordIt;

    _composite.addCommand(_factory.crPen_Up());
    return true;
}

bool Do_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{
    if (*wordIt != "DO")
        return false;

    increaseIt(wordIt);
    char* index = nullptr;
    int param = std::strtoll(wordIt->data(), &index, 10);
    if (*index != '\0' || param < 0)
        throw std::runtime_error("ERROR: syntax error: " + *wordIt);

    ++wordIt;

    _composite.addCommand(_factory.crDo(param));
    return true;
}

bool Again_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{
    if (*wordIt != "AGAIN")
        return false;

    ++wordIt;

    _composite.finishBlok();
    return true;
}

bool Pen_Definition_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{
    if (*wordIt != "DEFPEN")
        return false;

    char* index = nullptr;
    int penNumber = 0;
    double penWidth = 1;
    char color[3] = { 0 };

    increaseIt(wordIt);
    // number of pen
    penNumber = std::strtoll(wordIt->data(), &index, 10);
    if (*index != '\0')
        throw std::runtime_error("ERROR: syntax error: " + *wordIt);

    increaseIt(wordIt);
    // width of pen
    if (*wordIt != "SIZE")
        throw std::runtime_error("ERROR: no pen size");

    increaseIt(wordIt);
    penWidth = std::strtod(wordIt->data(), &index);
    if (*index != '\0')
        throw std::runtime_error("ERROR: syntax error: " + *wordIt);

    increaseIt(wordIt);

    // pen color
    if (*wordIt != "RGB")
        throw std::runtime_error("ERROR: no pen color specifier");

    for (size_t i = 0; i < 3; ++i)
    {
        increaseIt(wordIt);
        color[i] = std::strtoll(wordIt->data(), &index, 10);
        if (*index != '\0')
            throw std::runtime_error("ERROR: syntax error: " + *wordIt);
    }

    increaseIt(wordIt);

    if (*wordIt != "END")
        throw std::runtime_error("ERROR: too many arguments for pen definition");

    ++wordIt;

    rgb colorRgb(color[0], color[1], color[2]);
    _defineList.addPenDefinition(_factory.crPen_Definition(penWidth, colorRgb), penNumber);
    return true;
}

bool Pen_Selection_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{
    if (*wordIt != "SELPEN")
        return false;

    increaseIt(wordIt);

    char* index = nullptr;
    int param = std::strtoll(wordIt->data(), &index, 10);
    if (*index != '\0')
        throw std::runtime_error("ERROR: syntax error: " + *wordIt);

    ++wordIt;

    _composite.addCommand(_factory.crPen_Selection(param));
    return true;
}

bool Canvas_Definition_Id::pushCommand(DS::list<DS::string>::iterator& wordIt)
{
    if (*wordIt != "CANVAS")
        return false;

    char* index = nullptr;
    long long canavasSize[2] = { 0 };
    char color[3] = { 0 };
    double downLeft[2] = { 0 };
    double upRight[2] = { 1, 1 };

    // this cycle is only to have one finish point
    for (int i = 0; i < 1; ++i)
    {
        // set size of canvas(in pixels)
        for (size_t i = 0; i < 2; ++i)
        {
            increaseIt(wordIt);

            canavasSize[i] = std::strtoll(wordIt->data(), &index, 10);
            if (*index != '\0')
                throw std::runtime_error("ERROR: syntax error: " + *wordIt);
        }
        increaseIt(wordIt);

        // set color(in rgb)
        if (*wordIt != "RGB")
            throw std::runtime_error("ERROR: no canvas color specifier");

        for (size_t i = 0; i < 3; ++i)
        {
            increaseIt(wordIt);

            color[i] = std::strtoll(wordIt->data(), &index, 10);
            if (*index != '\0')
                throw std::runtime_error("ERROR: syntax error: " + *wordIt);
        }
        increaseIt(wordIt);

        // set view
        if (*wordIt == "END") break;
        if (*wordIt != "VIEW")
            throw std::runtime_error("ERROR: no canvas view");

        for (size_t i = 0; i < 2; ++i)
        {
            increaseIt(wordIt);

            downLeft[i] = std::strtod(wordIt->data(), &index);
            if (*index != '\0')
                throw std::runtime_error("ERROR: syntax error: " + *wordIt);
        }
        for (size_t i = 0; i < 2; ++i)
        {
            increaseIt(wordIt);

            upRight[i] = std::strtod(wordIt->data(), &index);
            if (*index != '\0')
                throw std::runtime_error("ERROR: syntax error: " + *wordIt);
        }
        increaseIt(wordIt);
    }

    if (*wordIt != "END")
        throw std::runtime_error("ERROR: too many arguments for canvas definition");

    ++wordIt;

    point_LL canavasSizeStruct(canavasSize[0], canavasSize[1]);
    rgb colorStruct(color[0], color[1], color[2]);
    point_D leftDownStruct(downLeft[0], downLeft[1]);
    point_D rightUpStruct(upRight[0], upRight[1]);

    _defineList.addCanvasDefinition(_factory.crCanvas_Definition(canavasSizeStruct,
                                    colorStruct, leftDownStruct, rightUpStruct));
    _defineList.applyCanvasDefinition();
    return true;
}

bool Comment::pushCommand(DS::list<DS::string>::iterator& wordIt)
{
    if (*wordIt != "/*")
        return false;

    for (; !wordIt.isEnd() && *wordIt != "*/"; ++wordIt)
        ;

    if (wordIt.isEnd())
        throw std::runtime_error("ERROR: no */");

    ++wordIt;

    return true;
}
