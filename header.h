#ifndef blogger_H
#define blogger_H
#include <string>
#include <iostream>
#include <conio.h>
#define namaBlogger(B) B->namaBlogger
#define emailBlogger(B) B->emailBlogger
#define kodePenulis(B) B->kodePenulis
#define nextBlogger(B) B->nextBlogger
#define prevBlogger(B) B->prevBlogger

#define namaPlatform(P) P->namaPlatform
#define urlPlatform(P) P->urlPlatform
#define nextPlatform(P) P->nextPlatform

#define infoBlogger(W) W->infoBlogger
#define infoPlatform(W) W->infoPlatform
#define nextWriting(W) W->nextWriting

#define firstBlogger(B) B.firstBlogger
#define lastBlogger(B) B.lastBlogger
#define firstPlatform(P) P.firstPlatform
#define firstWriting(W) W.firstWriting

using namespace std;

typedef struct blogger *adrBlogger;
typedef struct platform *adrPlatform;
typedef struct writing *adrWriting;

struct blogger {
    string namaBlogger, emailBlogger;
    int kodePenulis;
    adrBlogger nextBlogger, prevBlogger;
};

struct platform {
    string namaPlatform, urlPlatform;
    adrPlatform nextPlatform;
};

struct writing {
    adrBlogger infoBlogger;
    adrPlatform infoPlatform;
    adrWriting nextWriting;
};

struct ListB {
    adrBlogger firstBlogger;
    adrBlogger lastBlogger;
};
struct ListP {
    adrPlatform firstPlatform;
};

struct ListW {
    adrWriting firstWriting;
};

/* Blogger */
void createListBlogger(ListB &B);
adrBlogger createElmBlogger(string nama, string email, int kode);
void addBlogger(ListB &B);
void insertFirstBlogger(ListB &B, adrBlogger p);
void insertLastBlogger(ListB &B, adrBlogger p);
adrBlogger findBlogger(ListB B, int IDblogger);
void delBlogger(ListB &B, ListW &W, ListP &P, int IDblogger, adrBlogger &p);
void delBlogWriting(ListW &W, ListP &P, adrBlogger b);
void printBlogger(ListB B);

/* Platform */
void createListPlatform(ListP &P);
adrPlatform createElmPlatform(string nama, string url);
void addPlatform(ListW &W, ListB B, ListP &P);
adrPlatform findPlatform(ListP P, string nama);
void findPlatformOnBlogger(ListB B, ListP P, ListW W);
void delPlatform(ListP &P, adrPlatform p);
void delPlatformOnBlogger(ListB B, ListW &W, ListP &P);
void countPlatformOnBlogger(ListB B, ListP P, ListW W);

/* Writing */
void createListWriting(ListW &W);
adrWriting createElmWriting(adrBlogger b, adrPlatform p);
void addWriting(ListW &W, adrBlogger b, adrPlatform p);
bool findWriting(ListW W, adrWriting w);
void delWriting(ListW &W, adrWriting w);
bool findWriting(ListW W, adrBlogger b, adrPlatform p);
void printAll(ListW W, ListB B);

/* Menu (Kalo Pake) */
void mainMenu(ListB B, ListP P, ListW W);
void menuBlogger(ListB &B, ListP &P, ListW &W);
void menuPlatform(ListB &B, ListP &P, ListW &W);
int chooseLastFirst();

#endif
