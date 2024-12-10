#ifndef blogger_H
#define blogger_H
#include <string>
#include <iostream>
#define namaBlogger(B) B->namaBlogger
#define emailBlogger(B) B->emailBlogger
#define kodeBlogger(B) B->kodeBlogger
#define nextBlogger(B) B->nextBlogger
#define prevBlogger(B) B->prevBlogger
#define namaPlatform(P) P->namaPlatform
#define urlPlatform(P) P->urlPlatform
#define nextPlatform(P) P->nextPlatform
#define kodePenulis(W) W->bloggerID
#define platformUsed(W) W->platformUsed
#define nextWriting(W) W->nextWriting
#define firstBlogger(B) B.firstBlogger
#define lastBlogger(B) B.lastBlogger
#define firstPlatform(P) P.firstPlatform
#define firstWriting(W) W.firstWriting

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
    adrPlatform nextPlatform;
};

struct writing {
    adrBlogger bloggerID;
    adrPlatform platformUsed;
    adrWriting nextWriting;
};

struct List {
    adrBlogger firstBlogger;
    adrBlogger lastBlogger;
    adrPlatform firstPlatform;
    adrWriting firstWriting;
};


void createListBlogger(List &B);
adrBlogger createElmBlogger(string nama, string email, int kode);
void addBlogger(List &B, adrBlogger p);
void createListPlatform(List &P);
adrPlatform createElmPlatform(string nama, string url);
void addPlatform(List &P, adrPlatform p);
void createListWriting(List &W);
adrWriting createElmWriting();
void addWriting (List &B, adrBlogger b, adrPlatform p);
void print(List B, List P, List W);
adrBlogger findBlogger(List B, int IDblogger);
void findPlatform(List B, List P, int IDblogger);
void countPlatform(List B, List P, int IDblogger);
void deleteBlogger(List B, List W, int IDblogger, adrBlogger &p);
void deletePlatform(List P, List W, 
adrPlatform &p, int IDblogger);
void menu();

#endif