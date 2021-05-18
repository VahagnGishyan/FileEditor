#pragma once
#include "Header.h"

class FileEditor
{
private:
    std::vector<std::string> m_data;
    std::string m_fileName;
public:
    //initialization 
    FileEditor();
    FileEditor(const std::string&);

    //to work
    int                      size() const;
    void                     print() const;
    bool                     empty();
    void                     resize(int size);


    //for line
    void                     addNewLineBack(const std::string&);
    void                     deleteLineBack();

    void                     addNewLine(const unsigned short indexLine, const std::string& newLine);
    void                     deleteLine(const shint indexLine);

    void                     setLine(int index, const std::string& newLine);
    std::string              getLine(int index) const;

    void                     deleteInLine(const shint indexLine, const shint indexleft, const shint indexRight);

    //for file
    void                     updateFile(std::string filename = "")  const;
    void                     readFromFile(const std::string& filename);

    //Additions
    int                      getLineSize(const ushort start)  const;
    std::string              getFileName()  const;
    std::vector<std::string> separateBySpaces(const ushint indexLine);
    void                     separateBySpaces(const ushint indexLine, std::vector<std::string> newLine);
};

