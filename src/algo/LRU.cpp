#include "LRU.h"

// fake constructor
LRU::LRU() : Replacement() {
    last_used = nullptr;
}

// this constructor calls super constructor
LRU::LRU(Page* head, int frame_size) : Replacement(head, frame_size) {
    last_used = new int[frame_size]();
}

LRU::~LRU() {
    delete[] last_used;
}

void LRU::use(std::string* frame, int frame_size, char data) {
    // find the index of data in frame
    int index = std::distance(frame, std::find(frame, frame + frame_size, data));
    ++last_used[index];
}

void LRU::run() {
    // setup
    setupFrame();
    Page* page = getList();
    Page* next = page->next;
    Frame* frame_obj = getFrame();

    // main loop of algorithm
    while (next != nullptr) {
        // if current page already in frame
        if (searchDuplicate(frame_obj->getFrame(), frame_obj->FRAME_SIZE, page->data)) {
            use(frame_obj->getFrame(), frame_obj->FRAME_SIZE, page->data);
            skip();
            
            // onto next page
            page = page->next;
            next = page->next;

            continue;
        }
        else { // if page not in frame
            // must replace a page

            // find index of min element of last_used array
            int least_used = std::distance(last_used, 
                                        std::min_element(last_used, last_used + (frame_obj->FRAME_SIZE)));
            frame_obj->replace(page->data, least_used);
            last_used[least_used] = 0; // reset last used
        }

        // onto next page
        page = page->next;
        next = page->next;
    }
}