#include "FIFO.h"

// default constructor
FIFO::FIFO() : Replacement() {
    age = nullptr;
}

// calls super constructor
// avoid data being passed around
FIFO::FIFO(Page* head, int frame_size) : Replacement(head, frame_size) {
    age = new int[frame_size]();
}

FIFO::~FIFO() {
    delete[] age;
}



// ages all existing pages within frame
// helper method for run()
void FIFO::age_pages(std::string* frame, int frame_size) {
    for (int i = 0; i < frame_size; i++) {
        if (!frame[i].empty()) {
            ++age[i];
        }
    }
}

void FIFO::age_setup(int frame_size) {
    for (int i = 0; i < frame_size; i++) {
        age[i] += frame_size - i; // first element is frame size old and so on
    }
}

// returns index of first occurance of oldest (in case of tie)
// helper method for run()
int FIFO::findOldestIndex(int* age, int frame_size) {
    return (std::distance(age, 
                    std::max_element(age, age + frame_size)));
}

void FIFO::run() {
    // setup
    setupFrame();
    Page* page = getList();
    Frame* frame_obj = getFrame();
    age_setup(frame_obj->FRAME_SIZE);

    // main loop of algorithm
    while (page != nullptr) {
        // if current page already in frame
        if (searchDuplicate(frame_obj->getFrame(), frame_obj->FRAME_SIZE, page->data)) {
            skip();
            age_pages(frame_obj->getFrame(), frame_obj->FRAME_SIZE);
            page = page->next;
            continue;
        }
        else { // if page not in frame
            // must replace a page
            int oldest_index = findOldestIndex(age, frame_obj->FRAME_SIZE);

            frame_obj->replace(page->data, oldest_index);
            addMove(page->data, 
                    frame_obj->getFrame()[oldest_index] + "->" + page->data); // ex. 3->2
            age[oldest_index] = 0; // reset age
        }
        
        // age all pages
        age_pages(frame_obj->getFrame(), frame_obj->FRAME_SIZE);
        // onto next page
        page = page->next;
    }
}