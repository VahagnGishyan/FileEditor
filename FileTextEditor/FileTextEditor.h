#pragma once
#include "Header.h"

class FileTextEditor : public FileEditor
{
private:
    std::vector<std::vector<std::string>> m_text;

public:
    //initialization
                             FileTextEditor() : FileEditor()
    {

    }
                             FileTextEditor(std::string filename) : FileEditor(filename)
    {
	init();
    }
    
    void                     init(int indexStart = -1, int indexEnd = -1);
    void                     clear();

    //for FileEditor
    void                     updata();

    //for base work 
    void                     print() const;
    int                      size() const;
    bool                     empty() const;

    //set, get, add and delete lines
    std::vector<std::string> getLine(int indexLine) const; 
    void                     setLine(int indexLine, const std::vector<std::string>& newLine);

    void                     addNewLine(int indexLine, const std::vector<std::string>& newLine);
    void                     deleteLine(int indexLine);

    void                     addNewLineBack(const std::vector<std::string>&  newLine);
    void                     deleteLineBack();

    //work in lines
    int                      searchWordInLine(int indexLine, const std::string&) const;
    int                      getLineSize(int indexLine) const;

    //work form File
    void                     readFormFile(std::string filename = "");
    void                     updateFile();
};

