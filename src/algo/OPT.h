#pragma once
#include "replacement.h"

// implementation of optimal page replacement algorithm

class OPT : public Replacement {
    public:
        OPT();
        OPT(Page*, int);
        void run();

    private:
        std::pair<int, char> returnGreatestPair(std::array<std::pair<int, char>, 500>);
        std::pair<int, char> returnLowestPair(std::array<std::pair<int, char>, 500>);
        // I do not know how to avoid hardcoding the size here
        std::array<std::pair<int,char>, 500> predict(Page*);
};