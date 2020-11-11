#ifndef UTILS_H_
#define UTILS_H_

// Spaceman Function Prototypes
int getWordsCount();
std::tuple<int, std::string*> loadWordsList();
std::string loadWord(std::string* wordsList, int n);
bool isWordGuessed(std::string secretWord, char* lettersGuessed, int n);
void updateCurrentWord(std::string secretWord, char *lettersGuessed, int lenOfLetters, char *currentWord);
bool isGuessInWord(char guess, std::string secretWord);
bool hasBeenGuessed(char guess, char* lettersGuessed, int n);
std::string changeWord(std::string currentWord, std::string secretWord, std::string* wordsList, int n);
void startSpaceman(std::string secretWord, std::string* wordsList, int totalWords);

#endif /* UTLS_H_ */