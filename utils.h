#ifndef UTILS_H_
#define UTILS_H_

// Spaceman Function Prototypes
int getWordsCount();
std::tuple<size_t, std::string*> loadWordsList();
std::string loadWord(size_t n, std::string* wordsList);
bool isWordGuessed(std::string secretWord, char* lettersGuessed);
std::string getGuessedWord(std::string secretWord, size_t n, char* lettersGuessed);
bool isGuessInWord(std::string guess, std::string secretWord);
bool hasBeenGuessed(std::string guess, size_t n, char* lettersGuessed);
std::string changeWord(std::string currentWord, std::string secretWord, size_t n, std::string* wordsList);
void startSpaceman(std::string secretWord, size_t n, std::string* spacemanWordsList);

#endif /* UTLS_H_ */