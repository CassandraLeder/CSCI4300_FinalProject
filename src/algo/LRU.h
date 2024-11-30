#pragma once
#include "replacement.h"

// implementation of least recently used page replacement algorithm

class LRU : public Replacement {
    public:
        LRU();
        LRU(const Input&);
        ~LRU();
        void run();
        void use(Frame, char);
    private:
        int *last_used;
};