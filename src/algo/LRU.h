#pragma once
#include "replacement.h"

// implementation of least recently used page replacement algorithm

class LRU : public Replacement {
    public:
        LRU();
        LRU(Page*, int);
        ~LRU();
        void run();
        void use(std::string*, int, char);
    private:
        int *last_used;
};