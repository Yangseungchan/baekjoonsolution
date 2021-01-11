#include <iostream>

using namespace std;

int gcd(int n1, int n2)
{
    if (n2 == 0)
    {
        return n1;
    }
    return gcd(n2, n1 % n2);
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int size;
    int n1, n2, temp;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cin >> n1 >> n2;
        temp = (n1 > n2 ? gcd(n1, n2) : gcd(n2, n1));
        cout << n1 * n2 / temp << '\n';
    }
    return 0;
}