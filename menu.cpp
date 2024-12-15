#include "header.h"

int chooseLastFirst() {
    cout << "------------------------------------" << endl;
    cout << "|          Last or First           |" << endl;
    cout << "------------------------------------" << endl;
    cout << "| 1. Last                          |" << endl;
    cout << "| 2. First                         |" << endl;
    cout << "------------------------------------" << endl;
    int opt;
    cout << "  Option : ";
    cin >> opt;
    cout << "------------------------------------" << endl;
    if (opt != 1 || opt != 2) {
        cout << "Invalid Option!" << endl;
        chooseLastFirst();
    } else {
        return opt;
    }
}