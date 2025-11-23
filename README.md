📘 TextAnalyser – C++ Text Analysis CLI Tool

TextAnalyser is a lightweight yet powerful C++ command-line tool for analyzing plain-text files.
It provides detailed text statistics, word search, frequency analysis, and word extraction features, all implemented through a clean object-oriented design.
------------------------------------------------------------------------------------------------------------------------------------------------------------
🚀 Features
🔹 Core Text Analysis (TextAnalyser class)

lineCount() – Counts the number of lines

wordCount() – Counts total words, with whitespace-aware parsing

contains(word) – Checks whether a full word exists in the text

specificWordCount(word) – Counts occurrences of a specific word

wordFrequencies() – Returns an unordered_map<string, size_t> of word frequencies

extractWords() – Returns all words in the order they appear

stats() – Returns a struct summarizing:

Number of lines

Total words

Unique words
-----------------------------------------------------------------------------------------------------------------------------------------------------------
🔹 Command Line Interface (CLI class)

All functionality is exposed via a clean CLI layer: textanalyser <command> [options]
Available commands:
| Command                  | Description                        |
| ------------------------ | ---------------------------------- |
| `help`                   | Show help message                  |
| `stats <file>`           | Show file statistics               |
| `contains <file> <word>` | Check if a word exists in the file |
| `count <file> <word>`    | Count occurrences of a word        |
| `freq <file>`            | Show frequency map of all words    |
| `words <file>`           | List all words in order            |

-----------------------------------------------------------------------------------------------------------------------------------------------------------
📦 Build Instructions
Requirements

C++17 or higher

CMake (recommended)

A C++ compiler (GCC / Clang / MSVC)
-----------------------------------------------------------------------------------------------------------------------------------------------------------
Build with CMake

mkdir build
cd build
cmake ..
make
-----------------------------------------------------------------------------------------------------------------------------------------------------------
This generates the executable:./textanalyser <command>
-----------------------------------------------------------------------------------------------------------------------------------------------------------
📂 Project Structure

├── TextAnalyser.h
├── TextAnalyser.cpp
├── TextAnalyserCLI.h
├── TextAnalyserCLI.cpp
├── main.cpp
├── data/
│   └── sample.txt
└── README.md

TextAnalyser → Core text-processing logic

CLI → Parses commands and routes them to TextAnalyser

main → Minimal entry point that simply runs the CLI

-----------------------------------------------------------------------------------------------------------------------------------------------------------
🧪 Usage Examples
1. Show Help: textanalyser help
2. File Statistics: textanalyser stats data/sample.txt

Output example:
Lines:        12
Words:        85
Unique words: 46


3. Check Whether a Word Exists: textanalyser contains data/sample.txt hello
4. Count Occurrences of a Word: textanalyser count data/sample.txt hello
5. List all Words in Order: textanalyser words data/sample.txt
6. Show Word Frequencies: textanalyser freq data/sample.txt
------------------------------------------------------------------------------------------------------------------------------------------------------------
🛠 Error Handling

The CLI provides clear error messages for:

Missing or invalid arguments

Unknown commands

File read errors

Invalid word input

Exceptions thrown from TextAnalyser

All exceptions are caught at the CLI layer and presented cleanly to the user.

------------------------------------------------------------------------------------------------------------------------------------------------------------
🎯 Design Philosophy

The tool follows a clean separation of concerns:

TextAnalyser: pure logic, no I/O

CLI: argument parsing, routing, printing

main: minimal bootstrap (cli.run(argc, argv))

This makes the project easy to extend, test, and maintain.

------------------------------------------------------------------------------------------------------------------------------------------------------------
📄 License

This project is for educational and personal development purposes.
Feel free to modify or extend it as needed.

------------------------------------------------------------------------------------------------------------------------------------------------------------
If you have a question please feel free to ask you can find me on these ways 👇:
Email: kasrabakhshaei25@gmail.com
LinkedIn: www.linkedin.com/in/kasra-bakhshaei-061517336



















