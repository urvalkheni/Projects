#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void numberGuessingGame() {
    int number, guess, attempts = 0;
    char playAgain;

    // Seed random number generator
    srand(time(0));
    number = rand() % 100 + 1; // Generate random number between 1 and 100

    printf("Welcome to the Number Guessing Game!\n");
    printf("I have selected a number between 1 and 100.\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess > number) {
            printf("Too high! Try again.\n");
        } else if (guess < number) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
        }
    } while (guess != number);

    printf("Would you like to play again? (y/n): ");
    scanf(" %c", &playAgain);

    if (playAgain == 'y' || playAgain == 'Y') {
        numberGuessingGame(); // Restart the game
    } else {
        printf("Thanks for playing! Goodbye.\n");
    }
}

int main() {
    numberGuessingGame();
    return 0;
}
