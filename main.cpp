#include <iostream>
#include <fstream>
#include <memory>
#include <cmath>

#include "list.hpp"
#include "commands.hpp"
#include "canvas.hpp"
#include "turtle.hpp"
#include "composite.hpp"
#include "define_list.hpp"
#include "command_factory.hpp"
#include "command_handler.hpp"
#include "command_identifiers.hpp"
#include "parser.hpp"

int main()
{
//    std::ifstream is;
//    is.open("code.txt");
//    char* input;
//    is >> input;
//
////    std::shared_ptr<Composite> commandTree = std::make_shared<Composite>(); // contains a tree of Commands
//    std::shared_ptr<Define_List> defineList = std::make_shared<Define_List>(); // list of defines
//
//    std::shared_ptr<Canvas> canvas = std::make_shared<Canvas>();
//    std::shared_ptr<Turtle> turtle = std::make_shared<Turtle>(canvas, defineList);
//
////    std::shared_ptr<Command_Factory> factory = std::make_shared<Command_Factory>(turtle); // Command Fabric: will be create commands
////    std::shared_ptr<Command_Handler> handler = std::make_shared<Command_Handler>(commandTree, defineList, factory); // behaviour class, will be parse an input strings and push commands to the Composite and definitions to the defineList
////    Parser parser(input, handler);
////    parser.handle(); // commandTree has a tree of commands now
////
////    commandTree->execute();
//
//    std::ofstream os("pattern.bmp");
////    Uploader upl(c, os);
////    upl.upload();

    std::shared_ptr<Canvas> canvas = std::make_shared<Canvas>();
    std::shared_ptr<Define_List> defineList = std::make_shared<Define_List>();
    std::shared_ptr<Turtle> turtle = std::make_shared<Turtle>(canvas, defineList);
    std::shared_ptr<Command_Factory> factory = std::make_shared<Command_Factory>(turtle, canvas,
                                                                                 defineList);

    point_LL size = {13, 13};
    rgb color = {4, 2, 1};
    point_D p1 = {0, 0};
    point_D p2 = {4, 4};
    std::shared_ptr<Command> def = factory->crCanvas_Definition(size, color, p1, p2);

    defineList->addCanvasDefinition(def);
    defineList->applyCanvasDefinition();

    rgb color1 = {0, 2, 6};
    rgb color2 = {1, 3, 5};
    defineList->addPenDefinition(factory->crPen_Definition(3, color1), 2);
    defineList->addPenDefinition(factory->crPen_Definition(4, color2), 5);

    std::shared_ptr<Composite> algo = std::make_shared<Composite>(factory);
    algo->addCommand(factory->crPen_Selection(5));
    algo->addCommand(factory->crDo(3));
    algo->addCommand(factory->crMove(2));
    algo->addCommand(factory->crTurn(90));
    algo->finishBlok();
    algo->addCommand(factory->crTurn_East());
    algo->addCommand(factory->crTurn(45));
    algo->addCommand(factory->crMove(std::sqrt(2)));
    algo->addCommand(factory->crTurn(-45));
    algo->addCommand(factory->crMove(2));
    point_D p = {3.3333334, 0.666666667};
    algo->addCommand(factory->crMove_To(p));

    algo->execute();

    Command_Identifier* md = new Move_Id(algo, defineList, factory);

}
