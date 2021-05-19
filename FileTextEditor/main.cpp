#include "FileEditor.h"
#include "FileTextEditor.h"

int main()
{
    std::cout << "Start work main.cpp" << std::endl << std::endl;

    FileEditor object("data.txt");
    object.print();

    FileTextEditor data("data.txt");
    data.print();

    std::cout << std::endl << "End work main.cpp" << std::endl;

    return 0;
}