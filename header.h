#ifndef blogger_H
#define blogger_H
#include <string>
#include <iostream>
#define namaBlogger(B) B->namaBlogger
#define emailBlogger(B) B->emailBlogger
#define kodePenulis(B) B->kodePenulis
#define nextBlogger(B) B->nextBlogger
#define prevBlogger(B) B->prevBlogger

#define namaPlatform(P) P->namaPlatform
#define urlPlatform(P) P->urlPlatform
#define nextPlatform(P) P->nextPlatform

#define judulTulisan(W) W->judulTulisan
#define infoBlogger(W) W->infoBlogger
#define infoPlatform(W) W->infoPlatform
#define nextWriting(W) W->nextWriting

#define firstBlogger(B) B.firstBlogger
#define lastBlogger(B) B.lastBlogger
#define firstPlatform(P) P.firstPlatform
#define firstWriting(W) W.firstWriting

using namespace std;

typedef blogger *adrBlogger;
typedef platform *adrPlatform;
typedef writing *adrWriting;

struct blogger {
    string namaBlogger, emailBlogger;
    int kodePenulis;
    adrBlogger nextBlogger, prevBlogger;
};

struct platform {
    string namaPlatform, urlPlatform;
    int jumlahPengguna;
    adrPlatform nextPlatform;
};

struct writing {
    string judulTulisan;
    adrBlogger infoBlogger;
    adrPlatform infoPlatform;
    adrWriting nextWriting;
};

struct List {
    adrBlogger firstBlogger;
    adrBlogger lastBlogger;
    adrPlatform firstPlatform;
    adrWriting firstWriting;
};

/* Blogger */
void createListBlogger(List &B);
adrBlogger createElmBlogger(string nama, string email, int kode);
void addBlogger(List &B, adrBlogger p);
void insertFirstBlogger(List &B, adrBlogger p);
void insertLastBlogger(List &B, adrBlogger p);
adrBlogger findBlogger(List B, int IDblogger);
void deleteBlogger(List B, List W, int IDblogger, adrBlogger &p);
void printBlogger(List B);

/* Platform*/
void createListPlatform(List &P);
adrPlatform createElmPlatform(string nama, string url);
void addPlatform(List &P, adrPlatform p);
void findPlatform(List B, List P, int IDblogger);
void countPlatform(List B, List P, int IDblogger);
void deletePlatform(List P, List W, adrPlatform &p, int IDblogger);

/* Writing*/
void createListWriting(List &W);
adrWriting createElmWriting();
void addWriting (List &B, adrBlogger b, adrPlatform p);

/* Menu (Kalo Pake)*/
void printAll(List B, List P, List W);
void menu();
int chooseLastFirst();

#endif