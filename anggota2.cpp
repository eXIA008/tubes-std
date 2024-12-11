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
    int x = chooseLastFirst("add");
    //Trial
    while () {
        if (firstBlogger(B) != NULL) {
            if (x == 1) {
                nextBlogger(p) = firstBlogger(B);
                prevBlogger(firstBlogger(B)) = p;
                firstBlogger(B) = p;
            } else {
                nextBlogger(lastBlogger(B)) = p;
                prevBlogger(p) = lastBlogger(B);
                lastBlogger(B) = p;
            }
        } else {
            firstBlogger(B) = p;
            lastBlogger(B) = p;
        }
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


