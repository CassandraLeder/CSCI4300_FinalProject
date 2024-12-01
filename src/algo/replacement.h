#pragma once
#include <algorithm> // std::max_element
#include <map>

#include "..\data\frame.h"
#include "..\data\printer.h"

class Replacement {
    public:
        Replacement();
        Replacement(Page*, int);
        // abstract parts of the algorithm that can be shared
        void setupFrame();
        void skip();
        // only difference in page replacement algorithms is how they choose to replace a page

        // getters 
        Page* getList();
        Frame getFrame();
        std::map<char, std::string> getMoves();
        
        // setters
        void addMove(char, std::string);
        void setFrame(Frame);


    private:
        Frame frame_obj;
        Printer printer;
        Page* list;
        std::map<char, std::string> moves;
};