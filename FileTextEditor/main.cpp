#include "FileEditor.h"
#include "FileTextEditor.h"

int main()
{
    std::cout << "Start work main.cpp" << std::endl << std::endl;

    FileTextEditor text("data.txt");
    text.print();
    std::cout << std::endl;

    std::vector<std::string> argument{ "Sime", "is", "so", "cute" };
    text.addNewLine(4, argument);
    text.print();
    std::cout << std::endl;

    std::cout << std::endl << "End work main.cpp" << std::endl;

    return 0;
}