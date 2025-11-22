

#ifndef TEXT_ANALYSER_TEXTANALYSER_H
#define TEXT_ANALYSER_TEXTANALYSER_H
#include <iostream>
#include <string>
#include <fstream>





class TextAnalyser{
private:
    std::string storage_path,Text;


public:
    explicit TextAnalyser(const std::string&);
    [[nodiscard]] std::string GetPath()const;
    [[nodiscard]] std::string GetText()const;
    [[nodiscard]] std::size_t charCount()const;
    [[nodiscard]] std::size_t lineCount()const;
    [[nodiscard]] std::size_t wordCount()const;
    [[nodiscard]] std::size_t specificWordCount(const std::string&)const;




};










































#endif //TEXT_ANALYSER_TEXTANALYSER_H
