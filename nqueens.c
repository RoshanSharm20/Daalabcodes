#include <stdio.h>
#include <stdlib.h>
int issafe(int board[10][10], int row, int column, int n)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        if (board[i][column])
            return 0;
    }
    for (i = row, j = column; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return 0;
    }
    for (i = row, j = column; i >= 0 && j >= 0; i--, j++)
    {
        if (board[i][j])
            return 0;
    }

    return 1;
}

int nqueens(int board[10][10], int row, int n)
{
    if (row == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d  ", board[i][j]);
            }
            printf("\n");
        }

        printf("\n \n");
        return 0;
    }

    for (int col = 0; col < n; col++)
    {
        if (issafe(board, row, col, n))
        {
            board[row][col] = 1;
            if (nqueens(board, row + 1, n))
            {
                return 1;
            }
            board[row][col] = 0;
        }
    }
    return 0;
}
int main()
{
    int board[10][10] = {0};
    nqueens(board, 0, 4);

    return 0;
}