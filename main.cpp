#include <iostream>
#include <fstream>
#include <memory>

#include "list.hpp"
#include "commands.hpp"
#include "canvas.hpp"
#include "turtle.hpp"
#include "composite.hpp"
#include "define_list.hpp"
#include "command_factory.hpp"
#include "command_handler.hpp"
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

    //std::shared_ptr<Command> def = std::make_shared<Canvas_Definition>( canvas, turtle, {100, 100}, {4, 2, 1}, {-5.3, 3}, {10, 10} );
    //defineList->addCanvasDefinition(def);
    //defineList->applyCanvasDefinition();
    std::shared_ptr<Command> c = std::make_shared<Do>(turtle, 5);
    c->addCommand(std::make_shared<Move>(turtle, 3));
    c->execute();

}
