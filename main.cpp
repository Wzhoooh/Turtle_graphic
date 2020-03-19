#include <iostream>
#include <fstream>
#include <memory>

#include "list.hpp"
#include "commands.hpp"
#include "canvas.hpp"
#include "turtle.hpp"

int main()
{
    std::ifstream is;
    is.open("code.txt");
    char* input;
    is >> input;

    unsigned long long lenVertical = 100, lenGorisontal = 100;
    std::shared_ptr<Canvas> canvas = std::make_shared<Canvas>(lenVertical, lenGorisontal);
    std::shared_ptr<Turtle> turtle = std::make_shared<Turtle>(canvas);

    std::shared_ptr<Composite> commandTree = std::make_shared<Composite>(); // contains a tree of Commands
    std::shared_ptr<Command_Fabric> fabric = std::make_shared<Command_Fabric>(turtle); // Command Fabric: will be create commands
    std::shared_ptr<Command_Handler> handler = std::make_shared<Command_Handler>(commandTree); // behaviour class, will be parse an input strings and push commands to the Composite
    Parser parser(input);
    parser->handle(); // commandTree has a tree of commands now

    commandTree->execute()

    std::ofstream os("pattern.bmp");
    Uploader upl(c, os);
    upl.upload();

    std::shared_ptr<Turtle> turtle = std::make_shared<Turtle>();
    unsigned long long lenGorisontal = 100, lenVertical = 100;
    std::shared_ptr<Canvas> canvas = std::make_shared<Canvas>(lenGorisontal, lenVertical);
    std::shared_ptr<Command> c = std::make_shared<Move>(canvas, turtle, 3.6e-3);
    c->execute();
}
