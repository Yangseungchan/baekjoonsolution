#include <stdio.h>
#include <stdlib.h>

typedef struct __node
{
    int PosA;
    int PosB;
} Node;

Node nde[100];

void swapnde(Node *n1, Node *n2)
{
    int tmpA, tmpB;
    tmpA = n1->PosA;
    tmpB = n1->PosB;
    n1->PosA = n2->PosA;
    n1->PosB = n2->PosB;
    n2->PosA = tmpA;
    n2->PosB = tmpB;
}

void sortnde(int num)
{
    int i, j, min, min_idx;
    for (i = 0; i < num - 1; i++)
    {
        min = nde[i].PosA;
        min_idx = i;
        for (j = i + 1; j < num; j++)
        {
            if (min > nde[j].PosA)
            {
                min = nde[j].PosA;
                min_idx = j;
            }
        }
        swapnde(&nde[i], &nde[min_idx]);
    }
}

int find_max(int *arr, int size)
{
    int max = arr[0];
    for (size_t i = 0; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

int main(void)
{
    int i, j, num, max, dp1_max;
    int dp1[100];
    scanf("%d", &num);
    for (i = 0; i < num; i++)
    {
        scanf("%d %d", &(nde[i].PosA), &(nde[i].PosB));
    }
    sortnde(num);

    dp1[0] = 1;
    for (i = 1; i < num; i++)
    {
        max = 0;
        for (j = 0; j < i; j++)
        {
            if (nde[i].PosA > nde[j].PosA && nde[i].PosB > nde[j].PosB)
            {
                if (max < dp1[j])
                {
                    max = dp1[j];
                }
            }
        }
        dp1[i] = max + 1;
    }
    dp1_max = find_max(dp1, num);

    printf("%d\n", num - dp1_max);
    return 0;
}