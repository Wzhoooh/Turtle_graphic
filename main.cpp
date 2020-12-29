#include <iostream>
#include <conio.h>
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

#include "malloc.h"

size_t GetHeapSize(void)
{
    struct _heapinfo hi = { 0 };
    size_t total = 0;
    while (_heapwalk(&hi) == _HEAPOK)
    {
        if (hi._useflag != _FREEENTRY)
            total += hi._size;
    }
    return total;
}

int main(int argc, char* argv[])
{
    try
    {
        if (argc < 2)
            throw std::runtime_error("this utility needs console parameters");
        if (argc > 3)
            throw std::runtime_error("too many console parameters");

        Text_File_Reader fr(argv[1]);
        Canvas canvas(std::move(Round_Pen_Drawer()));
        Define_List defineList;
        Turtle turtle(canvas, defineList);

        defineList.addPenDefinition(new Pen_Definition(turtle, 1, rgb(0, 0, 0)), 0);
        defineList.applyDefinition(0);

        Command_Factory factory(turtle, canvas, defineList);
        Composite composite(factory);

        Parser p(fr.read(), Command_Handler(composite, defineList, factory));
        p.handle();
        composite.execute();
        if (argc == 2)
            canvas.uploadToBmp(argv[1]);
        else if (argc == 3)
            canvas.uploadToBmp(argv[2]);
    }
    catch(std::exception& e)
    {
        std::cout << "FATAL ERROR: " << e.what() << "\n";
        std::cout << "Press any key to continue...";
        getch();
        std::cout << "\n";
    }
}
