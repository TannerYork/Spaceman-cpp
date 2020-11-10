#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <tuple>
#include "utils.h"
using namespace std;

int main() {

    size_t sizeOfWordsList;
    string* wordsList;
    tie(sizeOfWordsList, wordsList)= loadWordsList();
    string secretWord = loadWord(sizeOfWordsList, wordsList);

    cout << "The secret word is: " << secretWord << endl;

    return 0;
}

int getWordsCount() {
    fstream file;
    string word, filename;

    filename = "words.txt";
    file.open(filename.c_str());

    int count = 0;
    while (file >> word) count += 1;
    return count;
}

tuple<size_t, string*> loadWordsList() {
    /* Loads a list of words into memory from the words.txt file */
    fstream file;
    string word, filename;

    filename = "words.txt";
    file.open(filename.c_str());

    static string words[55909];
    int i = 0;
    while (file >> word) {
        words[i] = word;
        i ++;
    }

    return make_tuple(sizeof(words), words);
}

string loadWord(size_t n, string* wordsList) {
    /* Chooses a random word from the wordslist to be the games secret word */
    srand(time(NULL)); //initialize the random seed
    int randIndex = rand() % n/sizeof(string);
    return wordsList[randIndex];
}

bool isWordGuessed(string secretWord, size_t n, char* lettersGuessed) {
    /* Checks if the current word is equal to the games secret word */
    for (int i = 0; i < n; i++) {
        if (secretWord.at(i) != lettersGuessed[i]) return false;
    }
    return true;
}

string getGuessedWord(string secretWord, size_t n, string* lettersGuessed) {
    /* Gets the current word string from the current guesses list*/
    return "pass";
}

bool isGuessInWord(string guess, string secretWord) {
    return false;
}

bool hasBeenGuessed(string guess, size_t n, string* lettersGuessed) {
    return false;
}

string changeWord(string currentWord, string secretWord, size_t n, string* wordsList) {
    return "pass";
}

void startSpaceman(string secretWord, size_t n, string* spacemanWordsList) {

}