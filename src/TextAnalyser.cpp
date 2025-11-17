#include "TextAnalyser.h"
#include <algorithm>
#include <stdexcept>
#include <fstream>



static bool path_validation(const std::string& st){
    if(st.empty())return false;
    return std::all_of(st.begin(),st.end(),
                   [](unsigned char ch){return std::isspace(ch);});

}







TextAnalyser::TextAnalyser(const std::string &path) {

    if(!path_validation(path)){
        throw std::invalid_argument("Path must not be empty or whitespace only.");
    }
    storage_path = path;

    std::ifstream file(path);
    if(!file){
        throw std::runtime_error("System can not open this file.");
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
    return newlines + 1;


}


