#include "FileTextEditor.h"

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

        FileEditor::setLine(start, newLine);
    }
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
std::vector<std::string> FileTextEditor::getLine(int indexLine) const 
{
    return(m_text.at(indexLine));
} 
void FileTextEditor::setLine(int indexLine, const std::vector<std::string>&  newLine)
{
    m_text.at(indexLine) = newLine;
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
void FileTextEditor::searchSymbolInLine(int indexLine, char symbol, int& indexWord, int& indexSymbol) const
{
    const std::vector<std::string>& words = FileTextEditor::getLine(indexLine);

    for (ushint start = 0; start < words.size(); ++start)
    {
        std::string word = words[start];
        for (ushint index = 0; index < word.size(); ++index)
        {
            if (word[index] == symbol)
            {
                indexWord = start;
                indexSymbol = index;
                return ;
            }
        }
    }
    indexWord = -1;
    indexSymbol = -1;
}
int  FileTextEditor::getLineSize(int indexLine) const
{
    return (m_text.at(indexLine).size());
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
