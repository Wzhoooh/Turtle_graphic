#include <iostream>
#include <fstream>
#include <sstream>

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

//#define p l.push_back

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





    Canvas canvas(std::move(Round_Pen_Drawer()));
    Define_List defineList;
    Turtle turtle(canvas, defineList);
    Command_Factory factory(turtle, canvas, defineList);
    Composite composite(factory);

    const char* s = "DEFPEN 33 SIZE 10 RGB 193 0 32 END SELPEN 33 CANVAS 2960 1080 RGB 204 195 31 VIEW 0 0 1000 1000 END   PD TA 45 M 500 DO 4 TL M 200 AGAIN";
    Parser p(s, Command_Handler(composite, defineList, factory));
std::cout << "---1---\n";
    p.handle();
std::cout << "---2---\n";
    composite.execute();
std::cout << "---3---\n";
    canvas.uploadToBmp("patterns/1");
//
//    const rgb* buf = canvas.getBuffer();
//    for (int y = canvas.getSizeBitMap().y-1; y >= 0 ; y--)
//    {
//        for (size_t x = 0; x < canvas.getSizeBitMap().x; x++)
//        {
//            std::stringstream ss;
//            ss << "(" << (int)buf[x + y * canvas.getSizeBitMap().x].red << ", " << (int)buf[x + y * canvas.getSizeBitMap().x].green << ", " << (int)buf[x + y * canvas.getSizeBitMap().x].blue << ")";
//            std::cout.width(13);
//            std::cout.flags(std::ios::left);
//            std::cout << ss.str();
//        }
//        std::cout << "\n";
//    }

//
//    DS::list<DS::string> l;
//    p("CANVAS");
//        p("5");
//        p("5");
//
//        p("10");
//        p("11");
//        p("12");
//
//        p("-2");
//        p("-2");
//        p("3");
//        p("3");
//    p("END");
//
//    p("DEFPEN"); p("15");
//        p("22");
//        p("1");
//        p("2");
//        p("3");
//    p("END");
//
//    p("M"); p("1");
//    p("TR");
//    p("M"); p("1");
//    p("T"); p("90");
//    p("M"); p("1");
//    p("MT"); p("2.5"); p("1.5");
////    p("T"); p("90");
////    p("TL");
////    p("TR");
////    p("TS");
////    p("TN");
////    p("TW");
////    p("M"); p("4");
////    p("TE");
////    p("PD");
////    p("PU");
////
////    p("SELPEN"); p("15");
////
////    p("DO"); p("3");
////        p("M"); p("2");
////        p("DO"); p("5");
////            p("TR");
////            p("M"); p("3");
////        p("AGAIN");
////    p("AGAIN");
////
////    p("MT"); p("10"); p("10");
//
//
//    Command_Handler c(algo, defineList, factory);
//    c.handle(l);
//
//    algo.execute();
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
