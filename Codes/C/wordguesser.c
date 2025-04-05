#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Function to shuffle the characters of a word
void shuffleWord(char *word, char *shuffled) {
    int len = strlen(word);
    int used[len];
    memset(used, 0, sizeof(used));

    for (int i = 0; i < len; i++) {
        int index;
        do {
            index = rand() % len;
        } while (used[index]);
        shuffled[i] = word[index];
        used[index] = 1;
    }
    shuffled[len] = '\0';
}

int main() {
    srand(time(0)); // Seed for randomization

    char word[100], guess[100], scrambled[100];
    int attempts = 3;

    printf("Player 1, enter a word to scramble: ");
    scanf("%s", word);
    system("clear || cls"); // Clears the screen to hide the word

    shuffleWord(word, scrambled);

    printf("Player 2, guess the scrambled word: %s\n", scrambled);

    while (attempts > 0) {
        printf("Enter your guess (%d attempts left): ", attempts);
        scanf("%s", guess);

        if (strcmp(word, guess) == 0) {
            printf("Congratulations! You guessed the word: %s\n", word);
            return 0;
        } else {
            attempts--;
            printf("Wrong guess!\n");
        }
    }

    printf("Game Over! The correct word was: %s\n", word);
    return 0;
}
