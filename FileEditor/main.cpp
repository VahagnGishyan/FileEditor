#include "FileEditor.h"

int main()
{
    std::cout << "Start work main.cpp" << std::endl << std::endl;

    FileEditor object("data.txt");
    object.print();
    std::cout << std::endl;

    object.addLineBetween(6, 12, "Hello World");
    object.print();
    object.updateFile("newdata.txt");

    object.addNewLineIndex(7, "\tSime is so cute");
    object.print();

    std::vector<std::string> data = object.separateBySpaces(7);

    std::cout << std::endl << "End work main.cpp" << std::endl;

    return 0;
}