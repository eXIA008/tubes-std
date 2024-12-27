#include "header.h"
using namespace std;

void createListBlogger(ListB &B) {
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

void addBlogger(ListB &B) {
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
            cout << "Blogger sudah ada!" << endl;
        }

        cout << "Lanjutkan ? (Y/N)";
        cin >> op;
    }
}

void insertLastBlogger(ListB &B, adrBlogger p) {
    if (firstBlogger(B) != NULL) {
        nextBlogger(lastBlogger(B)) = p;
        prevBlogger(p) = lastBlogger(B);
        lastBlogger(B) = p;
    } else {
        firstBlogger(B) = p;
        lastBlogger(B) = p;
    }
}
void insertFirstBlogger(ListB &B, adrBlogger p) {
    if (firstBlogger(B) != NULL) {
        nextBlogger(p) = firstBlogger(B);
        prevBlogger(firstBlogger(B)) = p;
        firstBlogger(B) = p;
    } else {
        firstBlogger(B) = p;
        lastBlogger(B) = p;
    }
}
adrBlogger findBlogger(ListB B, int IDblogger) {
    adrBlogger b = firstBlogger(B);
    while (b != NULL && kodePenulis(b) != IDblogger) {
        b = nextBlogger(b);
    }
    return b;
}

void delBlogger(ListB &B, ListW W, ListP &P, int IDblogger, adrBlogger &p) {
    adrBlogger check = findBlogger(B, IDblogger);
    if (check != NULL) {
        delBlogWriting(W, P, check);
        p = check;
        if (check == firstBlogger(B)) {
            prevBlogger(firstBlogger(B)) = NULL;
            firstBlogger(B) = nextBlogger(p);
            nextBlogger(p) = NULL;
        } else if (check == lastBlogger(B)) {
            nextBlogger(prevBlogger(p)) = NULL;
            lastBlogger(B) = prevBlogger(p);
            prevBlogger(p) = NULL; 
        } else {
            adrBlogger b = firstBlogger(B);
            while (nextBlogger(b) != check) {
                b = nextBlogger(b);
            }
            nextBlogger(b) = nextBlogger(p);
            prevBlogger(nextBlogger(p)) = b;
            prevBlogger(p) = NULL;
            nextBlogger(p) = NULL;
        }
    } else {
        cout << "Blogger tidak ada!";
    }
}

void printBlogger(ListB B) {
    adrBlogger b = firstBlogger(B); 
    if (firstBlogger(B) != NULL) {
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



