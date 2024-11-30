#pragma once
#include <string>
#include <fstream> // ifstream
#include <stdexcept> // std::invalid_arg

class Reader {
    public:
        const static int MAX_FILES = 3;
        Reader();
        Reader(std::string);
        ~Reader();
        std::string* readFiles();

    private:
        // helper function for readFiles()
        std::string readFile(std::string);
        std::ifstream file_obj;
        std::string file_list;
        std::string* files;
};