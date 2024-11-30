#include "LRU.h"

/* TODO: GET FIFO WORKING FIRST */

// fake constructor
LRU::LRU() : Replacement() {
    last_used = nullptr;
}

// this constructor calls super constructor
LRU::LRU(const Input& reference) : Replacement(reference) {
    last_used = new int[Replacement::getFrame().FRAME_SIZE - 1]();
}

LRU::~LRU() {
    delete[] last_used;
}

void LRU::use(Frame frame_obj, char data) {
    for (int i = 0; i < frame_obj.FRAME_SIZE - 1; i++) {
        if (frame_obj.lookupFrame(i) == data) {
            ++last_used[i];
        }
    }
}

void LRU::run() {
    // setup
    Page* page = Replacement::getList();
    Page* next = page->next;
    Frame frame_obj = Replacement::getFrame();
    Replacement::setupFrame();

    // main loop of algorithm
    while (next != nullptr) {
        // if current page already in frame
        if (frame_obj.getFrame()->find(page->data)) {
            Replacement::skip();
            use(frame_obj, page->data);
        }
        else { // if page not in frame
            // must replace a page
            int least_used = *std::min_element(last_used, last_used + (frame_obj.FRAME_SIZE - 1));
            frame_obj.replace(page->data, least_used);
            last_used[frame_obj.getFrame()->find(least_used)] = 0; // reset last used
        }

        // onto next page
        page = page->next;
        next = page;
    }
}