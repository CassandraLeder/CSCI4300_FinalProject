#pragma once
#include <iostream>
#include <iomanip>
#include "..\data\frame.h"

// displays frames and data because I am lazy

class Printer {
    public:
        // header and closer will be printed by main and display methods will be printed within classes
        void display_header(char);
        void display(std::vector<std::vector<std::string>>);
        void display(Page*);
        void display_closer(int);
};