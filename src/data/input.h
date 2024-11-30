#pragma once
#include <string>
#include <stdexcept>
#include <memory>
#include "page.h"

// represent input string as a linked list using smart pointers
class Input {
    public:
        Input();
        Input(std::string);
        ~Input(); // = default for smart
        bool is_empty();
        void insert(Page);
        void fill();
        Page* getFirstPage();
        char algorithm_type;
        int node_count;
        int frame_size;


    private:
        std::string input_string;
        // represents first page or node
        // std::usual_pointer<Page> first_page;
        Page* first_page;
};