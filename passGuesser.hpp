#ifndef _PASSGUESS_
#define _PASSGUESS_

#include <windows.h>
#include <pthread.h>
#include <atomic>
#include <math.h>
#include "passGen.hpp"
 
class passGuess {
    public:
        void driver(list<string> uniqueTokens, int length);
    private:
        int numPerm;
};
#endif
