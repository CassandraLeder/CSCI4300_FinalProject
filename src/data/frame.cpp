#include "frame.h"
#include <iostream> // delete this
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

// tests if whole frame is empty as oppossed to a specific position in frame being empty
bool Frame::isEmpty() {
    bool empty = true;

    for (int i = 0; i < Frame::FRAME_SIZE; i++) {
        if (frame[i].empty()) {
            empty = false;
        }
    }

    return empty;
}
// returns first empty frame
int Frame::findEmptyFrame() {
    for (int i = 0; i < FRAME_SIZE; i++) {
        if (frame[i].empty()) {
            return i;
        }
    }

    // if no empty frames
    return -1;
}

// position = column or row in array 
void Frame::add(char data, int position) {
    // this should require error checking but c++ has garbage values so it's easier to assume position already empty
    frame[position] = std::string(1, data); // convert char->string
    ++page_fault;
}

void Frame::replace(char data, int position) {
    if (frame[position].empty()) {
        throw std::invalid_argument("\nCannot replace empty page.\n");
    }

    // replacement is valid
    frame[position] = std::to_string(data);
    ++page_fault;
}

// getter
std::string* Frame::getFrame() {
    return frame;
}

char Frame::lookupFrame(int position) {
    return frame[position][0];
}