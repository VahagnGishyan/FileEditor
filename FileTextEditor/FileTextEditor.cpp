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
        std::vector<std::string>& line = getLine(start);
        
        if (line.empty())
            continue;
        
        std::string newLine = line.front();
        
        for (ushint index = 0; index < getLineSize(index); ++index)
        {
            newLine += " " + line[index];
        }
    }

    ushint cycles = std::min((int)m_text.size(), size() - m_startLine);

    for (ushint indexLine = 0; indexLine < cycles; ++indexLine)
    {
        std::vector<std::string>& line = m_text[indexLine];

        std::string newline;

        if (line.empty())
            continue;

        newline += line[0];
        for (ushint index = 1; index < line.size(); ++index)
        {
            newline += " " + line[index];
        }
        FileEditor::setLineIndex(indexLine + m_startLine, newline);
    }
    if ((int)m_text.size() > size() - m_startLine)
    {
        for (ushint start = cycles; start < m_text.size(); ++start)
        {
            std::vector<std::string>& line = m_text[start];

            std::string newline;

            if (line.empty())
                continue;

            newline += line[0];
            for (ushint index = 1; index < line.size(); ++index)
            {
                newline += " " + line[index];
            }
            FileEditor::addNewLineBack(newline);
        }
    }
    else if ((int)m_text.size() < size() - m_startLine)
    {
        for (ushint indexLine = cycles; indexLine < size(); ++indexLine)
        {
            FileEditor::deleteLineBack();
        }
    }
    else
    {
        return;
    }
}
std::string FileTextEditor::getFileName()  const
{
    // TODO: �������� ���� ��� ����������.
}

//for base work 
void FileTextEditor::print() const
{
    // TODO: �������� ���� ��� ����������.
}
int  FileTextEditor::size() const
{
    // TODO: �������� ���� ��� ����������.
}
void FileTextEditor::empty()
{
    // TODO: �������� ���� ��� ����������.
}

//set, get, add and delete lines
std::vector<std::string> FileTextEditor::getLine(int indexLine)
{
    // TODO: �������� ���� ��� ����������.
}
void FileTextEditor::setLine(int indexLine, std::string newLine)
{
    // TODO: �������� ���� ��� ����������.
}
void FileTextEditor::addNewLine(int indexLine, std::string newLine)
{
    // TODO: �������� ���� ��� ����������.
}
void FileTextEditor::deleteLine(int indexLine)
{
    // TODO: �������� ���� ��� ����������.
}
void FileTextEditor::addNewLineBack(int indexLine, std::string newLine)
{
    // TODO: �������� ���� ��� ����������.
}
void FileTextEditor::deleteLineBack(int indexLine)
{
    // TODO: �������� ���� ��� ����������.
}

//work in lines
void FileTextEditor::searchWordInLine(int indexLine, std::string word, int indexWord, int indexSymbol) const
{
    // TODO: �������� ���� ��� ����������.
}
void FileTextEditor::searchSymbolInLine(int indexLine, char symbol, int indexWord, int indexSymbol) const
{
    // TODO: �������� ���� ��� ����������.
}
int  FileTextEditor::getLineSize(int indexLine) const
{
    // TODO: �������� ���� ��� ����������.
}

//work form File
void FileTextEditor::readFormFile(std::string filename = "")
{
    // TODO: �������� ���� ��� ����������.
}
void FileTextEditor::updateFile()
{
    // TODO: �������� ���� ��� ����������.
}

//void splitWords();
void FileTextEditor::splitWordsBySpace()
{
    // TODO: �������� ���� ��� ����������.
}
