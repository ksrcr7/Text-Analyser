

#ifndef TEXT_ANALYSER_CLI_H
#define TEXT_ANALYSER_CLI_H

#include "TextAnalyser.h"

class CLI{

public:
    static int run(int argc, char** argv);

private:
    static void printGeneralUsage() ;
    static void printHelp();
    static int handleStats(const std::string&) ;
    static int handleContains(const std::string&,const std::string&);
    static int handleCount(const std::string&,const std::string&);
    static int handleFreq(const std::string&);
    static int handleWords(const std::string&);


};































#endif //TEXT_ANALYSER_CLI_H
