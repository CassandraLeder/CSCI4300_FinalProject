#include "page.h" 

Page::Page(const char data, Page* ptr) {
    this->data = data;
    next = ptr;
}