#pragma once
#include "input.h"
#include <vector> // only used to generate a history of frames for ease of output
// define a frame

class Frame {
    public:
        Frame();
        Frame(int);
        ~Frame();
        bool isEmpty();
        int findEmptyFrame();
        void add(char, int);
        void replace(char, int);
        void skipHistory();
        std::string* getFrame();
        std::vector<std::vector<std::string>> getHistory();
        char lookupFrame(int);
        int FRAME_SIZE;
        int page_fault;   

    private:
        void populateHistory();
        std::string* frame;   
        std::vector<std::vector<std::string>> history; // used to store history of frames for printing purposes
};