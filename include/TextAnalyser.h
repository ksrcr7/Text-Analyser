

#ifndef TEXT_ANALYSER_TEXTANALYSER_H
#define TEXT_ANALYSER_TEXTANALYSER_H
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>





class TextAnalyser{
private:
    std::string storage_path,Text;
    struct Status{
        std::size_t linecount{};
        std::size_t wordcount{};
        std::size_t uniquewords{};
    };


public:
    explicit TextAnalyser(const std::string&);
    [[nodiscard]] std::string GetPath()const;
    [[nodiscard]] std::string GetText()const;
    [[nodiscard]] std::size_t charCount()const;
    [[nodiscard]] std::size_t lineCount()const;
    [[nodiscard]] std::size_t wordCount()const;
    [[nodiscard]] std::size_t specificWordCount(const std::string&)const;
    [[nodiscard]] bool contains(const std::string&)const;
    std::unordered_map<std::string , std::size_t> wordFrequencies()const;
    std::vector<std::string> extractWords();
    [[nodiscard]] Status stats()const;









};










































#endif //TEXT_ANALYSER_TEXTANALYSER_H
