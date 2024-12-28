#include "header.h"
using namespace std;

void createListWriting(ListW &W) {
    firstWriting(W) = NULL;
}

adrWriting createElmWriting(adrBlogger b, adrPlatform p){
    adrWriting w = new writing;
    infoBlogger(w) = b;
    infoPlatform(w) = p;
    nextWriting(w) = NULL;
    return w;
}

void addWriting(ListW &W, adrBlogger b, adrPlatform p){
    adrWriting w = createElmWriting(b, p), temp;
    bool checkW = findWriting(W, b, p);
    if (checkW == false) {
        if (firstWriting(W) != NULL) {
            temp = firstWriting(W);
            while (nextWriting(temp) != NULL) {
                temp = nextWriting(temp);
            }
            nextWriting(temp) = w;
        } else {
            firstWriting(W) = w;
        }
    } else {
        cout << "Platform " << namaPlatform(p) <<  " sudah digunakan oleh Blogger " << namaBlogger(b) << endl;
    }
}

bool findWriting(ListW W, adrBlogger b, adrPlatform p){
    bool s = false;
    adrWriting temp = firstWriting(W);
    while (temp != NULL) {
        if (infoBlogger(temp) == b && infoPlatform(temp) == p){
            s = true;
        }
        temp = nextWriting(temp);
    }

    return s;
}
void printAll(ListW W, ListB B) {
    adrBlogger b = firstBlogger(B);
    adrPlatform p;
    cout << "------------------------------------" << endl;
    cout << "|       Blogger dan Platform       |" << endl;
    cout << "------------------------------------" << endl;
    if (firstBlogger(B) != NULL) {
        while (b != NULL) {
            cout << "Kode Blogger : " << kodePenulis(b) << endl;
            cout << "Nama Blogger : " << namaBlogger(b) << endl;
            cout << "Email Blogger : " << emailBlogger(b) << endl << endl;
            cout << "Menulis di Platform : " << endl;
            adrWriting w = firstWriting(W);
            while (w != NULL) {
                if (infoBlogger(w) == b) {
                    p = infoPlatform(w);
                    cout << "Nama Platform : " << namaPlatform(p) << endl;
                    cout << "Url Platform : " << urlPlatform(p) << endl;
                    cout << "------------------------------------" << endl;
                }
                w = nextWriting(w);
            }
            cout << "------------------------------------" << endl;
            b = nextBlogger(b);
        }
    } else {
        cout << "Blogger tidak ada!" << endl;
    }
    cout << "Tekan sembarang tombol...";
    getch();
}

void delBlogWriting(ListW &W, ListP &P, adrBlogger b) {
    adrWriting w = firstWriting(W);
    adrPlatform p;
    while (w != NULL) {
        if (infoBlogger(w) == b) {
            p = infoPlatform(w);
            delWriting(W, w);
            bool found = false;
            adrWriting checkw = firstWriting(W);
            while (checkw != NULL) {
                if (infoPlatform(checkw) == p) {
                    found = true;
                }
                checkw = nextWriting(checkw);
            }
            if (found == false) {
                delPlatform(P, p);
            }
        }
        w = nextWriting(w);
    }
}

void delWriting(ListW &W, adrWriting w) {
    adrWriting del,temp = firstWriting(W);
    if (w == firstWriting(W)) {
        del = firstWriting(W);
        firstWriting(W) = nextWriting(del);
        nextWriting(del) = NULL;
    } else if (nextWriting(w) == NULL) {
        while (nextWriting(nextWriting(temp)) != NULL) {
            temp = nextWriting(temp);
        }
        del = nextWriting(temp);
        nextWriting(temp) = NULL;
    } else {
        while (nextWriting(temp) != w) {
            temp = nextWriting(temp);
        }
        del = nextWriting(temp);
        nextWriting(temp) = nextWriting(del);
        nextWriting(del) = NULL;
    }
}
