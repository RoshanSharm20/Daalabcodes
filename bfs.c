#include <stdio.h>
#include <stdlib.h>
int graph[20][20];
int queue[200];
int visited[20];
int start = -1, end = -1;
void insert(int x)
{
    queue[++end] = x;
    end++;
}
int pop()
{
    return queue[start++];
}
void bfs(int x)
{
    insert(x);
    visited[x] = 1;
    while (start != end)
    {
        x = pop();
        printf("%d ", x);
        for (int i = 0; i < 20; i++)
        {
            if ((graph[x][i] == 1) && (visited[i] == 0))
            {
                insert(i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    for (int i = 0; i < 20; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            graph[i][j] = 0;
        }
    }
    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[0][3] = 1;
    graph[1][0] = 1;
    graph[2][0] = 1;
    graph[2][3] = 1;
    graph[3][0] = 1;
    graph[3][2] = 1;
    bfs(2);
}