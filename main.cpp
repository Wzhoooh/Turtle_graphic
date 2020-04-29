#include <iostream>
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
#include "text_file_reader.hpp"


int main(int argc, char* argv[])
{
    Text_File_Reader fr(argv[1]);
    Canvas canvas(std::move(Round_Pen_Drawer()));
    Define_List defineList;
    Turtle turtle(canvas, defineList);

    defineList.addPenDefinition(new Pen_Definition(turtle, 1, rgb(0, 0, 0)), 0);
    defineList.addPenDefinition(new Pen_Definition(turtle, 1, rgb(255, 255, 255)), 1);
    defineList.applyDefinition(0);

    Command_Factory factory(turtle, canvas, defineList);
    Composite composite(factory);
//std::cout << fr.read() << "\n";

    //const char* s = "DEFPEN 33 SIZE 10 RGB 193 0 32 END SELPEN 33 CANVAS 2960 1080 RGB 204 195 31 VIEW 0 0 1000 1000 END TA 45 M 500 PD DO 4 TL M 200 AGAIN";

    Parser p(fr.read(), Command_Handler(composite, defineList, factory));
    p.handle();
    composite.execute();
    canvas.uploadToBmp(argv[1]);

}
