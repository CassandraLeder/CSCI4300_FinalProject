#pragma once
#include "input.h"
// define a frame

class Frame {
    public:
        Frame();
        Frame(int);
        ~Frame();
        bool isEmpty();
        bool isEmpty(int);
        int findEmptyFrame();
        void add(char, int);
        void replace(char, int);
        std::string* getFrame();
        char lookupFrame(int);
        int FRAME_SIZE;
        int page_fault;   

    private:
        std::string* frame;   

};