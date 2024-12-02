#pragma once
#include "replacement.h"

// implementation of the least of first-in-first-out page replacement algorithm

class FIFO : public Replacement {
    public:
        FIFO();
        FIFO(Page*, int);
        ~FIFO();
        void run();

    private:
        int *age;
        // helper method for run()
        int findOldestIndex(int*, int);
        void age_pages(std::string*, int);
        void age_setup(int);

};