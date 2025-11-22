#include "TextAnalyser.h"
#include <algorithm>
#include <stdexcept>
#include <fstream>
#include <cctype>



static bool path_validation(const std::string& st){
    if(st.empty())return false;
    if(std::all_of(st.begin(),st.end(),
                   [](unsigned char ch){return std::isspace(ch);}))
        return false;
    return true;

}

static bool is_space(const std::string& st){
    return std::all_of(st.begin(),st.end(),
                       [](unsigned char ch){return std::isspace(ch);});
}

std::string trim(const std::string& st){
    size_t first = st.find_first_not_of(" \t\n\f\v\r");
    if(first == std::string::npos)
        return "";

    size_t last = st.find_last_not_of(" \t\n\f\v\r");
    return st.substr(first,last-first+1);
}







TextAnalyser::TextAnalyser(const std::string &path) {

    if(!path_validation(path)){
        throw std::invalid_argument("Path must not be empty or whitespace only.");
    }
    storage_path = path;

    std::ifstream file(path);
    if(!file){
        throw std::runtime_error("The file can not be opened.");
    }

    std::string content((std::istreambuf_iterator<char>(file)),
                        std::istreambuf_iterator<char>());

    Text = content;
}



std::string TextAnalyser::GetPath() const {
    return storage_path;
}

std::string TextAnalyser::GetText() const {
    return Text;
}

std::size_t TextAnalyser::charCount() const{
    return Text.size();
}

std::size_t TextAnalyser::lineCount() const{
    if(Text.empty())return 0;

    std::size_t newlines = std::count(Text.begin(),Text.end(),'\n');
    if(Text.back() == '\n')
        return newlines;
    else
        return newlines + 1;


}

std::size_t TextAnalyser::wordCount() const {
    if(Text.empty() || is_space(Text))return 0;


    bool inWord = false;
    size_t word = 0;

    for(unsigned char i : Text){
        if(std::isspace(i)){
            inWord  = false;
        }
        else{
            if(!inWord){
                ++word;
                inWord = true;
            }
        }
    }

    return word;

}

std::size_t TextAnalyser::specificWordCount(const std::string &word) const {
    if(word.empty() || is_space(word)){
        throw std::invalid_argument("Please enter your considered word.");
    }

    if(Text.empty() || is_space(Text))return 0;

    size_t count = 0;
    std::string temp;

    for(unsigned char ch : Text){
        if(std::isspace(ch)){
            if (!temp.empty() && temp.size() == word.size() && temp == word) {
                ++count;
            }
            temp.clear();
        }
        else{
            temp += static_cast<char>(ch);
        }


    }
    if (!temp.empty() && temp.size() == word.size() && temp == word) {
        ++count;
    }
    return count;

}

bool TextAnalyser::contains(const std::string &word) const {
    if(word.empty() || is_space(word)){
        throw std::invalid_argument("Please enter considered word.");
    }
    if(Text.empty() || is_space(Text))return false;

    std::string temp;
    for(unsigned char ch: Text){
        if(std::isspace(ch)){
            if(!temp.empty() && temp == word){
                return true;
            }
            temp.clear();
        }
        else{
            temp += static_cast<char>(ch);
        }
    }
    if (!temp.empty() && temp == word) {
        return true;
    }
    return false;


}



