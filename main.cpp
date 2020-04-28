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

#define p l.push_back

int main()
{
//    DS::string str("ergsfb", 3);
//    std::cout << str << " size: " << str.size() << " capasity: " << str.capacity() << "\n";

//    std::ifstream is;
//    is.open("code.txt");
//    char* input;
//    is >> input;
//
////    std::shared);tr<Composite> commandTree = std::make_shared<Composite>(); // contains a tree of Commands
//    std::shared);tr<Define_List> defineList = std::make_shared<Define_List>(); // list of defines
//
//    std::shared);tr<Canvas> canvas = std::make_shared<Canvas>();
//    std::shared);tr<Turtle> turtle = std::make_shared<Turtle>(canvas, defineList);
//
////    std::shared);tr<Command_Factory> factory = std::make_shared<Command_Factory>(turtle); // Command Fabric: will be create commands
////    std::shared);tr<Command_Handler> handler = std::make_shared<Command_Handler>(commandTree, defineList, factory); // behaviour class, will be parse an input strings and push commands to the Composite and definitions to the defineList
////    Parser parser(input, handler);
////    parser.handle(); // commandTree has a tree of commands now
////
////    commandTree->"execute();
//
//    std::ofstream os("pattern.bmp");
////    Uploader upl(c, os);
////    upl.upload();





    Canvas canvas(std::move(Loger()));
    Define_List defineList;
    Turtle turtle(canvas, defineList);
    Command_Factory factory(turtle, canvas, defineList);
    Composite algo(factory);

    DS::list<DS::string> l;
    p("CANVAS");
        p("5");
        p("5");

        p("10");
        p("11");
        p("12");

        p("3");
        p("3");
        p("8");
        p("8");
    p("END");

    p("DEFPEN"); p("15");
        p("22");
        p("1");
        p("2");
        p("3");
    p("END");

    p("M"); p("1");
    p("MT"); p("2.5"); p("3.5");
    p("T"); p("90");
    p("TL");
    p("TR");
    p("TS");
    p("TN");
    p("TW");
    p("M"); p("4");
    p("TE");
    p("PD");
    p("PU");

    p("SELPEN"); p("15");

    p("DO"); p("3");
        p("M"); p("2");
        p("DO"); p("5");
            p("TR");
            p("M"); p("3");
        p("AGAIN");
    p("AGAIN");

    p("MT"); p("10"); p("10");


    Command_Handler c(algo, defineList, factory);
    c.handle(l);

    algo.execute();
//
//    defineList.addPenDefinition(factory.crPen_Definition(3, {0, 2, 6}), 2);
//    defineList.addPenDefinition(factory.crPen_Definition(4, {1, 3, 5}), 5);
//
//    algo.addCommand(factory.crPen_Selection(5));
//    algo.addCommand(factory.crDo(3));
//    algo.addCommand(factory.crMove(2));
//    algo.addCommand(factory.crTurn(90));
//    algo.finishBlok();
//    algo.addCommand(factory.crTurn_East());
//    algo.addCommand(factory.crTurn(45));
//    algo.addCommand(factory.crMove(std::sqrt(2)));
//    algo.addCommand(factory.crTurn(-45));
//    algo.addCommand(factory.crMove(2));
//    algo.addCommand(factory.crMove_To({3.3333334, 0.666666667}));
//    algo.execute();
//
//    //Command_Identifier* md = new Move_Id(algo, defineList, factory);

}
