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
    int  size() const;
    void print() const;
    bool empty() const;
    void addNewLineBack(const std::string&);
    void deleteLineBack();

    //for line
    void addNewLineIndex(const unsigned short indexLine, const std::string& newLine);
    void deleteLineIndex(const shint indexLine);

    void addLineBetween(const shint indexLine, const shint indexSymbol, const std::string& newData);

    void deleteInLineRight(const shint indexLine, const shint indexSymbol);
    void deleteInLineLeft(const shint indexLine, const shint indexSymbol);
    //void deleteInLineIndexStartToIndexEnd(const shint indexLine, const shint indexStart, const shint indexEnd);

    //for file
    void updateFile(std::string filename = "")  const;
    void readFromFile(const std::string& filename);

    //Additions
    int getIndexLineEnd(const ushort start)  const;
    std::string getFileName()  const;
    std::vector<std::string> separateBySpaces(const ushint indexLine);
    void separateBySpaces(const ushint indexLine, std::vector<std::string> newLine);

    //Operators
    std::string operator[] (const ushort index) const;
};

