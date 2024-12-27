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

void addPlatform(ListW &W, ListB B, ListP &P, adrPlatform p) {
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
            p = createElmPlatform(nama, url);
            checkP = findPlatform(P, nama);
            if (checkP == NULL) {
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
                addWriting(W, checkB, p);
            }
        } else {
            cout << "Blogger tidak ada!";
        }
        
        cout << "Lanjutkan ? (Y/N)";
        cin >> op;
    }
}
adrPlatform findPlatform(ListP P, string nama){
    adrBlogger p = firstBlogger(P);

    while (p != NULL && urlPlatform(p) != nama) {
        p = nextBlogger(p);
    }
    return p;
}

void delPlatform(ListP P, adrPlatform &b){
    adrPlatform check = findBlogger(B, IDblogger);
    if (check != NULL) {
        delBlogWriting(W,)
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
            adrPlatform p = firstPlatform(P);
            while (nextBlogger(p) != NULL) {
                b = nextBlogger(b);
            }
            nextBlogger(b) = nextBlogger(p);
            prevBlogger(nextBlogger(p)) = b;
            prevBlogger(p) = NULL;
            nextBlogger(p) = NULL;
        }
        adrWriting rel = findWriting(W, check);
        if (rel != NULL) {
            infoBlogger(rel) = NULL;
        }
    } else {
        cout << "Blogger tidak ada!";
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
        cout << "Blogger " << namaBlogger(checkB) << " menggunakan Platform " << namaPlat;
        } else {
        cout << "Blogger " << namaBlogger(checkB) << " tidak menggunakan Platform " << namaPlat;
        }
    } else {
        cout << "Blogger tidak ada!";
    }
}

int countPlatformOnBlogger(ListB B, ListP P, ListW W) {
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
    } else {
        cout << "Blogger tidak ada!";
    }
    return i;
}