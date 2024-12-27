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

void mainMenu() {
    int opt;
    while (true) {
        cout << "------------------------------------" << endl;
        cout << "|             Main Menu            |" << endl;
        cout << "------------------------------------" << endl;
        cout << "| 1. Blogger                       |" << endl;
        cout << "| 2. Platform                      |" << endl;
        cout << "| 3. Exit                          |" << endl;
        cout << "------------------------------------" << endl;
        cout << "| Option : ";
        cin >> opt;
        cout << "------------------------------------" << endl;
        if (opt == 1) {
            menuBlogger();
        } else if (opt == 2) {
            menuPlatform();
        } else if (opt == 3) {
            return;
        } else {
            cout << "Invalid Option!" << endl;
        }
    }
}

void menuBlogger() {
    int opt;
    while (true) {
        cout << "------------------------------------" << endl;
        cout << "|           Menu Blogger           |" << endl;
        cout << "------------------------------------" << endl;
        cout << "| 1. Tambah Blogger                |" << endl;
        cout << "| 2. Tampilkan Blogger             |" << endl;
        cout << "| 3. Hapus Blogger dan Platform    |" << endl;
        cout << "| 4. Cari Blogger                  |" << endl;
        cout << "| 5. Back                          |" << endl;
        cout << "------------------------------------" << endl;
        cout << "| Option : ";
        cin >> opt;
        cout << "------------------------------------" << endl;
        if (opt == 1) {
            menuBlogger();
        } else if (opt == 2) {
            menuPlatform();
        } else if (opt == 3) {
            return;
        } else {
            cout << "Invalid Option!" << endl;
        }
    }
}

void menuPlatform() {
    int opt;
    while (true) {
        cout << "------------------------------------" << endl;
        cout << "|             Main Menu            |" << endl;
        cout << "------------------------------------" << endl;
        cout << "| 1. Blogger                       |" << endl;
        cout << "| 2. Platform                      |" << endl;
        cout << "| 3. Print All                     |" << endl;
        cout << "| 4. Exit                          |" << endl;
        cout << "------------------------------------" << endl;
        cout << "| Option : ";
        cin >> opt;
        cout << "------------------------------------" << endl;
        if (opt == 1) {
            menuBlogger();
        } else if (opt == 2) {
            menuPlatform();
        } else if (opt == 3) {
            return;
        } else {
            cout << "Invalid Option!" << endl;
        }
    }
}