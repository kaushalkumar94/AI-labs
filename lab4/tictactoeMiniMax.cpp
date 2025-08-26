#include <bits/stdc++.h>
using namespace std;

const int PLAYER = -1; // Human (MIN)
const int AI = 1;      // Computer (MAX)

struct Move {
    int row, col;
};

// Function to print board
void printBoard(vector<vector<int>> &board) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char c;
            if (board[i][j] == 1) c = 'X';
            else if (board[i][j] == -1) c = 'O';
            else c = '.';
            cout << c << " ";
        }
        cout << "\n";
    }
}

// Check if there is a winner
int evaluate(vector<vector<int>> &board) {
    // Rows
    for (int i = 0; i < 3; i++) {
        int sum = board[i][0] + board[i][1] + board[i][2];
        if (sum == 3) return 1;   // AI wins
        if (sum == -3) return -1; // Human wins
    }
    // Cols
    for (int j = 0; j < 3; j++) {
        int sum = board[0][j] + board[1][j] + board[2][j];
        if (sum == 3) return 1;
        if (sum == -3) return -1;
    }
    // Diagonals
    int diag1 = board[0][0] + board[1][1] + board[2][2];
    int diag2 = board[0][2] + board[1][1] + board[2][0];
    if (diag1 == 3 || diag2 == 3) return 1;
    if (diag1 == -3 || diag2 == -3) return -1;

    return 0; // no winner
}

// Check if moves are left
bool movesLeft(vector<vector<int>> &board) {
    for (auto &row : board)
        for (auto cell : row)
            if (cell == 0) return true;
    return false;
}

// Minimax function based on the given strategy
int minimax(vector<vector<int>> &board, bool isMax) {
    int score = evaluate(board);

    // Terminal states
    if (score == 1) return 1;   // AI wins
    if (score == -1) return -1; // Human wins
    if (!movesLeft(board)) return 0; // Draw

    if (isMax) { // MAX's turn
        int best = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0) {
                    board[i][j] = AI;
                    best = max(best, minimax(board, false));
                    board[i][j] = 0;
                }
            }
        }
        return best;
    } else { // MIN's turn
        int best = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0) {
                    board[i][j] = PLAYER;
                    best = min(best, minimax(board, true));
                    board[i][j] = 0;
                }
            }
        }
        return best;
    }
}

// Find the best move for AI
Move findBestMove(vector<vector<int>> &board) {
    int bestVal = -1000;
    Move bestMove = {-1, -1};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                board[i][j] = AI;
                int moveVal = minimax(board, false);
                board[i][j] = 0;
                if (moveVal > bestVal) {
                    bestMove = {i, j};
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}

int main() {
    vector<vector<int>> board(3, vector<int>(3, 0));

    cout << "Tic Tac Toe (AI = X, Human = O)\n";
    printBoard(board);

    while (true) {
        // Human move
        int r, c;
        cout << "Enter your move (row col): ";
        cin >> r >> c;
        if (board[r][c] != 0) {
            cout << "Invalid move, try again.\n";
            continue;
        }
        board[r][c] = PLAYER;

        printBoard(board);
        if (evaluate(board) == -1) { cout << "You win!\n"; break; }
        if (!movesLeft(board)) { cout << "It's a draw!\n"; break; }

        // AI move
        Move bestMove = findBestMove(board);
        board[bestMove.row][bestMove.col] = AI;
        cout << "AI chooses: " << bestMove.row << " " << bestMove.col << "\n";

        printBoard(board);
        if (evaluate(board) == 1) { cout << "AI wins!\n"; break; }
        if (!movesLeft(board)) { cout << "It's a draw!\n"; break; }
    }
    return 0;
}
