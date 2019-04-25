
#include "Mouchard.h"
#include <iostream>
using namespace std;

int main() {

    Int* p = (Int*) ::operator new(4 * sizeof(Int));

    Int* dcInt = new(p) Int();
    Int* icInt = new(p + 1) Int(5);
    Int* ccInt = new(p + 2) Int(*icInt);
    Int* mcInt = new(p + 3) Int(move(*icInt));
    *dcInt = *ccInt ;
    *mcInt = move(*dcInt);

    cout << endl;
    cout << "size of Int : " << sizeof(Int) << endl;
    for (size_t i = 0; i < 4; i++) {
        cout << p + i<< " : " << *(p + i) << endl;
        //delete(p+i) ;
    }
    ::operator delete(p);
}
