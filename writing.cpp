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
    if (firstWriting(W) != NULL) {
        temp = firstWriting(W);
        while (nextWriting(temp) != NULL) {
            temp = nextWriting(temp);
        }
        nextWriting(temp) = w;
    } else {
        firstWriting(W) = w;
     }
}

void printAll(ListW W, ListB B) {
    adrWriting w = firstWriting(W);
    adrBlogger b = firstBlogger(B);
    adrPlatform p;
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
                    cout << "--------------------------------" << endl;
                } else {
                    cout << "Belum menggunakan Platform manapun!";
                }
                w = nextWriting(w);
            }
            b = nextBlogger(b);
        }
    } else {
        cout << "Blogger tidak ada!" << endl;
    }
    cout << "------------------------------------" << endl;
}

void delBlogWriting(ListW &W, ListP &P, adrBlogger b) {
    adrWriting w = firstWriting(W);
    adrWriting checkw = firstWriting(W);
    adrPlatform p;
    while (w != NULL) {
        if (infoBlogger(w) == b) {
            infoBlogger(w) = NULL;
            p = infoPlatform(w);
            bool found = false;
            while (checkw != NULL) {
                if (infoPlatform(checkw) == p) {
                    found = true;
                }
                checkw = nextWriting(checkw);
            }
            infoPlatform(w) = NULL;
            if (!found) {
                delPlatform(P, p);
            }
        }
        w = nextWriting(w);
    }
}