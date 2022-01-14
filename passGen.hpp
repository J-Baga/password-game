#ifndef _PASSGEN_
#define _PASSGEN_

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <list>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

class passGen {
    public:
        passGen(list<string> tokenList);
        string getRandomPassword(int numWords);
        void setIterationLength(int numWords);
        string next();
        bool hasNext();
    private:
        list<string> wordList;
        unsigned long long int itrLen;
        unsigned long long int numPerm;
        unsigned long long int currPerm = 0;
        vector<string> sequentialPasswords;
        void getAllPasswords(int numWords);
};  
#endif