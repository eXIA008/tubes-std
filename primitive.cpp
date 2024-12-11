#include "blogger.h"

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
void addBlogger(List &B, adrBlogger p);
void createListPlatform(List &P){
    firstPlatform(P) = NULL;
}

adrPlatform createElmPlatform(string nama, string url){
    adrPlatform p = new platform;
    namaPlatform(p) = nama;
    urlPlatform(p) = url;
    nextPlatform(p) = NULL; 
    return p;
}
void addPlatform(List &P, adrPlatform p);
void createListWriting(List &W){
    firstWriting(W) = NULL;
}

adrWriting createElmWriting() {
    adrWriting w = new writing;
    bloggerID(w) = NULL;
    platformUsed(w) = NULL;
    nextWriting(w) = NULL;
    return w;
}
void addWriting (List &B, adrBlogger b, adrPlatform p);
void print(List B, List P, List W);
adrBlogger findBlogger(List B, int IDblogger);
void findPlatform(List B, List P, int IDblogger);
void countPlatform(List B, List P, int IDblogger);
void deleteBlogger(List B, List W, adrBlogger &p);
void deletePlatform(List P, List W, adrPlatform &p, int IDblogger);
void menu() {
    /*{IS : terdefinisi }*/
    
}