#include "FileEditor.h"

//initialization 
FileEditor::                         FileEditor()
{
    std::cout << "Works Constructor FileEditor()" << std::endl;
    m_fileName = "";
}
FileEditor::                         FileEditor(const std::string& fileName)
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
int  FileEditor::                    size() const
{
    return m_data.size();
}
void FileEditor::                    print() const
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
bool FileEditor::                    empty() 
{
    return m_data.empty();
}
void FileEditor::                    resize(int size)
{
    m_data.resize(size);
}
void FileEditor::                    clear()
{
    m_data.clear();
}

void FileEditor::                    addNewLineBack(const std::string& newLine)
{
    m_data.push_back(newLine);
}
void FileEditor::                    deleteLineBack()
{
    m_data.pop_back();
}

//for line
void FileEditor::                    addNewLine(const unsigned short indexLine, const std::string& newLine)
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
void FileEditor::                    deleteLine(const shint indexLine)
{
    for (unsigned short int index = indexLine; index < size() - 1; ++index)
    {
        m_data[index] = m_data[index + 1];
    }
    deleteLineBack();
}

void FileEditor::                    deleteInLine(const shint indexLine, const shint indexleft, const shint indexRight)
{
    std::string line = FileEditor::getLine(indexLine);

    std::string registLeft = "";
    std::string registRight = "";

    for (unsigned short index = 0; index < indexleft; ++index)
    {
        registRight += line[index];
    }

    const ushint size = static_cast<ushint>(line.size());
    for (unsigned short index = indexRight; index < size; ++index)
    {
        registRight += m_data[indexLine][index];
    }

    std::string newLine = registLeft + registRight;
    FileEditor::setLine(indexLine, newLine);
}

void FileEditor::                    setLine(int index, const std::string& newLine)
{
    ushint length = size();

    assert(length <= index && "The index cannot be longer than the length");

    if (length < index)
        m_data[index] = newLine;
    else 
        m_data.push_back(newLine);
}
std::string FileEditor::             getLine(int index) const
{
    return(m_data.at(index));
}

//for file
void FileEditor::                    updateFile(std::string filename) const
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
void FileEditor::                    openFile(const std::string& fileName)
{
    std::cout << "Works FileEditor::readFromFile(std::string& fileName)" << std::endl;
    m_fileName = fileName;

    if (!m_data.empty())
    {
        m_data.clear();
    }

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
int FileEditor::                     getLineSize(const ushort start) const
{
    return m_data.at(start).size();
}
std::string FileEditor::             getFileName()  const
{
    return m_fileName;
}
std::vector<std::string> FileEditor::separateBySpaces(const ushint indexLine)
{
    std::vector<std::string> resultData;
    const std::string& line = FileEditor::getLine(indexLine);

    std::string word = "";
    const ushint size = getLineSize(indexLine);


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
void FileEditor::                    separateBySpaces(const ushint indexLine, std::vector<std::string> newLine)
{
    const std::string& line = FileEditor::getLine(indexLine);

    std::string word = "";
    const ushint size = getLineSize(indexLine);

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
