#include <fstream>
#include <sstream>
#include "passGuesser.hpp"

// Compile: g++ -pthread -std=c++11 main.cpp passGen.cpp passGuesser.cpp -o passwordgame

/**
* Parses a valid text file and returns a list of its unique words.  
* @param argc - The number of command line arguments.
* @param argv - The command line arguments in an array.
* @return A list of unique tokens. 
*/ 
list<string> parse_file(int argc, char**argv){
    list<string> tokens;

    if(argc != 2){
        cout << "Error: Insufficient or Excessive arguments detected." << endl;
        cout << "Please restart the program, loading it such as the given example below:" << endl;
        cout << "passwordgame.exe text.txt" << endl;
        exit(0);
    }

    ifstream text(argv[1]);

    if(!text){
        cout << "Error: Unable to locate the specified file." << endl;
        cout << "Please load the program again, making sure you provide a valid file location." << endl;
        cout << "Example: passwordgame.exe text.txt" << endl;
        exit(0);
    }
    
    string token;
    while (text >> token){
        
        for(int i = 0; i < token.length(); i++){
            if(ispunct(token[i])){
                token.erase(i, 1);
            }
            token[i] = tolower(token[i]);
        }
        tokens.push_back(token);
        tokens.unique();
        tokens.sort();
    }

    tokens.unique();
    tokens.sort();
    
    return tokens;
}

int main(int argc, char** argv){
    srand(time(NULL));                                  // Used to ensure unique random passwords every execution.
    list<string> uniqueTokens = parse_file(argc, argv);
    int length;
    passGuess guesser;
    guesser.driver(uniqueTokens, length);    
    return 0;
}
