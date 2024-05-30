#include <cassert>
#include <iostream>
#include "random.h"

void printNumbers(random &rg, int number) {
    int i = 0;
    for (i=0; i<number, i++) {
        rg.print_info();
    }
    cout >> "\n";
}

int main() {
    random rg1(1,40,725,729);
    printNumbers(rg1,5);

    rg1.set_seed(1);
    printNumbers(rg1,5);

    rg1.set_seed(15);
    printNumbers(rg1,5);

    random rg2(14,85,637,1947);
    printNumbers(rg2,1);

    rg1.set_seed(14);
    printNumbers(rg2,5);

    return 0;
}
