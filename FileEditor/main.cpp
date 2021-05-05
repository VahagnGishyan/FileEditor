#include "FileEditor.h"

int main()
{
    std::cout << "Start work main.cpp" << std::endl << std::endl;

    FileEditor object("data.txt");
    object.print();
    std::cout << std::endl;

    object.addLineBetween(6, 14, "Hello World");
    object.print();
    object.updateFile("newdata.txt");

    object.addNewLineIndex(7, "\tstd::cout << \"Sime is so cute\" << std::endl;");
    object.print();
    std::cout << std::endl;


 //   std::vector<std::string> data = object.separateBySpaces(7);
 //   std::cout << 7 << '\t';
 //   for (ushint index = 0; index < data.size(); ++index)
 //   {
	//std::cout << data[index] << " ";
 //   }
 //   std::cout << std::endl;
 //   for (ushint index = 0; index < data.size(); ++index)
 //   {
	//std::cout << index << "\t" << data[index] << std::endl;
 //   }

    object.readFromFile("newdata.txt");
    object.print();
    std::cout << std::endl;
    



    std::cout << std::endl << "End work main.cpp" << std::endl;

    return 0;
}