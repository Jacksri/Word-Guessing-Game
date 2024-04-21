#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
class WordGame {
public:
    WordGame()
    {
        srand(static_cast < unsigned int>(time(nullptr)));
        currentWord = getRandomWord();
        incorrectAttempts = 0;
        maxAttempts = 6;
        initializeDisplayWord();
    }
    void play() {
        while (!isGameOver()) {
            displayGameStatus();
            char guess = getGuess();
            checkGuess(guess);
        }
        displayResult();
    }

private:
    string currentWord;
    string displayWord;
    int incorrectAttempts;
    int maxAttempts;

    vector<string> wordList = {"programming", "hacking", "developer", "keyboard",
    "algorithm", "computer","password","username","gmail","application","search","module"};

    string getRandomWord() const {
        return wordList[rand() % wordList.size()];
    }

    void initializeDisplayWord() {
        displayWord = string(currentWord.length(), '_');
    }

    void displayGameStatus() const {

        cout << "\nCurrent word: " << displayWord << endl;
        cout << "Incorrect attempts remaining: " << maxAttempts - incorrectAttempts << endl;
    }

    char getGuess() const {
        char guess;
        cout << "Enter a letter guess: ";
        cin >> guess;
        return guess;
    }

    void checkGuess(char guess) {
        size_t found = currentWord.find(guess);

        if (found != string::npos) {
            // Correct guess
            updateDisplayWord(guess);
        }
        else
        {
            // Incorrect guess
            cout << "Incorrect guess. Try again." << endl;
            incorrectAttempts++;
        }
    }

    void updateDisplayWord(char guess) {
        for (size_t i = 0; i < currentWord.length(); ++i)
            {
            if (currentWord[i] == guess) {
                displayWord[i] = guess;
            }
        }
    }

    bool isGameOver() const {
        if (incorrectAttempts >= maxAttempts) {
            return true;  // Game over due to too many incorrect attempts
        } else if (displayWord == currentWord) {
            return true;  // Player successfully guessed the word
        }
        return false;
    }

    void displayResult() const {
        if (displayWord == currentWord) {
            cout << "Congratulations! You guessed the word: " << currentWord << endl;
        } else {
            cout << "Sorry! You ran out of attempts. The correct word was: " << currentWord << endl;
        }
    }
};

int main() {
    cout<<"****************WELCOME TO WORD GUESSING GAME******************\n";
    cout<<"All are technical words using this game \n ";
    WordGame game;
    game.play();
    cout<<"                     ...GAME OVER...                            ";
    return 0;
}
