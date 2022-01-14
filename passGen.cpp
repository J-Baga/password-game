#include "passGen.hpp"

passGen::passGen(list<string> tokenList) {
    wordList = tokenList;
}

/**
* Creates a random password consisting of n words, where n is 
* the number of unique words. 
* @param numWords: The number of words in the password  
* @return The randomly generated password. 
*/ 
string passGen::getRandomPassword(int numWords){
    string password;
    vector<int> randomInts;
    for(int i = 0; i < numWords;){                                          //Acquire numWords unique integers.
        int randomInt = rand() % wordList.size();
        if(!count(randomInts.begin(), randomInts.end(), randomInt)){   
            randomInts.push_back(randomInt);
            i++;
        }
    }
    while(randomInts.size() != 0){                                          //Match integers to positions in list.
        int indexCounter = 0;
        for(string word : wordList){
            if(indexCounter == randomInts[0]){
                if(password.empty()){
                    password = word;
                }
                else{
                    password = password + " " + word;
                }
                randomInts.erase(randomInts.begin());
            }
            indexCounter++;
        }
    }
    return password;
}

/**
* Sets the private field containing the number of words to be in each 
* iteration of acquiring the permutations of passwords. Every time this
* function is called, the iterations of passwords will start from the 
* beginning, or the first possible password.
* @param numWords: The number of words in the passwords.
*/  
void passGen::setIterationLength(int numWords){
    itrLen = numWords;
    currPerm = 0;
}

/**
* Acquires a vector of every possible password in permutation order.
* While a password exists the next time the function is called, it will
* return a unique password depending on the permutation number that updates 
* every time the function is called. 
* @return currPassword: The current permutation of a n-word unique password.
*/ 
string passGen::next(){
    if(currPerm == 0){
        getAllPasswords(itrLen);
        numPerm = sequentialPasswords.size();
        printf("Given the input file tokens and specified length, the program can build %d different password combinations.\n\n", numPerm);
    }

    if(hasNext()){
        string currPassword = sequentialPasswords[currPerm];
        currPerm++;
        return currPassword;
    }
    else{
        return NULL;
    }
}

/**
* Checks whether all the possible password permutations have been accessed 
* and returned by the next() function.
* @return True: There exist a password after the current password permutation.
*         False: There does not exist a password after the current password permutation.
* 
*/ 
bool passGen::hasNext(){
    if(currPerm <= numPerm){
        return true;
    }
    else{
        return false;
    }
}

/**
* Acquires and stores every possible n-word permutation (n = [1,5]) password from
* a list of unique words. This is executed by building up unique permutations from
* previous unique n-word permutations up until the desired number of words for the
* password is reached.
* @param numWords: The number of words to be in a single password permutation.   
*/ 
void passGen::getAllPasswords(int numWords){
    vector<string> permutations;
    for(string word : wordList){                            // Creation of single-word permutation
        permutations.push_back(word);                       // vector.
    }

    if(numWords == 1){
        sequentialPasswords = permutations;
        return;
    }

    vector<string> permutationsCopy;                                // Copy of permutations to keep track of 
                                                                    // previous iteration's permutations for
                                                                    // next iteration.

    for(int i = 1; i < numWords; i++){                              // "Recursive" creation of permutations with
                for(int j = 0; j < permutations.size(); j++){       // incrementing number of words in them
                    for(std::string uniqueWord : wordList){         // every increasing loop iteration.
                        bool isUnique = true;
                        if(permutations[j].find(uniqueWord) != std::string::npos){ // Word is in password
                            std::istringstream password(permutations[j]);          // check if word is unique or not
                            std::string token;                                     // (ex. "cheese" vs "cheeseburger")
                            while(password >> token){
                                if(uniqueWord == token){
                                    isUnique = false;
                                }
                            }
                        }
                        if(isUnique){
                            permutationsCopy.push_back((permutations[j] + " " + uniqueWord));
                        }
                        else{
                            continue;
                        }
                    }
                }
                permutations = permutationsCopy;
                permutationsCopy.clear();
            }
    sort(permutations.begin(), permutations.end());
    sequentialPasswords = permutations;
}


