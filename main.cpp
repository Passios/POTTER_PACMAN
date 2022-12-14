#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "Engine.h"

using namespace std;

int main(int argc, char* argv[]) {

    if (argc != 3) {
        cout << "Usage: " << argv[0] << " *map file* *score file*" << endl;
        return EXIT_FAILURE;
    }

    Engine* e = NULL;
    try {
        e = new Engine(argv[1], argv[2]);
    } catch (ios_base::failure& e) {
        cerr << "IO error: " << e.what() << endl;
    } catch (invalid_argument& e) {
        cerr << "Argument error: " << e.what() << endl;
    }

    if (e != NULL) {
        e->startGame();
        delete e;
    }

    //system("PAUSE");
    return EXIT_SUCCESS;
}
