#include "FIFO.h"

// default constructor
FIFO::FIFO() : Replacement() {
    age = nullptr;
}

// calls super constructor
// avoid data being passed around
FIFO::FIFO(Input reference) : Replacement(reference) {
    age = new int[Replacement::getFrame().FRAME_SIZE - 1]();
}

FIFO::~FIFO() {
    delete[] age;
}

// ages all existing pages within frame
// helper method for run()
void FIFO::age_pages(Frame frame_obj) {
    for (int i = 0; i < frame_obj.FRAME_SIZE - 1; i++) {
        if (!frame_obj.isEmpty(i)) {
            ++age[i];
        }
    }
}

void FIFO::run() {
    // setup
    Page* page = getList();
    Page* next = page->next;
    Frame frame_obj = getFrame();
    Replacement::setupFrame();

    // main loop of algorithm
    while (next != nullptr) {
        // if current page already in frame
        if (frame_obj.getFrame()->find(page->data)) {
            Replacement::skip();
        }
        else { // if page not in frame
            // must replace a page
            int oldest = *std::max_element(age, age + (frame_obj.FRAME_SIZE - 1));
            int index = *std::find(age, age + (frame_obj.FRAME_SIZE - 1), oldest);

            frame_obj.replace(page->data, index);
            addMove(page->data, 
                    frame_obj.getFrame()[index] + "->" + page->data); // ex. 3->2
            age[index] = 0; // reset age
        }
        
        // age all pages
        age_pages(frame_obj);
        // onto next page
        page = page->next;
        next = page;
    }
}