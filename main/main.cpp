#include "../FileEditor/FileEditor.h"
#include "../FileTextEditor/FileTextEditor.h"

int main()
{
    FileTextEditor file("../Data/data.txt");
    file.deleteLine(4);
    file.print();

    return (0);
}