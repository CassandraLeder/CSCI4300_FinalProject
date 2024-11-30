#include "input.h"

const static char INPUT_DELIMITER = ',';

// constructor
// default (DON'T USE)
Input::Input() {
    first_page = nullptr;
    input_string = "";
}

// actual constructor
Input::Input(std::string input_string) {
    first_page = nullptr;
    this->input_string = input_string;
}

Input::~Input() {
    Page* temp = first_page;

    // delete every dynamically allocated page
    while(temp != nullptr) {
        Page* del = temp;
        temp = temp->next;
        delete del;
    }

    first_page = nullptr;
}

bool Input::is_empty() {
    if (first_page == nullptr)
        return true;
    else
        return false;
}

void Input::insert(Page page) {
    bool found = false;
    Page* new_page = new Page(page);
    Page* temp = first_page;

    if (first_page == nullptr) {
        new_page->next = nullptr;
        first_page = new_page;
    }
    else { // first page occupied 
        while (!found) { // find and replace next space
            Page* next = temp->next;
            
            if (next == nullptr) {
                found = true;
                new_page->next = nullptr;
                temp->next = new_page;
            }
            else {
                temp = temp->next;
            }
        } 
    }
}

// update entire linked list based on input string
void Input::fill() {
    if (input_string == "") {
        throw std::invalid_argument("\nInput string is empty\n");
    }

    // else begin fill
    int count = 0;

    // explore string for each character
    for (char& character : input_string) {

        // ',' by default
        if (character != INPUT_DELIMITER) {
            // first character dictates algorithm type
            if (count == 0) {
                algorithm_type = character;
                ++count;
            }
            else if (count == 1) {
                // convert char to int
                frame_size = character - '0';
                ++count;
            }
            else { // for every other case
                Page* new_page = new Page(character);
                Input::insert(*new_page); // insert new character in the linked list
                ++count;
            }
        }
    }

    // remember character and frame size technically counted towards count
    node_count = count - 2;
}

Page* Input::getFirstPage() {
    return first_page; // .get()
}