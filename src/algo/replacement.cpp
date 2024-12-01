#include "replacement.h"

Replacement::Replacement() {
    list = nullptr;
    printer = Printer();
    frame_obj = nullptr;
}

Replacement::Replacement(Page* head, int frame_size) {
    list = head;
    printer = Printer();
    frame_obj = new Frame(frame_size);
}

// destructor
Replacement::~Replacement() {
    delete frame_obj;
}


bool Replacement::searchDuplicate(std::string* frame, int frame_size, char data) {
    if (frame->find(data) != std::string::npos) {
        return true;
    }

    return false;
}

// shared algorithmic steps
// takes a frame that has not been set up at all
// add elements until frame size reached
void Replacement::setupFrame() {
    if (frame_obj == nullptr) {
        throw std::invalid_argument("\nframe_obj is null.\n");
    }

    for (int i = 0; i < frame_obj->FRAME_SIZE; i++) {
        
        // if this page already loaded into frame
        if (searchDuplicate(frame_obj->getFrame(), frame_obj->FRAME_SIZE, list->data)) {
            skip();
            continue;
        }

        // add each page to frame
        frame_obj->add(list->data, i); // method will add to page fault counter
        addMove(list->data, "empty->" + std::string(1, list->data)); // update moves

        // reference string as linked list
        list = list->next;   
    }
}

// performs the action for when page already loaded in frame
void Replacement::skip() {
    moves[list->data] = ",";
    list = list->next;
}
        
        /* GETTERS */
Page* Replacement::getList() { return list; } // so one can point at the value
Frame* Replacement::getFrame() { return frame_obj; }
std::map<char, std::string> Replacement::getMoves() { return moves; }
        
        /* SETTERS AND ADDERS */
// assume user knows position (faster)
void Replacement::addMove(char integer, std::string data, bool replace) {
    if (replace) {
        moves[integer] = data;
    }
    else { // in the special case of skipping 
        std::pair<char, std::string> pair (integer, data);
        moves.insert(pair);
    }
}  
