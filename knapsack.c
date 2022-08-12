#include <stdio.h>
#include <stdlib.h>
int maximum(int x, int y)
{
    return (x > y) ? x : y;
}
void knapsack(int W, int weights[], int prices[], int n)
{
    int knap[20][20], x[20];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                knap[i][j] = 0;
            else if (j >= weights[i])
                knap[i][j] = maximum(prices[i] + knap[i - 1][j - weights[i]], knap[i - 1][j]);
            else
                knap[i][j] = knap[i - 1][j];
        }
    }
    int i = n;
    int j = W;
    while (i > 0 && j > 0)
    {
        if (knap[i][j] != knap[i - 1][j])
        {
            x[i] = 1;
            j = j - weights[i];
        }
        i--;
    }

    printf("the maximum profit obtained is:%d\n", knap[n][W]);
    printf("the included elements are:\n");
    for (int i = 1; i <= n; i++)
    {
        if (x[i] == 1)
        {
            printf("sl.no: %d,price: %d,weight: %d", i, prices[i], weights[i]);
        }
    }
}
int main()
{
    int prices[10], weights[10], W, n;
    printf("enter the capacity:\n");
    scanf("%d", &W);
    printf("enter the size of the price array:\n");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("enter the price and corresponding weight:\n");
        scanf("%d%d", &prices[i], &weights[i]);
    }
    knapsack(W, weights, prices, n);
    return 0;
}