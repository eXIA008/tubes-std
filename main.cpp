#include <iostream>
#include "header.h"
using namespace std;

int main(){
    ListB B;
    ListP P;
    ListW W;
    createListBlogger(B);
    createListPlatform(P);
    createListWriting(W);
    mainMenu(B, P, W);
    cout << "SAYONARA!!! ";
    return 0;
}
