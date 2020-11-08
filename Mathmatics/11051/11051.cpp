#include <iostream>
#include <vector>

using namespace std;

int comb[1001][1001]; /* nCk */

int combination(int n, int k)
{
    if (comb[n][k] == -1)
    {
        comb[n][k] = ((combination(n - 1, k - 1) % 10007) + (combination(n - 1, k) % 10007)) % 10007;
    }

    return comb[n][k] % 10007;
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < 1001; i++)
    {
        for (int j = 0; j < 1001; j++)
        {
            if (j == 0 || j == i)
            {
                comb[i][j] = 1;
            }
            else
            {
                comb[i][j] = -1;
            }
        }
    }
    cout << combination(n, k) << '\n';
    return 0;
}