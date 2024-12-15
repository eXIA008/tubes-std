#include "header.h"

int chooseLastFirst() {
    int opt;
    while (true) {
        cout << "------------------------------------" << endl;
        cout << "|          Last or First           |" << endl;
        cout << "------------------------------------" << endl;
        cout << "| 1. Last                          |" << endl;
        cout << "| 2. First                         |" << endl;
        cout << "------------------------------------" << endl;
        cout << "  Option : ";
        cin >> opt;
        cout << "------------------------------------" << endl;

        if (opt == 1 || opt == 2) {
            return opt;
        } else {
            cout << "Invalid Option! Please try again." << endl;
        }
    }
}