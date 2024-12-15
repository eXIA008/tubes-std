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

void addBlogger(List &B) {
    string op = "Y", nama, email;
    int kode;
    adrBlogger b, check;

    cout << "------------------------------------" << endl;
    cout << "|            Add Blogger           |" << endl;
    cout << "------------------------------------" << endl;
    while (op == "Y" || op == "y") {
        cout << "Kode Blogger : ";
        cin >> kode;
        cout << "Nama Blogger : ";
        cin >> nama;
        cout << "Email Blogger : ";
        cin >> email;
        b = createElmBlogger(nama, email, kode);
        check = findBlogger(B, kode);
        if (check == NULL) {
            if (chooseLastFirst() == 1) {
              insertLastBlogger(B, b);
            } else {
                insertFirstBlogger(B, b);
            }
        } else {
            cout << "------------------------------------" << endl;
            cout << "|     Blogger Already Existed!     |" << endl;
            cout << "------------------------------------" << endl;
        }
        cout << "Lanjutkan ? (Y/N)";
        cin >> op;
    }
}

void insertLastBlogger(List &B, adrBlogger p) {
    if (firstBlogger(B) != NULL) {
        nextBlogger(lastBlogger(B)) = p;
        prevBlogger(p) = lastBlogger(B);
        lastBlogger(B) = p;
    } else {
        firstBlogger(B) = p;
        lastBlogger(B) = p;
    }
}

void insertFirstBlogger(List &B, adrBlogger p) {
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
    int x = chooseLastFirst();
    if (firstBlogger(B) != NULL) {
        if (firstBlogger(B) == lastBlogger(B)) {
            p = lastBlogger(B);
            lastBlogger(B) = NULL;
            firstBlogger(B) = NULL;
        } else {
            if (x == 2) {
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

void printBlogger(List W) {
    /* Print Blogger berdasarkan List Relasi
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
    */
    adrBlogger b = firstBlogger(W); //Kalo proc ini cuma buat blogger rubah W jadi B
    if (firstBlogger(W) != NULL) {
        cout << "------------------------------------" << endl;
        while (b != NULL) {
            cout << "Kode Blogger : " << kodePenulis(b) << endl;
            cout << "Nama Blogger : " << namaBlogger(b) << endl;
            cout << "Email Blogger : " << emailBlogger(b) << endl;
            b = nextBlogger(b);
        }
        cout << "------------------------------------" << endl;
    } else {
        cout << "------------------------------------" << endl;
        cout << "|       There is no Blogger!       |" << endl;
        cout << "------------------------------------" << endl;
    }
}

