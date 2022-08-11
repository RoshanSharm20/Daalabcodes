#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int array[100000];

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void main()
{
    int n, i, j, temp;
    clock_t start, end;
    double totaltime;
    printf("enter the no of elements\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        int r = rand();
        array[i] = r;
    }
    start = clock();
    for (i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        swap(&array[min], &array[i]);
    }
    end = clock();
    totaltime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("total time taken to sort:%f", totaltime);
    printf("the array has been sorted now");
}
