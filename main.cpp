#include <iostream>
#include <string>
using namespace std;

bool checkWinCondition(char board[3][3], char currentPlayer) {
    // Check rows
    for (int row = 0; row < 3; row++) {
        if (board[row][0] == currentPlayer && board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
            return true;
        }
    }

    // Check columns
    for (int column = 0; column < 3; column++) {
        if (board[0][column] == currentPlayer && board[0][column] == board[1][column] && board[1][column] == board[2][column]) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == currentPlayer && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    else if (board[0][2] == currentPlayer && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }

    return false;
}

int main() {
    char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
    };

    const char playerX = *"X";
    const char playerO = *"O";
    char winner = *" ";
    char currentPlayer = playerX;

    int r = -1;
    int c = -1;

    for (int i = 0; i<9; i++) {
        cout << "   |   |   " << endl;
        cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
        cout << "   |   |   " << endl;

        if (winner != ' ') {
            break;
        }

        cout << "Current Player is : \n" << currentPlayer;

        // Inside your main game loop
        while (true) {
            cout << "\n Enter row and column from 1-3: \n";

            cin >> r >> c;
            c --;
            r --;
            if (r < 0 || r >= 3 || c < 0 || c >= 3) {
                cout << "\nInvalid move. Try again." << endl;
            }
            else if (board[r][c] == ' ') {
                board[r][c] = currentPlayer;
                if (checkWinCondition(board, currentPlayer)) {
                    winner = currentPlayer;
                    break;
                }
                currentPlayer = (currentPlayer == playerX) ? playerO : playerX;
                r = -1;
                c = -1;
                break;
            }
            else {
                cout << "\nInvalid move. Try again." << endl;
            }
            cin.clear();
            cin.ignore(10000, '\n');
        }
        if (checkWinCondition(board, currentPlayer)) {
            winner = currentPlayer;
        }
    }

    if (winner != ' ') {
        cout << "Player " << winner << " wins!" << endl;
    }
    else {
        cout << "It's a tie!" << endl;
    }

    return 0;
}
