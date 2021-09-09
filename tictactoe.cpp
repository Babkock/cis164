/* Tic tac toe game
 * Tanner Babcock
 * tababcock@dmacc.edu
 * September 4, 2021
*/
#include <iostream>
using namespace std;

extern char board[];
char board[] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};

void drawBoard(void) {
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << " -----------" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << " -----------" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

int main(void) {
    char mark[] = {'X','O'};
    int move = 0;
    const int MAXMOVES = 9;
    for (int turn = 0; turn < MAXMOVES; turn++) {
        //draw the board
        drawBoard();
        // get next move
        cout << endl << "Player " << (turn%2)+1 << " select cell (1 - 9)" << endl;
        cin >> move;

        if (board[move-1] != ' ') {
            cout << "Sorry but that cell is taken! You lose the game." << endl;
            turn = MAXMOVES;
        }
        else {
            board[move-1] = mark[turn%2];
        }
        /* This section of the code checks all of the board positions that would
         * produce a victory for each player. Each player can win via the top, middle,
         * and bottom rows, as well as the left, middle, and right columns. A player
         * can also win diagonally.
        */
        if (turn > 3) {
            if ((board[0] == 'X' && board[1] == 'X' && board[2] == 'X') || // top row
                (board[3] == 'X' && board[4] == 'X' && board[5] == 'X') || // middle row
                (board[6] == 'X' && board[7] == 'X' && board[8] == 'X') || // bottom row
                (board[0] == 'X' && board[3] == 'X' && board[6] == 'X') || // left column
                (board[1] == 'X' && board[4] == 'X' && board[7] == 'X') || // middle column
                (board[2] == 'X' && board[5] == 'X' && board[8] == 'X') || // right column
                (board[0] == 'X' && board[4] == 'X' && board[8] == 'X') || // diagonal
                (board[2] == 'X' && board[4] == 'X' && board[6] == 'X')) { // diagonal
                drawBoard();
                cout << endl << "Player one (X) wins!" << endl;
                break;
            }
            if ((board[0] == 'O' && board[1] == 'O' && board[2] == 'O') || // top row
                (board[3] == 'O' && board[4] == 'O' && board[5] == 'O') || // middle row
                (board[6] == 'O' && board[7] == 'O' && board[8] == 'O') || // bottom row
                (board[0] == 'O' && board[3] == 'O' && board[6] == 'O') || // left column
                (board[1] == 'O' && board[4] == 'O' && board[7] == 'O') || // middle column
                (board[2] == 'O' && board[5] == 'O' && board[8] == 'O') || // right column
                (board[0] == 'O' && board[4] == 'O' && board[8] == 'O') || // diagonal
                (board[2] == 'O' && board[4] == 'O' && board[6] == 'O')) { // diagonal
                drawBoard();
                cout << "Player two (O) wins!" << endl;
                break;
            }
        }
    }
    cout << "Game Over." << endl;
    return 0;
}

/* I expected this program to work, and it did. I made a function
 * for drawing the board, as I wanted to draw it in multiple spots
 * in the code */
