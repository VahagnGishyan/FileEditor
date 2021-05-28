#include "FileTextEditor.h"

//initialization
void FileTextEditor::                    init(int indexStart, int indexEnd)
{
    clear();
    if (indexStart < 0)
    {
        indexStart = 0;
    }
    if (indexEnd < 0)
    {
        indexEnd = FileEditor::size();
    }

    for (ushint start = indexStart; start < indexEnd; ++start)
    {
        FileTextEditor::addNewLineBack(FileEditor::splitWordsBySpace(start));
    }

    //TO DO :: improve & accelerate the two places below, separate them in a separate new function
    for (int index = indexEnd - 1; index >= indexStart; --index)
        FileEditor::deleteLineBack();
}
void FileTextEditor::                    clear()
{
    m_text.clear();
}

//for FileEditor
void FileTextEditor::                    updata()
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

        FileEditor::setLine(start, newLine);
    }
}

//for base work 
void FileTextEditor::                    print() 
{
    for (ushint start = 0; start < size(); ++start)
    {
        std::cout << start << "\t";
        for (ushint index = 0; index < FileTextEditor::getLine(start).size(); ++index)
        {
            std::cout << FileTextEditor::getLine(start)[index] << " ";
        }
        std::cout << std::endl;
    }
}
int  FileTextEditor::                    size() 
{
    return (m_text.size());
}
bool FileTextEditor::                    empty() 
{
    return (m_text.empty());
}


//set, get, add and delete lines
std::vector<std::string>& FileTextEditor::getLine(int indexLine)
{
    return m_text[(indexLine)];
}
void FileTextEditor::                    setLine(int indexLine, const std::vector<std::string>&  newLine)
{
    ushint length = size();

    assert(indexLine <= length && "The index cannot be longer than the length");

    if (indexLine < length)
        m_text[indexLine] = newLine;
    else
        m_text.push_back(newLine);
}
void FileTextEditor::                    setLine(int indexLine, std::string& newWord)
{
    ushint length = FileTextEditor::size();

    assert(indexLine <= length && "The index cannot be longer than the length");

    std::vector<std::string> newLine;
    newLine.push_back(newWord);

    if (indexLine < length)
        m_text[indexLine] = newLine;
    else
        m_text.push_back(newLine);
}

void FileTextEditor::                    addNewLine(int indexLine, const std::vector<std::string>& newLine)
{
    std::vector<std::string> reservData = newLine;
    ushint length = size();

    if (indexLine == length)
    {
        FileTextEditor::addNewLineBack(newLine);
        return;
    }

    for (ushint index = indexLine; index < length; ++index)
    {
        std::vector<std::string> registerLine = FileTextEditor::getLine(index);
        FileTextEditor::setLine(index, reservData);
        reservData = registerLine;
    }

    addNewLineBack(reservData);
}
void FileTextEditor::                    addNewLine(int indexLine, const std::string& newWord)
{
    std::vector<std::string> newLine;
    newLine.push_back(newWord);

    std::vector<std::string> reservData = newLine;
    ushint length = size();

    if (indexLine == length)
    {
        FileTextEditor::addNewLineBack(newLine);
        return;
    }

    for (ushint index = indexLine; index < length; ++index)
    {
        std::vector<std::string> registerLine = FileTextEditor::getLine(index);
        FileTextEditor::setLine(index, reservData);
        reservData = registerLine;
    }

    addNewLineBack(reservData);
}
void FileTextEditor::                    deleteLine(int indexLine)
{
    for (unsigned short int index = indexLine; index < size() - 1; ++index)
    {
        FileTextEditor::setLine(index, FileTextEditor::getLine(index + 1));
    }
    deleteLineBack();
}

void FileTextEditor::                    addNewLineBack(const std::vector<std::string>& newLine)
{
    m_text.push_back(newLine);
}
void FileTextEditor::                    addNewLineBack(std::string& newWord)
{
    std::vector<std::string> newLine;
    newLine.push_back(newWord);

    m_text.push_back(newLine);
}
void FileTextEditor::                    deleteLineBack()
{
    m_text.pop_back();
}

void FileTextEditor::                    combineWords(ushint indexLine, ushint indexLeftWord, ushint indexRightWord)
{
    std::vector<std::string>& line = m_text[indexLine];
    ushint size = static_cast<ushint>(line.size());

    //std::string leftData = "";
    std::string middleData = "";
    std::vector<std::string> rightData;

    for (ushint index = indexLeftWord; index <= indexRightWord; ++index)
    {
        middleData += line[index];
    }
    for (ushint index = indexRightWord + 1; index < size; ++index)
    {
        rightData.push_back(line[index]);
    }

    shint index = size - 1;
    while (index >= indexLeftWord)
    {
        line.pop_back();
        --index;
    }
    line.push_back(middleData);

    for (ushint index = 0; index < rightData.size(); ++index)
    {
        line.push_back(rightData[index]);
    }
}

void FileTextEditor::                    addWordInLine(ushint indexLine, ushint indexWord, std::string& newWord)
{
    std::vector<std::string>& line = m_text[indexLine];
    ushint size = static_cast<ushint>(line.size());

    //std::string leftData = "";
    std::vector<std::string> rightData;

    for (ushint index = indexWord; index < size; ++index)
    {
        rightData.push_back(line[index]);
    }

    shint index = size - 1;
    while (index >= indexWord)
    {
        line.pop_back();
        --index;
    }
    line.push_back(newWord);

    for (ushint index = 0; index < rightData.size(); ++index)
    {
        line.push_back(rightData[index]);
    }
}
void FileTextEditor::                    deleteWordInLine(ushint indexLine, ushint indexWord)
{
    std::vector<std::string>& line = m_text[indexLine];
    ushint size = static_cast<ushint>(line.size());

    std::vector<std::string> rightData;

    for (ushint index = indexWord + 1; index < size; ++index)
    {
        rightData.push_back(line[index]);
    }

    shint index = size - 1;
    while (index >= indexWord)
    {
        line.pop_back();
        --index;
    }

    for (ushint index = 0; index < rightData.size(); ++index)
    {
        line.push_back(rightData[index]);
    }
}

//work in lines
int  FileTextEditor::                    searchWordInLine(int indexLine, const std::string& word)
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
int  FileTextEditor::                    getLineSize(int indexLine)
{
    return (m_text.at(indexLine).size());
}

//work form File
void FileTextEditor::                    readFormFile(std::string filename)
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
void FileTextEditor::                    updateFile()
{
    updata();
    FileEditor::updateFile();
}
