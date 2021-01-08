#include <iostream>

#define INIT_MIN -99999999
using namespace std;

int dp[21][21][21];

int get_dp(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }
    else
    {
        if (a > 20 || b > 20 || c > 20)
        {
            return get_dp(20, 20, 20);
        }
        else if (dp[a][b][c] != INIT_MIN)
        {
            return dp[a][b][c];
        }
        else if (a < b && b < c)
        {
            int n1, n2, n3;
            n1 = dp[a][b][c - 1] != INIT_MIN ? dp[a][b][c - 1] : get_dp(a, b, c - 1);
            n2 = dp[a][b - 1][c - 1] != INIT_MIN ? dp[a][b - 1][c - 1] : get_dp(a, b - 1, c - 1);
            n3 = dp[a][b - 1][c] != INIT_MIN ? dp[a][b - 1][c] : get_dp(a, b - 1, c);
            dp[a][b][c] = n1 + n2 - n3;
            return n1 + n2 - n3;
        }
        else
        {
            int n1, n2, n3, n4;
            n1 = dp[a - 1][b][c] != INIT_MIN ? dp[a - 1][b][c] : get_dp(a - 1, b, c);
            n2 = dp[a - 1][b - 1][c] != INIT_MIN ? dp[a - 1][b - 1][c] : get_dp(a - 1, b - 1, c);
            n3 = dp[a - 1][b][c - 1] != INIT_MIN ? dp[a - 1][b][c - 1] : get_dp(a - 1, b, c - 1);
            n4 = dp[a - 1][b - 1][c - 1] != INIT_MIN ? dp[a - 1][b - 1][c - 1] : get_dp(a - 1, b - 1, c - 1);
            dp[a][b][c] = n1 + n2 + n3 - n4;
            return n1 + n2 + n3 - n4;
        }
    }
}

int main(void)
{
    int a, b, c;
    cin >> a >> b >> c;

    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            for (int k = 0; k < 21; k++)
                if (i == 0 || j == 0 || k == 0)
                {
                    dp[i][j][k] = 1;
                }
                else
                {
                    dp[i][j][k] = INIT_MIN;
                }
        }
    }

    do
    {
        int result = get_dp(a, b, c);
        cout << "w(" << a << ", " << b << ", " << c << ") = " << result << '\n';
        cin >> a >> b >> c;

    } while (!(a == -1 && b == -1 && c == -1));

    return 0;
}