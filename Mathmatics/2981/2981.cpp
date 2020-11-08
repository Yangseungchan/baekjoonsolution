#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    if (a < b)
    {
        return gcd(b, a);
    }
    else
    {
        return gcd(b, a % b);
    }
}

void collect_factor(vector<int> &arr, int num)
{
    arr.push_back(num);
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            arr.push_back(i);
            if (num / i != i)
            {
                arr.push_back(num / i);
            }
        }
    }
    sort(arr.begin(), arr.end());
    for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++)
    {
        cout << *it << ' ';
    }
    cout << '\n';
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int num, diff_gcd;
    cin >> num;
    vector<int> number;
    vector<int> differ;
    vector<int> factor;

    number.assign(num, 0);
    differ.assign(num - 1, 0);

    for (int i = 0; i < num; i++)
    {
        cin >> number[i];
    }

    sort(number.begin(), number.end());

    for (int j = 0; j < num - 1; j++)
    {
        differ[j] = number[j + 1] - number[j];
    }

    if (num > 2)
    {
        diff_gcd = gcd(differ[1], differ[0]);
        for (int j = 2; j < num - 1; j++)
        {
            diff_gcd = gcd(differ[j], diff_gcd);
        }
    }
    else
    {
        diff_gcd = differ[0];
    }
    collect_factor(factor, diff_gcd);

    return 0;
}