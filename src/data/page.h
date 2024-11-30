#pragma once
// defines a page (basically a node)

class Page {
    public:    
        Page(const char, Page* ptr = nullptr);
        char data;
        Page* next;
};