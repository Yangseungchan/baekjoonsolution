#include <stdio.h>
int main(void)
{
    long long easystairs[101][10];
    long long sum;
    int num, i, j;
    scanf("%d", &num);
    sum = 0;
    easystairs[1][0] = 0;
    for (i = 1; i <= 9; i++)
    {
        easystairs[1][i] = 1;
    }

    for (i = 2; i <= num; i++)
    {
        easystairs[i][0] = easystairs[i - 1][1] % 1000000000;
        for (j = 1; j <= 8; j++)
        {
            easystairs[i][j] = (easystairs[i - 1][j - 1] + easystairs[i - 1][j + 1]) % 1000000000;
        }
        easystairs[i][9] = easystairs[i - 1][8] % 1000000000;
    }

    for (i = 0; i <= 9; i++)
    {
        sum += easystairs[num][i] % 1000000000;
    }

    printf("%lld\n", sum % 1000000000);

    return 0;
}