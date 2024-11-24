#include <stdio.h>
#include <limits.h>

#define PLAYER 'X'
#define AI 'O'
#define SIZE 3

char board[SIZE][SIZE];

// Function Prototypes
void initializeBoard();
void printBoard();
int isMovesLeft();
int checkWin();
int minimax(int depth, int isMax);
int bestMove();
void makeMove(int row, int col, char player);

int main()
{
    int row, col;
    initializeBoard();

    while (1)
    {
        printBoard();

        // Player's move
        printf("Enter your move (row and column): ");
        scanf("%d %d", &row, &col);

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != '_')
        {
            printf("Invalid move. Try again.\n");
            continue;
        }

        makeMove(row - 1, col - 1, PLAYER);

        if (checkWin() == 10)
        {
            printBoard();
            printf("You win!\n");
            break;
        }

        if (!isMovesLeft())
        {
            printBoard();
            printf("It's a draw!\n");
            break;
        }

        // AI's move
        int aiMove = bestMove();
        makeMove(aiMove / SIZE, aiMove % SIZE, AI);

        if (checkWin() == -10)
        {
            printBoard();
            printf("AI wins!\n");
            break;
        }

        if (!isMovesLeft())
        {
            printBoard();
            printf("It's a draw!\n");
            break;
        }
    }
    return 0;
}

// Initialize the Tic-Tac-Toe board
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

int checkWin()
{
    for (int i = 0; i < SIZE; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '_')
        {
            return (board[i][0] == PLAYER) ? 10 : -10;
        }

        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '_')
        {
            return (board[0][i] == PLAYER) ? 10 : -10;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '_')
    {
        return (board[0][0] == PLAYER) ? 10 : -10;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '_')
    {
        return (board[0][2] == PLAYER) ? 10 : -10;
    }

    return 0;
}

int minimax(int depth, int isMax)
{
    int score = checkWin();

    if (score == 10)
        return score - depth;

    if (score == -10)
        return score + depth;

    if (!isMovesLeft())
        return 0;

    if (isMax)
    {
        int best = INT_MIN;

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (board[i][j] == '_')
                {
                    board[i][j] = PLAYER;
                    best = (best > minimax(depth + 1, 0)) ? best : minimax(depth + 1, 0);
                    board[i][j] = '_';
                }
            }
        }
        return best;
    }
    else
    {
        int best = INT_MAX;

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (board[i][j] == '_')
                {
                    board[i][j] = AI;
                    best = (best < minimax(depth + 1, 1)) ? best : minimax(depth + 1, 1);
                    board[i][j] = '_';
                }
            }
        }
        return best;
    }
}

int bestMove()
{
    int bestVal = INT_MAX;
    int move = -1;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == '_')
            {
                board[i][j] = AI;
                int moveVal = minimax(0, 1);
                board[i][j] = '_';

                if (moveVal < bestVal)
                {
                    bestVal = moveVal;
                    move = i * SIZE + j;
                }
            }
        }
    }

    return move;
}

void makeMove(int row, int col, char player)
{
    board[row][col] = player;
}