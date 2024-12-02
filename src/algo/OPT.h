#pragma once
#include "replacement.h"

// implementation of optimal page replacement algorithm

class OPT : public Replacement {
    public:
        OPT();
        OPT(Page*, int);
        void run();
        static const int size = 20;

    private:
        std::pair<int, char> returnGreatestPair(std::array<std::pair<int, char>, size>);
        std::pair<int, char> returnLowestPair(std::array<std::pair<int, char>, size>);
        // I do not know how to avoid hardcoding the size here
        std::array<std::pair<int,char>, size> predict(Page*);
};