#pragma once
#include "FileEditor.h"

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
	// TODO: Добавьте сюда код реализации.
    }

    //operators
    std::vector<std::string> operator[](int index) const;

    //for FileEditor
    void updata();
    std::string getFileName()  const;

    //for base work 
    void print() const;
    int  size() const;
    void empty();

    //set, get, add and delete lines
    std::vector<std::string> getLine(int indexLine);
    void setLine(int indexLine, std::string newLine);
    void addNewLine(int indexLine, std::string newLine);
    void deleteLine(int indexLine);
    void addNewLineBack(int indexLine, std::string newLine);
    void deleteLineBack(int indexLine);

    //work in lines
    void searchWordInLine(int indexLine, std::string word, int indexWord, int indexSymbol) const;
    void searchSymbolInLine(int indexLine, char symbol, int indexWord, int indexSymbol) const;
    int  getLineSize(int indexLine) const;

    //work form File
    void readFormFile(std::string filename = "");
    void updateFile();

    //void splitWords();
    void splitWordsBySpace();

};

