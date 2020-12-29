#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int arr[100001];
int arr_m[100001];

int bin_search(int find, int n) // n = length of arr
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == find)
            return 1;
        else if (arr[mid] < find)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return 0;
}

int main(void)
{
    int N, M, find;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(&arr[0], &arr[N]);

    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &arr_m[i]);
    }
    for (int i = 0; i < M; i++)
    {
        printf("%d\n", bin_search(arr_m[i], N));
    }
    return 0;
}