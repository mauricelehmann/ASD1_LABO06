#include "Mouchard.h"
#include <iostream>
using namespace std;

int main() {

    //Expected output : DC IC(5) CC(5) MC(5) C=(5) M=(5) D(-2) D(-1) D(5) D(5)
    Int a;
    Int b(5);
    Int c = b;
    Int d(move(c));
    a = b;
    a = move(d);

    return 0;
}
