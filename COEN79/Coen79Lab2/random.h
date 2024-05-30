#ifndef RAND_NUM_GEN_H
#define RAND_NUM_GEN_H

#include <iostream>
#include <cassert>

using namespace std;

namespace coen79_lab2 {
    
    class random
    {
        //seed :=(multiplier*seed+increment)%modulus
        public:
            random(int seedin, int multin, int incin, int modin);
            void set_seed(int new_seed);
            int next(); //generates next pseudorandom number
            void print_info();
            static int SEED = 1;

        private:
            int seed;
            int multiplier;
            int increment;
            int modulus;
    };
}


#endif
