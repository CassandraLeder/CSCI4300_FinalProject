#include "printer.h"

/* TODO: FINISH THIS AFTER ALGORITHM IMPLEMENTATIONS ARE COMPLETE */

// display current frame
void Printer::display(Frame frame) {
    // create top of frame drawing
    std::cout << "\n_________________";
    
    // print cells and bottom of frame drawing
    for (int i = 0; i < frame.FRAME_SIZE; i++) {
        std::cout << "|\n|\n|\n|   " + frame.getFrame()[i] + "   |"
        + "\n\n_______________";
    }
}

// display reference stream
void Printer::display(Input in) {
    Page* temp = in.getFirstPage();

    // traverse linked list
    while (temp->next != nullptr) {
        std::cout << temp->data << "    "; 
        temp->next;
    }
}

void Printer::display(Frame frame, Input in) {
    display(frame);
    display(in);
}