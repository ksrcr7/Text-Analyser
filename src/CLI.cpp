#include "CLI.h"

void CLI::printGeneralUsage() {
    std::cout<<"Usage: textanalyser <command> [options]\n";
    std::cout<<"Use \"textanalyser help\" for more information. \n";

}

void CLI::printHelp() {
    std::cout << "TextAnalyser CLI\n\n";
    std::cout << "Commands:\n";
    std::cout << "  help                         Show this help message\n";
    std::cout << "  stats <file>                 Show basic statistics for a file\n";
    std::cout << "  contains <file> <word>       Check if a word exists in the file\n";
    std::cout << "  count <file> <word>          Count occurrences of a word in the file\n";
    std::cout << "  freq <file>                  Show frequency of all words in the file\n";
    std::cout << "  words <file>                 List all words in the file\n";

}

int CLI::run(int argc, char **argv) {
    if(argc < 2){
        printGeneralUsage();
        return 1;
    }
    std::string command = argv[1];

    try {
        if(command == "help"){
            printHelp();
            return 0;
        }
        else if(command == "stats"){
            if(argc < 3){
                std::cerr<<"Error: missing <file> argument for \"stats\" command.\n";
                std::cerr << "Usage: textanalyser stats <file>\n";
                return 1;
            }
            std::string path = argv[2];
            return handleStats(path);

        }
        else if(command == "contains"){
            if(argc < 4){
                std::cerr<<"Error: missing <file> or <word> argument for \"contains\" command.\n";
                std::cerr << "Usage: textanalyser contains <file> <word>\n";
                return 1;
            }
            std::string path = argv[2];
            std::string word = argv[3];
            return handleContains(path,word);

        }
        else if(command == "count"){
            if(argc < 4){
                std::cerr<<"Error: missing <file> or <word> argument for \"contains\" command.\n";
                std::cerr << "Usage: textanalyser count <file> <word>\n";
                return 1;
            }
            std::string path = argv[2];
            std::string word = argv[3];
            return handleCount(path,word);
        }
        else if(command == "freq"){
            if(argc < 3){
                std::cerr<<"Error: missing <file> argument for \"freq\" command.\n";
                std::cerr << "Usage: textanalyser freq <file>\n";
                return 1;
            }
            std::string path = argv[2];
            return handleFreq(path);

        }
        else if(command == "words"){
            if(argc < 3){
                std::cerr<<"Error: missing <file> argument for \"words\" command.\n";
                std::cerr << "Usage: textanalyser words <file>\n";
                return 1;
            }
            std::string path = argv[2];
            return handleWords(path);

        }
        else{
            std::cerr<<"Error: unknown command \"" << command << "\".\n";
            printGeneralUsage();
            return 1;
        }
    }
    catch (std::exception& e) {
        std::cerr<<"Error: "<<e.what()<<'\n';
        return 1;
        
    }
}

int CLI::handleStats(const std::string &path) {
    TextAnalyser analyser(path);
    TextAnalyser::Status st = analyser.stats();

    std::cout << "Lines:        " << st.linecount   << '\n';
    std::cout << "Words:        " << st.wordcount   << '\n';
    std::cout << "Unique words: " << st.uniquewords << '\n';
    return 0;
}

int CLI::handleContains(const std::string &path, const std::string &word) {
    TextAnalyser analyser(path);
    bool exist = analyser.contains(word);

    if(exist){
        std::cout<<"The word "<<word<<" exist in the file.\n";
    }
    else
        std::cout<<"The word "<<word<<" doesnt exist in the file.\n";

    return 0;
}

int CLI::handleCount(const std::string &path, const std::string &word) {
    TextAnalyser analyser(path);
    size_t it = analyser.specificWordCount(word);

    std::cout<<"The word "<<word<<" "<<it<<" times is repeated in the file.\n";
    return 0;

}

int CLI::handleFreq(const std::string &path) {
    TextAnalyser analyser(path);
    const auto& Freqs = analyser.wordFrequencies();

    if(Freqs.empty()){
        std::cout<<"No words found in the file.\n";
        return 1;
    }

    for (const auto & t : Freqs)
        std::cout<<t.first<<" : "<<t.second<<" times.\n";

    return 0;


}

int CLI::handleWords(const std::string &path) {
    TextAnalyser analyser(path);

    const auto& words = analyser.extractWords();
    for(const auto& it : words)
        std::cout<<it<<'\n';
    return 0;

}
