#pragma once
#include "../Header.h"
#include "../FileEditor/FileEditor.h"

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
    void                     print();
    int                      size();
    bool                     empty();

    //set, get, add and delete lines
    std::vector<std::string>& getLine(int indexLine); 
    void                      setLine(int indexLine, const std::vector<std::string>& newLine);
    void                      setLine(int indexLine, std::string& newLine);

    void                      addNewLine(int indexLine, const std::vector<std::string>& newLine);
    void                      addNewLine(int indexLine, const std::string& newLine);
    void                      deleteLine(int indexLine);

    void                      addNewLineBack(const std::vector<std::string>&  newLine);
    void                      addNewLineBack(std::string& newLine);
    void                      deleteLineBack();

    void                      combineWords(ushint indexLine, ushint indexLeftWord, ushint indexRightWord);
    
    void                      addWordInLine(ushint indexLine, ushint indexWord, std::string& newLine);
    void                      deleteWordInLine(ushint indexLine, ushint indexWord);

    //work in lines
    int                       searchWordInLine(int indexLine, const std::string&);
    int                       getLineSize(int indexLine);

    //work form File
    void                      readFormFile(std::string filename = "");
    void                      updateFile();
};

