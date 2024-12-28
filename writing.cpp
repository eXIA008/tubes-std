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
    bool checkW = findWriting(W, w);
    if (checkW) {
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

bool findWriting(ListW W, adrWriting w){
    bool b = false;
    adrWriting temp = firstWriting(W);
    while (temp != NULL) {
        if (temp == w){
            b = true;
        } 
        temp = nextWriting(temp);
    }
    
    return b;
}
void printAll(ListW W, ListB B) {
    adrWriting w = firstWriting(W);
    adrBlogger b = firstBlogger(B);
    adrPlatform p;
    cout << "------------------------------------" << endl;
    cout << "|       Blogger dan Platform       |" << endl;
    cout << "------------------------------------" << endl;
    if (firstBlogger(B) != NULL) {
        while (b != NULL) {
            cout << "Kode Blogger : " << kodePenulis(b) << endl;
            cout << "Nama Blogger : " << namaBlogger(b) << endl;
            cout << "Email Blogger : " << emailBlogger(b) << endl;
            cout << "--------------------------------" << endl;
            cout << "Menulis di Platform : " << endl << endl;
            while (w != NULL) {
                if (infoBlogger(w) == b) {
                    p = infoPlatform(w);
                    cout << "Nama Platform : " << namaPlatform(p) << endl;
                    cout << "Url Platform : " << urlPlatform(p) << endl;
                } else {
                    cout << "-" << endl;
                }
                w = nextWriting(w);
            }
            cout << "--------------------------------" << endl;
            b = nextBlogger(b);
        }
    } else {
        cout << "Blogger tidak ada!" << endl;
    }
    cout << "------------------------------------" << endl;
    cout << "Tekan sembarang tombol...";
    getch();
}
// 
void delBlogWriting(ListW &W, ListP &P, adrBlogger b) {
    adrWriting w = firstWriting(W);
    adrWriting checkw = firstWriting(W);
    adrPlatform p;
    while (w != NULL) {
        if (infoBlogger(w) == b) {
            p = infoPlatform(w);
            infoBlogger(w) = NULL;
            infoPlatform(w) = NULL;
            bool found = false;
            while (checkw != NULL) {
                if (infoPlatform(checkw) == p) {
                    found = true;
                }
                checkw = nextWriting(checkw);
            }
            if (!found) {
                delPlatform(P, p);
            }
            delWriting(W, w);
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
