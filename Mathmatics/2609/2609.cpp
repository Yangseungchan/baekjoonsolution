#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void find_factor(int num, vector<int> &arr, int &max)
{
    int i;
    for (i = 2; i * i <= num; i++)
    {
        while (num % i == 0)
        {
            num /= i;
            arr[i] += 1;
            if (max < i)
                max = i;
        }
    }
    if (num > 1)
    {
        arr[num] += 1;
        if (max < num)
            max = num;
    }
}

void print_factor(vector<int> &arr)
{
    for (int i = 2; i < arr.size(); i++)
    {
        if (arr[i] > 0)
        {
            cout << i << " : " << arr[i] << '\n';
        }
    }
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> arr1;
    vector<int> arr2;

    int num1, num2, max1, max2, min_max, gcd, lcm;
    cin >> num1 >> num2;

    arr1.assign(num1 + 1, 0);
    arr2.assign(num2 + 1, 0);

    max1 = max2 = 0;
    find_factor(num1, arr1, max1);
    find_factor(num2, arr2, max2);
    min_max = max(max1, max2);

    gcd = lcm = 1;
    for (int i = 2; i <= min_max; i++)
    {
        if (arr1[i] > 0 || arr2[i] > 0)
        {
            gcd *= (int)pow(i, min(arr1[i], arr2[i]));
            lcm *= (int)pow(i, max(arr1[i], arr2[i]));
        }
    }
    cout << gcd << '\n';
    cout << lcm << '\n';

    return 0;
}