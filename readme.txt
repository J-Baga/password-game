Password Guesser and Generator
-------------------------------
Team Members:

Steven Kha
Jerald Gopez
Jeric Baga

Threading was implemented. The compilation command is as follows:
g++ -pthread -std=c++11 main.cpp passGen.cpp passGuesser.cpp -o passwordgame

Run Commands:
./passwordgame sample_words.txt

Included files:
main.cpp
passGen.cpp
passGen.hpp
passGuesser.cpp
passGuesser.hpp
readme.txt
sample_words.txt

Description:
Given a text file of words, generate a random password of k unique words, where k is a value between 1 and 5, determined by the user. Two different methods will race to see which one generates that random k-word password first:

1) Random Password Generator - Continusouly generates a random k-word password based.

2) K-Word Password Permutation Generator - Generates all the possible permutations of k-word passwords based on all the words provided in the text file.

This race is done using multithreading. During the race, the user will be updated with the number of passwords each method has generated. When a method generates the correct password, the race ends and the user will be notified of how many password it took for the winning method to generate the correct one.




