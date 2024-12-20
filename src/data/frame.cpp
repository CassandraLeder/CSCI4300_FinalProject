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
    for (int i = 0; i < FRAME_SIZE; i++) {
        frame[i] = "";
    }
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

    populateHistory();
}

void Frame::replace(char data, int position) {
    if (frame[position].empty()) {
        throw std::invalid_argument("\nCannot replace empty page.\n");
    }

    // replacement is valid
    frame[position] = std::string(1, data);
    ++page_fault;

    populateHistory();
}

void Frame::skipHistory() {
    std::vector<std::string> data;
    data.push_back(",");
    history.push_back(data);
}

// getter
std::string* Frame::getFrame() {
    return frame;
}

std::vector<std::vector<std::string>> Frame::getHistory() {
    return history;
}

char Frame::lookupFrame(int position) {
    return frame[position][0];
}



void Frame::populateHistory() {
    std::vector<std::string> data;

    for (int i = 0; i < FRAME_SIZE; i++) {
        data.push_back(frame[i]);
    }

    history.push_back(data);
}