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
            cout << "Invalid Option!" << endl;
        }
    }
}

void mainMenu(ListB B, ListP P, ListW W) {
    int opt;
    while (true) {
        system("cls");
        cout << "------------------------------------" << endl;
        cout << "|             Main Menu            |" << endl;
        cout << "------------------------------------" << endl;
        cout << "| 1. Blogger                       |" << endl;
        cout << "| 2. Platform                      |" << endl;
        cout << "| 3. Tampilkan Blogger dan platform|" << endl;
        cout << "| 4. Exit                          |" << endl;
        cout << "------------------------------------" << endl;
        cout << "| Option : ";
        cin >> opt;
        cout << "------------------------------------" << endl;
        if (opt == 1) {
            menuBlogger(B, P, W);
        } else if (opt == 2) {
            menuPlatform(B, P, W);
        } else if (opt == 3) {
            printAll(W, B);
        } else if (opt == 4) {
            return;
        } else {
            cout << "Invalid Option!" << endl;
        }
    }
}

void menuBlogger(ListB &B, ListP &P, ListW &W) {
    int opt, kode;
    while (true) {
        system("cls");
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
            addBlogger(B);
        } else if (opt == 2) {
            printBlogger(B);
        } else if (opt == 3) {
            adrBlogger p;
            cout << "Kode Blogger yang ingin dihapus : "; cin >> kode;
            delBlogger(B, W, P, kode, p);
        } else if (opt == 4) {
            adrBlogger p;
            cout << "Kode Blogger : "; cin >> kode;
            p = findBlogger(B, kode);
            if (p!=NULL) {
                cout << "Blogger " << namaBlogger(p) << " ditemukan!"<< endl;
            } else {
                cout << "Blogger tidak ditemukan!" << endl;
            }
        } else if (opt == 5) {
            return;
        } else {
            cout << "Invalid Option!";
        }
    }
}

void menuPlatform(ListB &B, ListP &P, ListW &W) {
    int opt;
    while (true) {
        system("cls");
        cout << "------------------------------------" << endl;
        cout << "|          Menu Platform           |" << endl;
        cout << "------------------------------------" << endl;
        cout << "| 1. Tambah Platform pada Blogger  |" << endl;
        cout << "| 2. Mencari Platform pada Blogger |" << endl;
        cout << "| 3. Hapus Platform dari Blogger   |" << endl;
        cout << "| 4. Jumlah Platform dari Blogger  |" << endl;
        cout << "| 5. Back                          |" << endl;
        cout << "------------------------------------" << endl;
        cout << "| Option : ";
        cin >> opt;
        cout << "------------------------------------" << endl;
        if (opt == 1) {
           addPlatform(W, B, P);
        } else if (opt == 2) {
            findPlatformOnBlogger(B, P, W);
        } else if (opt == 3) {
            delPlatformOnBlogger(B, W, P);
        } else if (opt == 4) {
            countPlatformOnBlogger(B, P, W);
        } else if (opt == 5) {
            return;
        } else {
            cout << "Invalid Option!" << endl;
        }
    }
}