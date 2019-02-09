//
// Created by Sean Kelker on 1/18/19.
//

#include "random.h"

namespace coen79_lab2 {

    rand_gen::rand_gen(int seed, int multiplier, int increment, int modulus){

        this->seed = seed;
        this->multiplier = multiplier;
        this->increment = increment;
        this->modulus = modulus;

    }

    void rand_gen::set_seed(int new_seed) {
        seed = new_seed;
    }

    int rand_gen::next() {

        int r = ((multiplier * seed) + increment ) % modulus;
        seed = r;
        return r;

    }

    void rand_gen::print_info() {

        cout << "seed: " << seed << endl;
        cout << "multiplier: "<< multiplier << endl;
        cout << "increment: "<< increment << endl;
        cout << "modulus: "<< modulus << endl;

    }


}



