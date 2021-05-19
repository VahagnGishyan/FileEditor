#include "FileTextEditor.h"

//initialization
void FileTextEditor::init(ushint indexStart = -1, ushint indexEnd = -1)
{
    if (indexStart < 0)
    {
        indexStart = 0;
    }
    if (indexEnd < 0)
    {
        indexEnd = FileEditor::size();
    }

    for (ushint start = 0; start < indexEnd; ++start)
    {
        FileTextEditor::setLine(start, FileEditor::splitWordsBySpace(start));
    }
}
void FileTextEditor::clear()
{
    m_text.clear();
}

//for base work 
void FileTextEditor::print() const
{
    for (ushint start = 0; start < size(); ++start)
    {
        const std::vector<std::string>& line = FileTextEditor::getLine(start);

        std::cout << start << "\t";
        for (ushint index = 0; index < line.size(); ++index)
        {
            std::cout << line[index] << " ";
        }
        std::cout << std::endl;
    }
}
int  FileTextEditor::size() const
{
    return (m_text.size());
}
bool FileTextEditor::empty() const
{
    return (m_text.empty());
}


//set, get, add and delete lines
std::vector<std::string> FileTextEditor::getLine(int indexLine) const 
{
    return(m_text.at(indexLine));
} 
void FileTextEditor::setLine(int indexLine, const std::vector<std::string>&  newLine)
{
    ushint length = size();

    assert(length <= indexLine && "The index cannot be longer than the length");

    if (length < indexLine)
        m_text[indexLine] = newLine;
    else
        m_text.push_back(newLine);
}
void FileTextEditor::addNewLine(int indexLine, const std::vector<std::string>& newLine)
{

    std::vector<std::string> reservData;
    ushint length = size();

    for (ushint index = 0; index < length; ++index)
    {
        std::vector<std::string> registerLine = FileTextEditor::getLine(index);
        FileTextEditor::setLine(index, reservData);
        reservData = registerLine;
    }

    addNewLineBack(reservData);
}
void FileTextEditor::deleteLine(int indexLine)
{
    for (unsigned short int index = indexLine; index < size() - 1; ++index)
    {
        FileTextEditor::setLine(index, FileTextEditor::getLine(index + 1));
    }
    deleteLineBack();
}
void FileTextEditor::addNewLineBack(const std::vector<std::string>& newLine)
{
    m_text.push_back(newLine);
}
void FileTextEditor::deleteLineBack()
{
    m_text.pop_back();
}

//work in lines
int FileTextEditor::searchWordInLine(int indexLine, const std::string& word) const
{
    const std::vector<std::string>& words = FileTextEditor::getLine(indexLine);

    for (ushint index = 0; index < words.size(); ++index)
    {
        if (words[index] == word)
        {
            return index;
        }
    }
    return -1;
}
int  FileTextEditor::getLineSize(int indexLine) const
{
    return (m_text.at(indexLine).size());
}

//work form File
void FileTextEditor::readFormFile(std::string filename)
{
    if (filename == "")
    {
        filename = FileEditor::getFileName();
    }

    if (filename == "")
    {
        std::cout << "Error, FileEditor.cpp, dataFileForInput.open() == false" << std::endl;
        std::cout << "fileName = " << filename << std::endl;
        return;
    }

    FileEditor::openFile(filename);
    init();
}
void FileTextEditor::updateFile()
{
    FileEditor::updateFile();
}


