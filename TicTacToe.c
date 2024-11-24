#include <stdio.h>

#define SIZE 3

char board[SIZE][SIZE];
char currentPlayer;

// Function prototypes
void initializeBoard();
void printBoard();
int makeMove(int row, int col);
int checkWin();
int isMovesLeft();

// Initialize the Tic-Tac-Toe board with empty spaces
void initializeBoard()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = '_';
        }
    }
}

// Print the Tic-Tac-Toe board
void printBoard()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Make a move on the board
int makeMove(int row, int col)
{
    // Check if the move is within the bounds of the board and the cell is empty
    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == '_')
    {
        board[row][col] = currentPlayer;
        return 1;
    }
    return 0;
}

// Check if there is a winner
int checkWin()
{
    // Check rows and columns
    for (int i = 0; i < SIZE; i++)
    {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
        {
            return 1;
        }
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
    {
        return 1;
    }
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
    {
        return 1;
    }

    return 0;
}

// Check if there are moves left on the board
int isMovesLeft()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == '_')
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int row, col;
    int gameOver = 0;

    initializeBoard();
    currentPlayer = 'X';

    while (!gameOver)
    {
        printBoard();
        printf("Player %c, enter your move (row and column): ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Check if the move is valid
        if (makeMove(row - 1, col - 1))
        {
            // Check if the current player has won
            if (checkWin())
            {
                printBoard();
                printf("Player %c wins!\n", currentPlayer);
                gameOver = 1;
            }
            else if (!isMovesLeft())
            {
                printBoard();
                printf("It's a draw!\n");
                gameOver = 1;
            }
            else
            {
                // Switch players
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }
        else
        {
            printf("Invalid move! Please try again.\n");
        }
    }

    return 0;
}