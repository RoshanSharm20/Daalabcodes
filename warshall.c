#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int maxi(int x, int y)
{
    if (x >= y)
        return x;
    else
        return y;
}
void warshall(int graph[10][10], int v)
{
    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                graph[i][j] = maxi(graph[i][j], graph[i][k] && graph[k][j]);
            }
        }
    }
}
void main()
{
    int graph[10][10] = {0}, v, e, a, b;
    printf("enter the number of vertices\n");
    scanf("%d", &v);
    printf("enter the number of edges\n");
    scanf("%d", &e);
    for (int i = 1; i <= e; i++)
    {
        printf("enter the end vertices of edge\n");
        scanf("%d%d", &a, &b);
        graph[a][b] = 1;
    }
    printf("the entered matrix is :\n");
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
    warshall(graph, v);
    printf("the transitive closure matrix is :\n");
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
}