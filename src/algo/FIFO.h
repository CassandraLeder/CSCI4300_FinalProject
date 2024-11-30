#pragma once
#include "replacement.h"

// implementation of the least of first-in-first-out page replacement algorithm

class FIFO : public Replacement {
    public:
        FIFO();
        FIFO(Input);
        ~FIFO();
        void run();

    private:
        int *age;
        // helper method for run()
        void age_pages(Frame);

};