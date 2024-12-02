#pragma once
#include "replacement.h"

// implementation of least recently used page replacement algorithm

class LRU : public Replacement {
    public:
        LRU();
        LRU(Page*, int);
        ~LRU();
        void run();
    private:
        void use(std::string*, int, char);
        Page* setupFrame(Frame*, Page*);
        int *last_used;

};