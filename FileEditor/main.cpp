#include "FileEditor.h"

int main()
{
    std::cout << "Start work main.cpp" << std::endl << std::endl;

    FileEditor object("data.txt");
    object.print();

    std::cout << std::endl << "End work main.cpp" << std::endl;

    return 0;
}