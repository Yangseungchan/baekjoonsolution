#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int i, num;
    cin >> num;
    for (i = 2; i * i <= num; i++)
    {
        while (num % i == 0)
        {
            num /= i;
            cout << i << '\n';
        }
    }

    if (num > 1)
    {
        cout << num << '\n';
    }
    return 0;
}