#include <memory>
#include "command_handler.hpp"
#include "define_list.hpp"
#include "composite.hpp"
#include "command_factory.hpp"
#include "command_identifiers.hpp"

Command_Handler::Command_Handler(Composite* composite, Define_List* defineList,
    Command_Factory* factory): _composite(composite), _defineList(defineList),
    _factory(factory){}

void Command_Handler::handle(DS::list<DS::string>& list)
{
    DS::list<std::shared_ptr<Command_Identifier>> identifiers;
    identifiers.push_back(std::make_shared<Move_Id>(_composite, _defineList, _factory));
    identifiers.push_back(std::make_shared<Move_To_Id>(_composite, _defineList, _factory));
    identifiers.push_back(std::make_shared<Turn_Id>(_composite, _defineList, _factory));
    identifiers.push_back(std::make_shared<Turn_Left_Id>(_composite, _defineList, _factory));
    identifiers.push_back(std::make_shared<Turn_Right_Id>(_composite, _defineList, _factory));
    identifiers.push_back(std::make_shared<Turn_South_Id>(_composite, _defineList, _factory));
    identifiers.push_back(std::make_shared<Turn_North_Id>(_composite, _defineList, _factory));
    identifiers.push_back(std::make_shared<Turn_West_Id>(_composite, _defineList, _factory));
    identifiers.push_back(std::make_shared<Turn_East_Id>(_composite, _defineList, _factory));
    identifiers.push_back(std::make_shared<Pen_Down_Id>(_composite, _defineList, _factory));
    identifiers.push_back(std::make_shared<Pen_Up_Id>(_composite, _defineList, _factory));
    identifiers.push_back(std::make_shared<Do_Id>(_composite, _defineList, _factory));
    identifiers.push_back(std::make_shared<Again_Id>(_composite, _defineList, _factory));
    identifiers.push_back(std::make_shared<Pen_Selection_Id>(_composite, _defineList, _factory));
    identifiers.push_back(std::make_shared<Pen_Definition_Id>(_composite, _defineList, _factory));
    identifiers.push_back(std::make_shared<Canvas_Definition_Id>(_composite, _defineList, _factory));

    for (auto it = list.begin(); it != list.end();)
    {
        bool isCorrect = false;
        for (auto&& id : identifiers)
            if (isCorrect = id->pushCommand(it))
                break;

        if (!isCorrect)
            throw std::runtime_error("ERROR: unknown command: " + *it);
    }
}
