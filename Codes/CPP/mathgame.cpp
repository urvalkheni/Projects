#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to generate a random math question and return the correct answer
int generateQuestion(int& correctAnswer) {
    int num1 = rand() % 20 + 1;
    int num2 = rand() % 20 + 1;
    int operation = rand() % 4;

    switch (operation) {
        case 0:
            cout << "What is " << num1 << " + " << num2 << "? ";
            correctAnswer = num1 + num2;
            break;
        case 1:
            cout << "What is " << num1 << " - " << num2 << "? ";
            correctAnswer = num1 - num2;
            break;
        case 2:
            cout << "What is " << num1 << " * " << num2 << "? ";
            correctAnswer = num1 * num2;
            break;
        case 3:
            // Ensure valid division
            while (num2 == 0) {
                num2 = rand() % 20 + 1;
            }
            cout << "What is " << num1 * num2 << " / " << num2 << "? ";
            correctAnswer = num1;
            break;
    }
    return correctAnswer;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    const int timeLimitInSeconds = 60;
    int score = 0;
    int userAnswer = 0;
    int correctAnswer = 0;

    cout << "=== Math Brain Trainer Game ===" << endl;
    cout << "You have " << timeLimitInSeconds << " seconds to answer as many questions as you can." << endl;
    cout << "Each correct answer gives you 1 point." << endl;
    cout << "Press Enter to start the game...";
    cin.ignore();

    auto startTime = steady_clock::now();

    while (true) {
        auto currentTime = steady_clock::now();
        auto elapsedTime = duration_cast<seconds>(currentTime - startTime).count();

        if (elapsedTime >= timeLimitInSeconds) {
            break;
        }

        generateQuestion(correctAnswer);
        cin >> userAnswer;

        if (userAnswer == correctAnswer) {
            cout << "Correct!" << endl;
            ++score;
        } else {
            cout << "Incorrect. The correct answer was " << correctAnswer << "." << endl;
        }

        cout << "Time remaining: " << timeLimitInSeconds - elapsedTime << " seconds" << endl;
        cout << "--------------------------------------" << endl;
    }

    cout << "\nTime's up!" << endl;
    cout << "Your final score: " << score << endl;
    cout << "Thank you for playing." << endl;

    return 0;
}
