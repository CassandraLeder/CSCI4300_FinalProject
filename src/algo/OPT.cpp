#include "OPT.h"
#include <array>

OPT::OPT() : Replacement() {
}

// calls super constructor
OPT::OPT(Page* head, int frame_size) : Replacement(head, frame_size) {
}

// greatest element will be sorted at the very bottom of array
std::pair<int, char> OPT::returnGreatestPair(std::array<std::pair<int, char>, size> list) {
    return (list[(size - 1)]);
}

// least element is equal to bottom of array - frame_size
std::pair<int, char> OPT::returnLowestPair(std::array<std::pair<int, char>, size> list) {
    return (list[(size - 1) - getFrame()->FRAME_SIZE]);
}

// create a prediction array and return most likely pages
std::array<std::pair<int, char>, OPT::size>  
OPT::predict(Page* current_head) {

    if (getFrame()->FRAME_SIZE > size) {
        throw std::invalid_argument("\nFrame size greater than error size. See OPR.cpp\n");
    }

    std::array<std::pair<int, char>, size> values;
    std::map<char, int> predictions;

    while (current_head != nullptr) {
        ++predictions[current_head->data];
        current_head = current_head->next;
    }

    int i = 0;

    for (auto& it : predictions) {
        values[i] = std::make_pair(it.second, it.first);
        ++i;
    }

    // sort based on integer
    std::sort(values.begin(), values.end());

    return values;
}

// run algorithm
void OPT::run() {
    // setup
    setupFrame();
    Page* page = getList();
    Frame* frame_obj = getFrame();

    while (page != nullptr) {
        
        // already loaded in frame
        if (searchDuplicate(frame_obj->getFrame(), frame_obj->FRAME_SIZE, page->data)) {
            skip();
            page = page->next;
            continue;
        }
        else { // replacement
            auto predictions = predict(page);
                        
            // we want to replace lowest element in the sorted list with the highest element 
            auto highest_pair = returnGreatestPair(predictions);
            auto lowest_pair = returnLowestPair(predictions);
            int lowest_index = 0;

            for (int i = 0; i < frame_obj->FRAME_SIZE; i++) {
                if (frame_obj->lookupFrame(i) == lowest_pair.second) {
                    lowest_index = i;
                }
            }

            frame_obj->replace(highest_pair.second, lowest_index);
        }

        // advance pointer
        page = page->next;
    }
}