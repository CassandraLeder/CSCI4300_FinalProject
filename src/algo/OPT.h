#pragma once
#include "replacement.h"

// implementation of optimal page replacement algorithm

class OPT : public Replacement {
    public:
        OPT();
        OPT(const Input&);
        ~OPT();
        void run();
        Page* predict();
        Page* optimal_page();

    private:
        
};