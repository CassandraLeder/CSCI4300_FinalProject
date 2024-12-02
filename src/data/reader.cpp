#include "reader.h"

// constructor
// default
Reader::Reader() {
    files = nullptr;
    file_list = "";
}

// actual
Reader::Reader(std::string file_list) {
    file_obj.open(file_list, std::ifstream::in);
    
    // if file list path failed to open
    if (!file_obj.is_open()) {
        throw std::invalid_argument("\nFile list is not valid. Check path entered.\n");
    }

    this->file_list = file_list;
    files = new std::string[MAX_FILES]; // 3 by default

    std::string file = ""; // file name will be outputted here
    int count = 0;

    while (getline(file_obj, file, '\n')) {
        files[count] = file;
        ++count;
    }

    file_obj.close();
}

// destructor
Reader::~Reader() {
    delete[] files;
}

// return contents of file as a string
std::string Reader::readFile(std::string file) {
    // open file
    file_obj.open(file, std::ifstream::in);

    // if file failed to open
    if (!file_obj.is_open()) {
        throw std::invalid_argument("\nFile is not valid. Check path entered. File name: " + file);
    }

    // get file content
    std::string content((std::istreambuf_iterator<char>(file_obj)), 
            (std::istreambuf_iterator<char>()));

    // close file
    file_obj.close();

    return content;
}

std::string* Reader::readFiles() {

    if (files == nullptr) {
        throw std::invalid_argument("\nList of file names was null.\n");
    }

    std::string *contents = new std::string[MAX_FILES]();

    // for every file in files
    for (int i = 0; i < MAX_FILES; i++) {
        // get contents
        contents[i] = readFile(files[i]);
    }

    return contents;
}