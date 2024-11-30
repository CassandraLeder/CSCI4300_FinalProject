#include "replacement.h"

Replacement::Replacement() {
    list = nullptr;
}

Replacement::Replacement(Input reference) {
    list = reference.getFirstPage();
    frame_obj = Frame(reference);
}

// shared algorithmic steps
// takes a frame that has not been set up at all
// add elements until frame size reached
void Replacement::setupFrame() {

    for (int i = 0; i < frame_obj.FRAME_SIZE - 1; i++) {
        // add each page to frame
        frame_obj.add(list->data, i); // method will add to page fault counter

        // reference string as linked list
        list = list->next;   
    }
}

// performs the action for when page already loaded in frame
void Replacement::skip() {
    moves[list->data] = " ";
    list = list->next;
}
        
        /* GETTERS */
Page* Replacement::getList() { return list; }
Frame Replacement::getFrame() { return frame_obj; }
std::map<char, std::string> Replacement::getMoves() { return moves; }
        
        /* SETTERS AND ADDERS */
// assume user knows position (faster)
void Replacement::addMove(char integer, std::string data) {
    moves[integer] = data;
}  

void Replacement::setFrame(Frame frame_obj) { this->frame_obj = frame_obj; }