#pragma once
#include <iostream>
#include "frame.h"
#include "input.h"

// displays frames because I am lazy

class Printer {
    public:
        void display(Frame);
        void display(Input);
        void display(Frame, Input);
};