#pragma once
#include <algorithm> // std::max_element(), std::find(), std::distance()
#include <map> // used for keeping track of moves
#include "..\data\frame.h"
#include "..\data\printer.h"

class Replacement {
    public:
        Replacement();
        Replacement(Page*, int);
        ~Replacement();
        // abstract parts of the algorithm that can be shared
        bool searchDuplicate(std::string*, int, char);
        void setupFrame();
        void skip();
        // only difference in page replacement algorithms is how they choose to replace a page

        // getters 
        Page* getList();
        Frame* getFrame();
        Printer* getPrinter();
        std::map<char, std::string> getMoves();
        
        // setters
        void addMove(char, std::string, bool = true);

    private:
        Frame* frame_obj;
        Printer printer;
        Page* list;
        std::map<char, std::string> moves;
};