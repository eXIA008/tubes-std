#include "blogger.h"
#include "menu.h"
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
    //int x = chooseLastFirst();
    //Trial
    while () {
        if (firstBlogger(B) != NULL) {
            if (x == 1) {
                nextBlogger(p) = firstBlogger(B);
                firstBlogger(B) = p;
            } else {
                adrBlogger h = firstBlogger(B);
                while (nextBlogger(h) != NULL) {
                    h = nextBlogger(h);
                }
                nextBlogger(h) = p;
            }
        } else {
            firstBlogger(B) = p;
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
    //int x = chooseLastFirst();
    //Trial
    while () {
        if (firstBlogger(B) != NULL) {
            if (x == 1) {
                p = firstBlogger(B);
                firstBlogger(B) = nextBlogger(p);
                nextBlogger(p) = NULL;
            }
        }
    }
}
