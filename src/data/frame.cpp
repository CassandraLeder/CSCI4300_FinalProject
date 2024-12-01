#include "frame.h"

// constructor
// default (DON'T USE)
Frame::Frame() {
    frame = nullptr;
    page_fault = 0;
    FRAME_SIZE = 0;
}

// actual constructor
Frame::Frame(int frame_size) {
    FRAME_SIZE = frame_size;
    frame = new std::string[frame_size]();
    page_fault = 0;
}

// destructor
Frame::~Frame() {
    delete[] frame;
}

bool Frame::isEmpty() {
    bool empty = true;

    for (int i = 0; i < Frame::FRAME_SIZE; i++) {
        if (frame[i] != "") {
            empty = false;
        }
    }

    return empty;
}

bool Frame::isEmpty(int position) {
    if (frame[position] == "")
        return true;
    else
        return false;
}

// returns first empty frame
int Frame::findEmptyFrame() {
    for (int i = 0; i < FRAME_SIZE; i++) {
        if (!isEmpty(i)) {
            return i;
        }
    }

    // if no empty frames
    return -1;
}

// position = column or row in array 
void Frame::add(char data, int position) {
    
    // if position occupied
    if (!isEmpty(position)) {
        throw std::invalid_argument("\nCannot add " + std::to_string(data)
                                        + " because position is occupied by " + frame[position]);
    }

    frame[position] = data;
    ++page_fault;
}

void Frame::replace(char data, int position) {
    if (isEmpty(position)) {
        throw std::invalid_argument("\nCannot replace empty page.\n");
    }

    // replacement is valid
    frame[position] = data;
    ++page_fault;
}

// getter
std::string* Frame::getFrame() {
    return frame;
}

char Frame::lookupFrame(int position) {
    return frame[position][0];
}