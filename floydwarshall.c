#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int mini(int x, int y)
{
    if (x <= y)
        return x;
    else
        return y;
}
void floydwarshall(int graph[10][10], int v)
{
    for (int k = 1; k <= v; k++)
    {
        for (int i = 1; i <= v; i++)
        {
            for (int j = 1; j <= v; j++)
            {
                if (i == j)
                    graph[i][j] = 0;
                else
                    graph[i][j] = mini(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}
void main()
{
    int graph[10][10], v, e, a, b, w;
    printf("enter the number of vertices\n");
    scanf("%d", &v);
    printf("enter the number of edges:\n");
    scanf("%d", &e);
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            graph[i][j] = 999;
        }
    }
    for (int i = 0; i < e; i++)
    {
        printf("enter the end of vertices with their weights\n");
        scanf("%d%d%d", &a, &b, &w);
        graph[a][b] = w;
    }
    printf("the adjacnecy matrix entered is:\n");
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
    floydwarshall(graph, v);
    printf("the shortest distance matrix is:\n");
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
}