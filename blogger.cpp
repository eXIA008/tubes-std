#include "header.h"
using namespace std;

void createListBlogger(List &B) {
    firstBlogger(B) = NULL;
    lastBlogger(B) = NULL;
}

adrBlogger createElmBlogger(string nama, string email, int kode) {
    adrBlogger b = new blogger;
    namaBlogger(b) = nama;
    emailBlogger(b) = email;
    kodePenulis(b) = kode;
    nextBlogger(b) = NULL;
    prevBlogger(b) = NULL;

    return b;
}

void addBlogger(List &B, adrBlogger p) {
    string op;
    while (op != "N" || op != "n") {
        //disini minta input aja dari user nigger
        cout << "Lanjutkan ? (Y/N) : ";
        cin >> op;
    }  
}

void insertFirstBlogger(List &B, adrBlogger p) {
    if (firstBlogger(B) != NULL) {
        nextBlogger(lastBlogger(B)) = p;
        prevBlogger(p) = lastBlogger(B);
        lastBlogger(B) = p;
    } else {
        firstBlogger(B) = p;
        lastBlogger(B) = p;
    }
}

void insertLastBlogger(List &B, adrBlogger p) {
    if (firstBlogger(B) != NULL) {
        nextBlogger(p) = firstBlogger(B);
        prevBlogger(firstBlogger(B)) = p;
        firstBlogger(B) = p;
    } else {
        firstBlogger(B) = p;
        lastBlogger(B) = p;
    }
}

adrBlogger findBlogger(List B, int IDblogger) {
    adrBlogger b = firstBlogger(B);
    while (b != NULL && kodePenulis(b) != IDblogger) {
        b = nextBlogger(b);
    }
    return b;
}

void deleteBlogger(List B, List W, int IDblogger, adrBlogger &p) {
    int x = chooseLastFirst("del");
    //Trial
    while () {
        if (firstBlogger(B) != NULL) {
            if (firstBlogger(B) == lastBlogger(B)) {
                p = lastBlogger(B);
                lastBlogger(B) = NULL;
                firstBlogger(B) = NULL;
            } else {
                if (x == 1) {
                    p = firstBlogger(B);
                    firstBlogger(B) = nextBlogger(p);
                    prevBlogger(nextBlogger(p)) = NULL;
                    nextBlogger(p) = NULL;
                } else {
                    p = lastBlogger(B);
                    lastBlogger(B) = prevBlogger(p);
                    nextBlogger(prevBlogger(p)) = NULL;
                    prevBlogger(p) = NULL;
                }
            }
        } else  {
            p = NULL;
        }
    }
}

void printBlogger(List W) {
    adrWriting  w = firstWriting(W);
    cout << "------------------------------------" << endl;
    cout << "|          Daftar Blogger          |" << endl;
    cout << "------------------------------------" << endl;
    if (firstWriting(W) != NULL) {
        cout << "------------------------------------" << endl;
        while (w != NULL) {
            cout << "Kode Blogger : " << kodePenulis(infoBlogger(w)) << endl;
            cout << "Nama Blogger : " << namaBlogger(infoBlogger(w)) << endl;
            cout << "Email Blogger : " << emailBlogger(infoBlogger(w)) << endl;
            w = nextWriting(w);
        }
        cout << "------------------------------------" << endl;
    } else {
        cout << "------------------------------------" << endl;
        cout << "|       There is no Blogger!       |" << endl;
        cout << "------------------------------------" << endl;
    }
}

