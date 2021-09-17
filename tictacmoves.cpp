/* Tic tac toe moves
 * Tanner Babcock
 * tababcock@dmacc.edu
 * September 16, 2021 */
#include <iostream>
#include <array>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    vector<unsigned int> xmoves;
    vector<unsigned int> omoves;
    array<char, 2> mark = {'X', 'O'};
    array<char, 9> board = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    unsigned int move = 0;
    const int MAXMOVES = 9;

    for (int turn = 0; turn < MAXMOVES; turn++) {
        // draw the board
        cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
        cout << "-----------" << endl;
        cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
        cout << "-----------" << endl;
        cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;

        // get the next move
        cout << endl << "Player " << ((turn % 2) + 1) << " select a cell (1 - 9): ";
        cin >> move;
        if (board[move-1] != ' ') {
            cerr << "Sorry but that cell is taken! You lose the game" << endl;
            turn = MAXMOVES;
        }
        else {
            board[move-1] = mark[turn % 2];
        }

        // add move to vector
        if (((turn % 2) + 1) == 1) // player 1 'X'
            xmoves.push_back(move);
        else
            omoves.push_back(move);
    }
    cout << "Game Over" << endl;

    cout << endl << "Review of Player 1 (X) Moves:" << endl;
    int x = 1;
    for (const unsigned int& i : xmoves) {
        cout << "Move " << x << " - Space " << i << endl;
        x++;
    }
    x = 1;
    cout << "Review of Player 2 (O) Moves:" << endl;
    for (const unsigned int& i : omoves) {
        cout << "Move " << x << " - Space " << i << endl;
        x++;
    }

    return 0;
}
