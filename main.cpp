#include <iostream>
#include <fstream>
#include <memory>
#include <cmath>
#include <string>

#include "list.hpp"
#include "string.hpp"
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
    dataStructures::string str("ergsfb", 3);
    std::cout << str << " size: " << str.size() << " capasity: " << str.capacity() << "\n";

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





    std::shared_ptr<Canvas> canvas = std::make_shared<Canvas>(std::make_shared<Loger>());
    std::shared_ptr<Define_List> defineList = std::make_shared<Define_List>();
    std::shared_ptr<Turtle> turtle = std::make_shared<Turtle>(canvas, defineList);
    std::shared_ptr<Command_Factory> factory = std::make_shared<Command_Factory>(turtle, canvas,
                                                                                 defineList);

    // ( size_of_canvas, canvas_color, left_down_point, right_up_point )
    std::shared_ptr<Command> def = factory->crCanvas_Definition({13, 13}, {4, 2, 1},
                                                                {0, 0}, {4, 4});

    defineList->addCanvasDefinition(def);
    defineList->applyCanvasDefinition();

    defineList->addPenDefinition(factory->crPen_Definition(3, {0, 2, 6}), 2);
    defineList->addPenDefinition(factory->crPen_Definition(4, {1, 3, 5}), 5);

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
