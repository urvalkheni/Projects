#include <iostream>
#include <limits>
using namespace std;

char board[3][3];
char currentPlayer = 'X';

void initializeBoard() {
    char pos = '1';
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = pos++;
}

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        cout << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n---|---|---\n";
    }
    cout << "\n";
}

bool checkWin() {
    for (int i = 0; i < 3; ++i)
        if ((board[i][0] == currentPlayer &&
             board[i][1] == currentPlayer &&
             board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer &&
             board[1][i] == currentPlayer &&
             board[2][i] == currentPlayer))
            return true;

    if ((board[0][0] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][0] == currentPlayer))
        return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void getPlayerMove() {
    int move;
    bool valid = false;

    while (!valid) {
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if (cin.fail() || move < 1 || move > 9) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 9.\n";
            continue;
        }

        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "That cell is already taken. Try again.\n";
        } else {
            board[row][col] = currentPlayer;
            valid = true;
        }
    }
}

void playGame() {
    initializeBoard();
    currentPlayer = 'X';

    while (true) {
        displayBoard();
        getPlayerMove();

        if (checkWin()) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins.\n";
            break;
        }

        if (checkDraw()) {
            displayBoard();
            cout << "The game is a draw.\n";
            break;
        }

        switchPlayer();
    }
}

int main() {
    char playAgain;

    do {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Game over.\n";
    return 0;
}