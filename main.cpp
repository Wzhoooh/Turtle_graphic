#include <iostream>
#include "list.hpp"

int main()
{
    std::ifstream is;
    is.open("code.txt");
    char input[/* size of file */];
    is >> input;

    Composite commandTree; // contains a tree of Commands
    Parser p(input); // parse an input file
    Filler f(p, commandTree);  // fills a commandTree with commands from Parser
    p.fill(); // commandTree has a tree of commands now

    size_t lenGorisontal, lenVertical;
    Canvas c(lenGorisontal, lenVertical);
    Executor ex(c, commandTree);
    ex.execute(); // puts a final pattern into Canvas

    std::ofstream os("pattern.bmp");
    UPLoader upL(c, os);
    ipL.upload();
}
