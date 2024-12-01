#pragma once
#include "replacement.h"

// implementation of optimal page replacement algorithm

class OPT : public Replacement {
    public:
        OPT();
        OPT(Page*, int);
        ~OPT();
        void run();
        Page* predict();
        Page* optimal_page();

    private:
        
};