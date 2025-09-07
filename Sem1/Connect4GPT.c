#define ROWS 6
#define COLS 7

void printBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
    for (int j = 0; j < COLS; j++) {
        printf("  %d ", j + 1);
    }
    printf("\n");
}

int dropToken(char board[ROWS][COLS], int col, char token) {
    if (col < 0 || col >= COLS || board[0][col] != ' ') {
        return 0;
    }
    for (int i = ROWS - 1; i >= 0; i--) {
        if (board[i][col] == ' ') {
            board[i][col] = token;
            return 1;
        }
    }
    return 0;
}

int checkWin(char board[ROWS][COLS], char token) {
    // Check horizontal
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == token && board[i][j + 1] == token &&
                board[i][j + 2] == token && board[i][j + 3] == token) {
                return 1;
            }
        }
    }
    // Check vertical
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == token && board[i + 1][j] == token &&
                board[i + 2][j] == token && board[i + 3][j] == token) {
                return 1;
            }
        }
    }
    // Check diagonal (bottom left to top right)
    for (int i = 3; i < ROWS; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == token && board[i - 1][j + 1] == token &&
                board[i - 2][j + 2] == token && board[i - 3][j + 3] == token) {
                return 1;
            }
        }
    }
    // Check diagonal (top left to bottom right)
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == token && board[i + 1][j + 1] == token &&
                board[i + 2][j + 2] == token && board[i + 3][j + 3] == token) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    char board[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }

    char playerTokens[2] = {'X', 'O'};
    int currentPlayer = 0;
    int column;
    int moves = 0;

    while (1) {
        printBoard(board);
        printf("Player %d (%c), choose a column (1-7): ", currentPlayer + 1, playerTokens[currentPlayer]);
        scanf("%d", &column);
        if (dropToken(board, column - 1, playerTokens[currentPlayer])) {
            moves++;
            if (checkWin(board, playerTokens[currentPlayer])) {
                printBoard(board);
                printf("Player %d (%c) wins!\n", currentPlayer + 1, playerTokens[currentPlayer]);
                break;
            }
            if (moves == ROWS * COLS) {
                printBoard(board);
                printf("It's a draw!\n");
                break;
            }
            currentPlayer = 1 - currentPlayer; // Switch player
        } else {
            printf("Invalid move, try again.\n");
        }
    }

    return 0;
}