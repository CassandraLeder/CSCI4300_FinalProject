#pragma once
#include "input.h"
// define a frame

class Frame {
    public:
        int FRAME_SIZE;
        Frame();
        Frame(Input);
        ~Frame() = default;
        bool isEmpty();
        bool isEmpty(int);
        int findEmptyFrame();
        void add(char, int);
        void replace(char, int);
        std::string* getFrame();
        char lookupFrame(int);
        int page_fault;   

    private:
        Input in;
        std::string* frame;   

};