#ifndef COMMANDS_IDENTIFICATORS_HPP_INCLUDED
#define COMMANDS_IDENTIFICATORS_HPP_INCLUDED

#include <memory>
class Composite;
class Define_List;
class Command_Factory;

class Command_Identifier
{
public:
    virtual bool pushCommand(const char*) = 0; // pushes command to composite or defineList from factory if command is correct
};

class Move_Id: public Command_Identifier
{
public:
    Move_Id(std::shared_ptr<Composite> composite, std::shared_ptr<Define_List> defineList,
                    std::shared_ptr<Command_Factory> factory);
    bool pushCommand(const char*) override;

private:
    std::shared_ptr<Composite> _composite;
    std::shared_ptr<Define_List> _defineList;
    std::shared_ptr<Command_Factory> _factory;
};

class Move_To_Id: public Command_Identifier
{
public:
    Move_To_Id(std::shared_ptr<Composite> composite, std::shared_ptr<Define_List> defineList,
                    std::shared_ptr<Command_Factory> factory);
    bool pushCommand(const char*) override;

private:
    std::shared_ptr<Composite> _composite;
    std::shared_ptr<Define_List> _defineList;
    std::shared_ptr<Command_Factory> _factory;
};

#endif // COMMANDS_IDENTIFICATORS_HPP_INCLUDED
