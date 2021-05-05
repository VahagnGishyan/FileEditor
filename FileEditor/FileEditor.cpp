#include "FileEditor.h"

//initialization 
FileEditor::FileEditor()
{
    std::cout << "Works Constructor FileEditor()" << std::endl;
    m_fileName = "";
}
FileEditor::FileEditor(const std::string& fileName)
{
    m_fileName = fileName;
    std::ifstream dataFileForInput(m_fileName);
    if (!dataFileForInput)
    {
        std::cout << "Error, FileEditor.cpp, dataFileForInput.open() == false" << std::endl;
        std::cout << "fileName = " << m_fileName << std::endl;
    }
    else
    {
        while (!dataFileForInput.eof())
        {
            std::string line;
            getline(dataFileForInput, line);
            addNewLineBack(line);
        }
    }
    dataFileForInput.close();
}

//to work
int  FileEditor::size() const
{
    return m_data.size();
}
void FileEditor::print() const
{

    if (m_data.empty())
    {
        std::cout << "Vector is empty" << std::endl;
    }
    else
    {
        for (unsigned short index = 0; index < m_data.size(); ++index)
        {
            std::cout << index << "\t" << m_data[index] << std::endl;
        }
    }
}
bool FileEditor::empty() const
{
    return m_data.empty();
}
void FileEditor::addNewLineBack(const std::string& newLine)
{
    m_data.push_back(newLine);
}
void FileEditor::deleteLineBack()
{
    m_data.pop_back();
}

//for line
void FileEditor::addNewLineIndex(const unsigned short indexLine, const std::string& newLine)
{
    std::string Line = newLine;
    ushint size = static_cast<ushint>(m_data.size());

    for (unsigned short int index = indexLine; index < size; ++index)
    {
        std::string registerLine = m_data[index];
        m_data[index] = Line;
        Line = registerLine;
    }
    addNewLineBack(Line);
}
void FileEditor::deleteLineIndex(const shint indexLine)
{
    for (unsigned short int index = indexLine; index < size() - 1; ++index)
    {
        m_data[index] = m_data[index + 1];
    }
    deleteLineBack();
}

void FileEditor::addLineBetween(const shint indexLine, const shint indexSymbol, const std::string& newData)
{
    std::string registLeft = "";
    std::string registRight = "";

    for (unsigned short index = 0; index <= indexSymbol; ++index)
    {
        registLeft += m_data[indexLine][index];
    }

    const ushint endSize = getIndexLineEnd(indexLine);
    for (unsigned short index = indexSymbol + 1; index < endSize; ++index)
    {
        registRight += m_data[indexLine][index];
    }

    m_data[indexLine] = registLeft + newData + registRight;
}

void FileEditor::deleteInLineRight(const shint indexLine, const shint indexSymbol)
{
    std::string registLeft = "";

    for (unsigned short index = 0; index <= indexSymbol; ++index)
    {
        registLeft += m_data[indexLine][index];
    }

    m_data[indexLine] = registLeft;
}
void FileEditor::deleteInLineLeft(const shint indexLine, const shint indexSymbol)
{
    std::string registRight = "";
    const ushint size = getIndexLineEnd(indexLine);
    for (unsigned short index = indexSymbol; index < size; ++index)
    {
        registRight += m_data[indexLine][index];
    }

    m_data[indexLine] = registRight;
}

//for file
void FileEditor::updateFile(std::string filename) const
{
    if (filename == "")
        filename = m_fileName;

    std::ofstream dataFileForOutput(filename);
    if (!dataFileForOutput)
    {
        std::cout << "Error, FileEditor.cpp, dataFileForOutput.open() == false" << std::endl;
        std::cout << "fileName = " << filename << std::endl;
    }
    else
    {
        dataFileForOutput.clear();
        for (unsigned short index = 0; index < m_data.size(); ++index)
        {
            dataFileForOutput << m_data[index] << '\n';
        }
    }
}
void FileEditor::readFromFile(const std::string& fileName)
{
    std::cout << "Works FileEditor::readFromFile(std::string& fileName)" << std::endl;
    m_fileName = fileName;

    std::ifstream dataFileForInput(m_fileName);
    if (!dataFileForInput)
    {
        std::cout << "Error, FileEditor.cpp, dataFileForInput.open() == false" << std::endl;
        std::cout << "fileName = " << m_fileName << std::endl;
    }
    else
    {
        if (!m_data.empty())
        {
            m_data.clear();
            m_data.shrink_to_fit();
        }
        while (!dataFileForInput.eof())
        {
            std::string line;
            getline(dataFileForInput, line);
            addNewLineBack(line);
        }
    }
    dataFileForInput.close();
}

//Additions
int FileEditor::getIndexLineEnd(const ushort start) const
{
    return m_data.at(start).size();
}
std::string FileEditor::getFileName()  const
{
    return m_fileName;
}
std::vector<std::string> FileEditor::separateBySpaces(const ushint indexLine)
{
    std::vector<std::string> resultData;
    const std::string line = m_data.at(indexLine);

    std::string word = "";
    const ushint size = getIndexLineEnd(indexLine);


    for (ushint index = 0; index < size; ++index)
    {
        const char symbol = line[index];

        if (std::isspace(symbol))
        {
            if (word.empty())
                continue;
            resultData.push_back(word);
            word = "";
        }
        else
        {
            word += symbol;
        }
    }
    if(!word.empty())
        resultData.push_back(word);

    return (resultData);
}
void FileEditor::separateBySpaces(const ushint indexLine, std::vector<std::string> newLine)
{
    const std::string line = m_data.at(indexLine);

    std::string word = "";
    const ushint size = getIndexLineEnd(indexLine);

    for (ushint index = 0; index < size; ++index)
    {
        const char symbol = line[index];

        if (std::isspace(symbol))
        {
            if (newLine.empty())
                continue;
            if (word.empty())
                continue;
            newLine.push_back(word);
        }
        else
        {
            word += symbol;
        }
    }
}

//Operators
std::string FileEditor::operator[] (const ushort index) const
{
    return m_data[index];
}
