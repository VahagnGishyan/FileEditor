#include "FileEditor.h"
#include "FileTextEditor.h"

int main()
{
    std::cout << "Start work main.cpp" << std::endl << std::endl;

    FileEditor data("data.txt");
    data.print();
    data.addNewLine(4, "Sime is so cute");
    data.print();

    FileTextEditor text("data.txt");
    text.print();
    std::vector<std::string> argument{ "Sime", "is", "so", "cute" };
    text.addNewLine(4, argument);
    text.print();

    std::cout << std::endl << "End work main.cpp" << std::endl;

    return 0;
}