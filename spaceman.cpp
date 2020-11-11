#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <tuple>
#include <ctype.h>
#include "utils.h"
using namespace std;

int main() {

    int sizeOfWordsList;
    string* wordsList;

    tie(sizeOfWordsList, wordsList)= loadWordsList();
    string secretWord = loadWord(wordsList, sizeOfWordsList);

    startSpaceman(secretWord, wordsList, sizeOfWordsList);
    return 0;
}

void startSpaceman(string secretWord, string* wordsList, int totalWords) {
    char lettersGuessed[27] = {};
    int totalGuesses = 0;
    int guessesLeft = secretWord.length();

    int lenOfWord = secretWord.length();
    char currentWord[30] = {};

    string prompt = "Welcome to Spaceman!";
    string origonalSecretWord = secretWord; // This is only used if the changeWord function/feature is added

    bool isPlaying = true;
    while(isPlaying) {
        updateCurrentWord(secretWord, lettersGuessed, totalGuesses, currentWord);

        cout << prompt << endl;
        cout << "Current word: " << flush;
        for (int i = 0; i < lenOfWord; i++) {
            cout << currentWord[i] << " " << flush;
        }

        cout << endl << "Letters guessed: " << flush;
        cout << "[" << flush;
        for (int i = 0; i < totalGuesses; i++) {
            if (i < totalGuesses-1) {
                cout << lettersGuessed[i] << ", " << flush;
            } else {
                cout << lettersGuessed[i] << flush;
            }
        }
        cout << "]" << endl;

        cout << "You have " << guessesLeft << " guesses left." << endl;
        cout << "==============================" << endl;
        
        string userGuess;
        do { // TODO: Theres an issue if the user inputs multiple integers
            cout << "Enter a letter: " << flush;
            cin >> userGuess;
        } while(userGuess.length() > 1 or !isalpha(userGuess[0]));

        char guess = userGuess[0];
        if (hasBeenGuessed(guess, lettersGuessed, totalGuesses)) {
            prompt = "You already guessed  ";
            prompt[20] = guess;
            continue;
        } 
        
        if (isGuessInWord(guess, secretWord)) {
            cout << "Correct! " << guess << " in the the secret word." << endl;
        } else {
            cout << "Incorrect. " << guess <<  " is not in the secret word" << endl;
            guessesLeft -= 1;
        }
        lettersGuessed[totalGuesses] = guess;
        totalGuesses += 1;

        if (isWordGuessed(secretWord, lettersGuessed, totalGuesses)) {
            cout << "You Won! Want to play agian? Y/n " << flush;
            string input;
            cin >> input;

            if (input == "N" or input == "n") {
                isPlaying = false;
            } else {

                for (int i = 0; i < lenOfWord; i++) {
                    currentWord[i] = '_';
                }

                totalGuesses = 0;
                secretWord = loadWord(wordsList, totalWords);
                guessesLeft = secretWord.length();

            }
        } else if (guessesLeft <= 0) {
            cout << "Out of guesses! Want to play agian? Y/n " << flush;
            string input;
            cin >> input;

            if (input == "N" or input == "n") {
                isPlaying = false;
            } else {

                for (int i = 0; i < lenOfWord; i++) {
                    currentWord[i] = '_';
                }

                totalGuesses = 0;
                secretWord = loadWord(wordsList, totalWords);
                guessesLeft = secretWord.length();
            }
        }
    }
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

tuple<int, string*> loadWordsList() {
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

    return make_tuple(sizeof(words)/sizeof(string), words);
}

string loadWord(string* wordsList, int n) {
    /* Chooses a random word from the wordslist to be the games secret word */
    srand(time(NULL)); //initialize the random seed
    int randIndex = rand() % n/sizeof(string);
    return wordsList[randIndex];
}

bool isWordGuessed(string secretWord, char* lettersGuessed, int n) {
    /* Checks if the current word is equal to the games secret word */
    for (int i = 0; i < n; i++) {
        if (secretWord.at(i) != lettersGuessed[i]) return false;
    }
    return true;
}

void updateCurrentWord(string secretWord, char* lettersGuessed, int lenOfLetters, char* currentWord) {
    /* Gets the current word list from the current guesses list*/
    for (int i = 0; i < secretWord.length(); i++) {
        currentWord[i] = '_'; // May need to be change to 95 (the ascii code for _)
        for (int j = 0; j < lenOfLetters; j ++) {
            if (secretWord[i] == lettersGuessed[j]) {
                currentWord[i] = lettersGuessed[j];
            }
        }
    }
}

bool isGuessInWord(char guess, string secretWord) {
    for (int i = 0; i < secretWord.length(); i++) {
        if (guess == secretWord.at(i)) return true;
    }
    return false;
}

bool hasBeenGuessed(char guess, char* lettersGuessed, int n) {
    for (int i = 0; i < n; i++) {
        if (guess == lettersGuessed[i]) return true;
    }
    return false;
}

string changeWord(string currentWord, string secretWord, size_t n, string* wordsList) {
    return "pass";
}