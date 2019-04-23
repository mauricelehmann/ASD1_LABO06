#include "Mouchard.h"

using namespace std;

int main() {

    //Expected output : DC IC(5) CC(5) MC(5) C=(5) M=(5) D(-2) D(-1) D(5) D(5)
    Int * dcInt = new Int();
    Int * icInt = new Int(5);
    Int * ccInt = new Int(*icInt);
    Int * mcInt = new Int(move(*ccInt));
    *dcInt = *icInt;
    *mcInt = move(*icInt);

    delete icInt;
    delete ccInt;
    delete mcInt;
    delete dcInt;

    return 0;
}
