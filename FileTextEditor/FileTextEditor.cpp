#include "FileTextEditor.h"

//operators
std::vector<std::string> FileTextEditor::operator[](int index) const
{
    return (m_text.at(index));
}

//for FileEditor
void FileTextEditor::updata()
{
    FileEditor::empty();
    for (ushint start = 0; start < size(); ++start)
    {
        std::vector<std::string> line = FileTextEditor::getLine(start);
        
        if (line.empty())
            continue;
        
        std::string newLine = line.front();
        
        for (ushint index = 0; index < getLineSize(index); ++index)
        {
            newLine += " " + line[index];
        }

        FileTextEditor::setLine(start, newLine);
    }
}
std::string FileTextEditor::getFileName()  const
{
    // TODO: Добавьте сюда код реализации.
}

//for base work 
void FileTextEditor::print() const
{
    // TODO: Добавьте сюда код реализации.
}
int  FileTextEditor::size() const
{
    // TODO: Добавьте сюда код реализации.
}
void FileTextEditor::empty()
{
    // TODO: Добавьте сюда код реализации.
}

//set, get, add and delete lines
std::vector<std::string> FileTextEditor::getLine(int indexLine)
{
    return(m_text.at(indexLine));
}
void FileTextEditor::setLine(int indexLine, std::string newLine)
{
    FileEditor::setLine(indexLine, newLine);
}
void FileTextEditor::addNewLine(int indexLine, std::string newLine)
{
    // TODO: Добавьте сюда код реализации.
}
void FileTextEditor::deleteLine(int indexLine)
{
    // TODO: Добавьте сюда код реализации.
}
void FileTextEditor::addNewLineBack(int indexLine, std::string newLine)
{
    // TODO: Добавьте сюда код реализации.
}
void FileTextEditor::deleteLineBack(int indexLine)
{
    // TODO: Добавьте сюда код реализации.
}

//work in lines
void FileTextEditor::searchWordInLine(int indexLine, std::string word, int indexWord, int indexSymbol) const
{
    // TODO: Добавьте сюда код реализации.
}
void FileTextEditor::searchSymbolInLine(int indexLine, char symbol, int indexWord, int indexSymbol) const
{
    // TODO: Добавьте сюда код реализации.
}
int  FileTextEditor::getLineSize(int indexLine) const
{
    // TODO: Добавьте сюда код реализации.
}

//work form File
void FileTextEditor::readFormFile(std::string filename = "")
{
    // TODO: Добавьте сюда код реализации.
}
void FileTextEditor::updateFile()
{
    // TODO: Добавьте сюда код реализации.
}

//void splitWords();
void FileTextEditor::splitWordsBySpace()
{
    // TODO: Добавьте сюда код реализации.
}
