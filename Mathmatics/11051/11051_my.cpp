#include <iostream>
#include <vector>

using namespace std;

long long combination(int n, int k)
{
    vector<int> upper;
    vector<int> lower;
    long long result;

    for (int i = 0; i < k; i++)
    {
        upper.push_back(n - i);
        lower.push_back(k - i);
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (upper[j] % lower[i] == 0)
            {
                upper[j] /= lower[i];
                break;
            }
        }
    }

    for (int i = 0; i < k; i++)
    {
        upper[i] %= 10007;
    }
    result = upper[0];
    for (int i = 1; i < k; i++)
    {
        result *= upper[i];
        result %= 10007;
    }
    return result % 10007;
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    cout << combination(n, k) << '\n';
    return 0;
}