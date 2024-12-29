#include <stdio.h>

char board[3][3]; // Tic-Tac-Toe board

// Function to initialize the board
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '1' + (i * 3 + j);
        }
    }
}

// Function to display the board
void displayBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

// Function to check if a player has won
int checkWinner() {
    for (int i = 0; i < 3; i++) {
        // Check rows and columns
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return 1;
        }
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return 1;
    }
    return 0;
}

// Function to check if the board is full
int isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int player = 1, choice;
    char mark;

    initializeBoard();

    while (1) {
        displayBoard();
        printf("Player %d, enter your choice: ", player);
        scanf("%d", &choice);

        // Determine the mark (X or O) for the current player
        mark = (player == 1) ? 'X' : 'O';

        // Map choice to board position
        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        // Place the mark on the board
        board[row][col] = mark;

        // Check for a winner
        if (checkWinner()) {
            displayBoard();
            printf("Player %d wins!\n", player);
            break;
        }

        // Check for a draw
        if (isBoardFull()) {
            displayBoard();
            printf("It's a draw!\n");
            break;
        }

        // Switch player
        player = (player == 1) ? 2 : 1;
    }

    return 0;
}




