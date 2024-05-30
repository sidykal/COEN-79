#include <cassert>
#include <iostream>
#include "random.h"

using namespace std;
using namespace coen79_lab2;
namespace coen79_lab2
{
    random :: random(int seedin, int multin, int incin, int modin){
        seed = seedin;
        multiplier = multin;
        increment = incin;
        modulus = modin;
    }
    void random :: set_seed(int new_seed){
        seed = new_seed;
    }
    int random :: next(){ //generates next pseudorandom number
        seed = (multiplier * seed + increment) % modulus;
	return seed;
    }
    void random :: print_info(){
        cout << "Seed: " << seed << endl << "Multiplier: " << multiplier << endl << "Increment: " << increment << endl << "Modulus: " << modulus << "Next: " << next() << endl;
    }
}
