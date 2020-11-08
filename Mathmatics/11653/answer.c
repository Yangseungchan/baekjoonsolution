#include <stdio.h>
int main()
{
    int n, i, j;
    scanf("%d", &n);
    for (i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            n /= i;
            printf("%d\n", i);
        }
    }
    if (n > 1)
        printf("%d\n", n);
}