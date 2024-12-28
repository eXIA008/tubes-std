#include "header.h"
using namespace std;

void createListPlatform(ListP &P) {
    firstPlatform(P) = NULL;
}

adrPlatform createElmPlatform(string nama, string url) {
    adrPlatform p = new platform;
    namaPlatform(p) = nama;
    urlPlatform(p) = url;
    nextPlatform(p) = NULL;
    return p;

}
void addPlatform(ListW &W, ListB B, ListP &P) {
    string op = "Y", nama, url;
    int kode;
    adrBlogger checkB;
    adrPlatform p, checkP, temp;

    cout << "------------------------------------" << endl;
    cout << "|           Add Platform           |" << endl;
    cout << "------------------------------------" << endl;
    while (op == "Y" || op == "y") {
        cout << "Kode Blogger : ";
        cin >> kode;
        checkB = findBlogger(B, kode);
        if (checkB != NULL) {
            cout << "Nama Platform : ";
            cin >> nama;
            cout << "URL Platform : ";
            cin >> url;
            checkP = findPlatform(P, nama);
            if (checkP == NULL) {
                p = createElmPlatform(nama, url);
                if (firstPlatform(P) != NULL) {
                    temp = firstPlatform(P);
                    while (nextPlatform(temp) != NULL) {
                        temp = nextPlatform(temp);
                    }
                    nextPlatform(temp) = p;
                } else {
                    firstPlatform(P) = p;
                }
                addWriting(W, checkB, p);
            } else {
                addWriting(W, checkB, checkP);
            }
        } else {
            cout << "Blogger tidak ada!" << endl;
        }
        cout << "Lanjutkan ? (Y/N)";
        cin >> op;
    }
}
adrPlatform findPlatform(ListP P, string nama){
    adrPlatform p = firstPlatform(P);

    while (p != NULL && namaPlatform(p) != nama) {
        p = nextPlatform(p);
    }
    return p;
}

void delPlatform(ListP &P, adrPlatform p){
    adrPlatform del,temp = firstPlatform(P);
    if (p == firstPlatform(P)) {
        del = firstPlatform(P);
        firstPlatform(P) = nextPlatform(del);
        nextPlatform(del) = NULL;
    } else if (nextPlatform(p) == NULL) {
        while (nextPlatform(nextPlatform(temp)) != NULL) {
            temp = nextPlatform(temp);
        }
        del = nextPlatform(temp);
        nextPlatform(temp) = NULL;
    } else {
        while (nextPlatform(temp) != p) {
            temp = nextPlatform(temp);
        }
        del = nextPlatform(temp);
        nextPlatform(temp) = nextPlatform(del);
        nextPlatform(del) = NULL;
    }
}

void findPlatformOnBlogger(ListB B, ListP P, ListW W) {
    bool found = false;
    int kode;
    string namaPlat;
    cout << "Kode Blogger : ";
    cin >> kode;
    adrBlogger checkB = findBlogger(B, kode);
    if (checkB != NULL) {
        cout << "Nama Platform : ";
        cin >> namaPlat;
        adrPlatform checkP = findPlatform(P, namaPlat);
        adrWriting w = firstWriting(W);
        while (w != NULL) {
            if (infoBlogger(w) == checkB && infoPlatform(w) == checkP) {
                found = true;
            }
            w = nextWriting(w);
        }
        if (found) {
            cout << "Blogger " << namaBlogger(checkB) << " menggunakan Platform " << namaPlat << endl;
        } else {
            cout << "Blogger " << namaBlogger(checkB) << " tidak menggunakan Platform " << namaPlat<< endl;
        }
    } else {
        cout << "Blogger tidak ada!" << endl;
    }
    cout << "Tekan sembarang tombol...";
    getch();
}

void delPlatformOnBlogger(ListB B, ListW &W, ListP &P) {
    bool found = false;
    int kode;
    string namaPlat;
    cout << "Kode Blogger : ";
    cin >> kode;
    adrBlogger checkB = findBlogger(B, kode);
    if (checkB != NULL) {
        cout << "Nama Platform : ";
        cin >> namaPlat;
        adrPlatform checkP = findPlatform(P, namaPlat);
        adrWriting w = firstWriting(W);
        while (w != NULL) {
            if (infoBlogger(w) == checkB && infoPlatform(w) == checkP) {
                if (firstWriting(W) != NULL){
                    delWriting(W, w);
                    found = true;
                }
            }
            w = nextWriting(w);
        }
        if (found) {
            cout << "Platform " << namaPlat << "dihapus dari Blogger " << namaBlogger(checkB) << endl;
        } else {
            cout << "Blogger " << namaBlogger(checkB) << " tidak menggunakan Platform " << namaPlat<< endl;
        }
    } else {
        cout << "Blogger tidak ada!" << endl;
    }
    cout << "Tekan sembarang tombol...";
    getch();
}

void countPlatformOnBlogger(ListB B, ListP P, ListW W) {
    int i = 0, kode;
    string nama;

    cout << "Kode Blogger : ";
    cin >> kode;
    adrBlogger checkB = findBlogger(B, kode);
    if (checkB != NULL) {
        adrWriting w = firstWriting(W);
        while (w != NULL){
            if (infoBlogger(w) == checkB) {
                i++;
            }
            w = nextWriting(w);
        }
         cout << "Blogger " << namaBlogger(checkB) << " memiliki " << i << " platform" << endl;
    } else {
        cout << "Blogger tidak ada!" << endl;
    }
    cout << "Tekan sembarang tombol...";
    getch();
}
