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
    int index = -1;

    // find the index of data in frame
    for (int i = 0; i < frame_size; i++) {
        if (frame[i] == std::string(1, data)) {
            index = i;
        }
    }

    if (index == -1) {
        throw std::invalid_argument("Data passed to function could not be found. data is " + data);
    }

    // otherwise increment used element
    ++last_used[index];
}

// overriden method from parent function
// checks for any skips that might have occured when setting up program
Page* LRU::setupFrame(Frame* frame_obj, Page* head) {
    if (frame_obj == nullptr) {
        throw std::invalid_argument("\nframe_obj is null.\n");
    }

    getPrinter()->display(head);

    int i = 0;

    // until every spot in frame is full
    while (i != frame_obj->FRAME_SIZE) {
        // if this page already loaded into frame
        if (searchDuplicate(frame_obj->getFrame(), frame_obj->FRAME_SIZE, head->data)) {
            skip();
            use(frame_obj->getFrame(), frame_obj->FRAME_SIZE, head->data);
            head = head->next; // not using original parent functions head so skip does not increment
            continue; // do not increment i because we would skip over potential index
        }

        // add each page to frame
        frame_obj->add(head->data, i); // method will add to page fault counter
        addMove(head->data, "empty->" + std::string(1, head->data)); // update moves

        // reference string as linked list
        head = head->next;   
        ++i;
    }

    return head;
}

void LRU::run() {
    // setup
    Page* page = setupFrame(getFrame(), getList());
    Frame* frame_obj = getFrame();

    // main loop of algorithm
    while (page != nullptr) {
        // if current page already in frame
        if (searchDuplicate(frame_obj->getFrame(), frame_obj->FRAME_SIZE, page->data)) {
            use(frame_obj->getFrame(), frame_obj->FRAME_SIZE, page->data);
            skip();
            
            // onto next page
            page = page->next;
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
    }
}