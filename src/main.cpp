  /* header files */
#include "data\reader.h"
#include "data\printer.h"
#include "algo\FIFO.h" // these classes include all other written classes
#include "algo\LRU.h"
#include "algo\OPT.h"

/*
    Page Replacement algorithms implementation 
    by Cassandra Leder on 27/11/24
*/ 

/*
    GLOBAL CONSTANTS
*/
// for testing
const static std::string LIST_OF_FILES = "./files.txt";


int main(int argc, char **argv) {

    // if one arg not supplied
    /* if (argc != 2) {
        std::cout << "Usage: a.out [.txt file with list of input files]";
        return EXIT_FAILURE;
    } */

    Reader file_reader(LIST_OF_FILES); // or *argv[1]

    // returns pointer to array of all file contents from list
    std::string *file_contents = file_reader.readFiles();

    Printer printer;

    // main program loop
    for (int i = 0; i < file_reader.MAX_FILES; i++) {
        Input *in = new Input(file_contents[i]);
        in->fill(); // add reference to linked list
        
        printer.display_header(in->algorithm_type);

        // find algorithm type
        // FIFO selected
        if (in->algorithm_type == 'F') { 
            FIFO fifo(in->getFirstPage(), in->frame_size); // create object
            fifo.run(); // run algorithm

            printer.display(fifo.getFrame()->getHistory());
            printer.display_closer(fifo.getFrame()->page_fault); // display page faults
        }
        else if (in->algorithm_type == 'L') {
            LRU lru(in->getFirstPage(), in->frame_size);
            lru.run();

            printer.display(lru.getFrame()->getHistory());
            printer.display_closer(lru.getFrame()->page_fault);
        }
        else if (in->algorithm_type == 'O') {
            OPT opt(in->getFirstPage(), in->frame_size);
            opt.run();

            printer.display(opt.getFrame()->getHistory());
            printer.display_closer(opt.getFrame()->page_fault);
        }
        else {
            throw std::invalid_argument("\nThe algorithm type in the reference string does not match any of the avaliable algorithms.\n");
        }

        delete in; // remove linked list of data
    }

    delete[] file_contents;
    return EXIT_SUCCESS;
}
