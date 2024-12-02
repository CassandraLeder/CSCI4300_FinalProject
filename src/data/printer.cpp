#include "printer.h"

using namespace std;

void Printer::display_header(char algo_type) {
    switch (algo_type) {
        case 'F':
            std::cout << "FIFO:   ";
            break;
        case 'L':
            std::cout << endl << endl << "\n\nLRU:    ";
            break;
        case 'O':
            std::cout << endl << endl << "\n\nOPT:    ";
            break;

        default:
            std::cerr << "Error! Algorithm type is not 'F', 'L', or 'R'. It's " << algo_type;
    }
}

// display current frame
void Printer::display(vector<vector<string>> frame_history) {
    cout << endl;

    // print header
    for (int i = 0; i < frame_history.size(); i++) {
        
        if (frame_history[i].size() > 1) {
            cout << left << "     " << "________" << setw(2);
        }
        else { // in case of a skip
            cout << left << "        " << ",     ";
        }
    }

    cout << endl;

    // print cells and bottom of frame drawing
    for (int i = 0; i < frame_history[0].size(); i++) { // frame_history[0] will always equal frame size
        for (int j = 0; j < frame_history.size(); j++) {
            if (frame_history[j].size() > 1) {
                cout << left << "   " << "|" << setw(2) << "   " << frame_history[j][i] << "  " << setw(3) << "   " <<"|";
            }
            else {
                cout << "           ";
            }
        }

        cout << endl;
    }

    // create footer
    for (int i = 0; i < frame_history.size(); i++) {
        if (frame_history[i].size() > 1) {
            cout << left << "     " << "________" << setw(2);
        }
        else {
            cout << "           ";
        }
    }
}


// display reference stream
void Printer::display(Page* head) {
    
    // traverse linked list
    while (head != nullptr) {
        std::cout << head->data << "            "; 
        head = head->next;
    }
}

void Printer::display_closer(int page_fault) {
    std::cout << "  " << page_fault << " faults";
}