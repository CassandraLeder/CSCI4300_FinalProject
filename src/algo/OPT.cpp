#include "OPT.h"

/* TODO: LEARN HOW TO IMPLEMENT THIS LOL */

OPT::OPT() : Replacement() {
    
}
// calls super constructor
OPT::OPT(const Input& reference) : Replacement(reference) {

}

OPT::~OPT() {

}

// run algorithm
void OPT::run() {
    // setup
    Page* page = Replacement::getList();
    Page* next = page->next;
    Frame frame_obj = Replacement::getFrame();
    Replacement::setupFrame();

    while (next != nullptr) {
        
    }
}

Page* OPT::predict() {
    return new Page('b', nullptr);
}

Page* OPT::optimal_page() {
    return new Page('b', nullptr);
}