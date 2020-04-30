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
    try
    {
        if (argc != 2)
            throw std::runtime_error("file is opened not from console");

        Text_File_Reader fr(argv[1]);
        Canvas canvas(std::move(Round_Pen_Drawer()));
        Define_List defineList;
        Turtle turtle(canvas, defineList);

        defineList.addPenDefinition(new Pen_Definition(turtle, 1, rgb(0, 0, 0)), 0);
        defineList.addPenDefinition(new Pen_Definition(turtle, 1, rgb(255, 255, 255)), 1);
        defineList.applyDefinition(0);

        Command_Factory factory(turtle, canvas, defineList);
        Composite composite(factory);

        Parser p(fr.read(), Command_Handler(composite, defineList, factory));
        p.handle();
        composite.execute();
        canvas.uploadToBmp(argv[1]);
    }
    catch(std::exception& e)
    {
        std::cout << "FATAL ERROR: " << e.what() << "\n";
        system("pause");
    }

}
