#include <iostream>

using namespace std;

int combination(int n, int k)
{
    int upper = 1;
    int lower = 1;

    for (int i = 0; i < k; i++)
    {
        upper *= (n - i);
        lower *= (k - i);
    }
    return upper / lower;
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