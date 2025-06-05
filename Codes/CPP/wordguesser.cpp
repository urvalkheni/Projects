#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    string word = "panda"; // You can replace this with a random word from a list
    string guessed(word.length(), '_');
    vector<char> wrongGuesses;
    int maxAttempts = 6;

    cout << "Welcome to the Word Guesser Game!" << endl;
    cout << "You have " << maxAttempts << " incorrect attempts allowed." << endl;
    cout << "Guess the word: " << guessed << endl;

    while (guessed != word && wrongGuesses.size() < maxAttempts) {
        char guess;
        cout << "\nEnter a letter: ";
        cin >> guess;

        // Validate input
        if (!isalpha(guess)) {
            cout << "Invalid input. Please enter a single alphabet character." << endl;
            continue;
        }

        guess = tolower(guess); // Ensure lowercase

        // Check if letter was already guessed
        if (guessed.find(guess) != string::npos || 
            find(wrongGuesses.begin(), wrongGuesses.end(), guess) != wrongGuesses.end()) {
            cout << "You have already guessed that letter." << endl;
            continue;
        }

        // Check if guess is in the word
        bool correctGuess = false;
        for (size_t i = 0; i < word.length(); ++i) {
            if (word[i] == guess) {
                guessed[i] = guess;
                correctGuess = true;
            }
        }

        if (correctGuess) {
            cout << "Correct guess! Word progress: " << guessed << endl;
        } else {
            wrongGuesses.push_back(guess);
            cout << "Wrong guess. Attempts left: " 
                 << (maxAttempts - wrongGuesses.size()) << endl;

            cout << "Wrong guesses so far: ";
            for (char ch : wrongGuesses) {
                cout << ch << ' ';
            }
            cout << endl;
        }
    }

    if (guessed == word) {
        cout << "\nCongratulations! You guessed the word: " << word << endl;
    } else {
        cout << "\nYou ran out of attempts. The correct word was: " << word << endl;
    }

    return 0;
}
