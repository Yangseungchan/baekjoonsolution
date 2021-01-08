#include <iostream>
#include <deque>
#include <string>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int result_idx = 0;

    string str1, str2;

    deque<int> result;

    cin >> str1 >> str2;

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int len1 = str1.length();
    int len2 = str2.length();
    int max_length = max(len1, len2);
    int min_length = min(len1, len2);
    int prev = 0;
    int sum, flag, n1, n2;

    if (len1 > len2)
        flag = 1;
    else if (len1 < len2)
        flag = 2;
    else
        flag = 0;

    for (int i = 0; i < max_length; i++)
    {
        if (i < len1)
            n1 = (int)str1[i] - 48;
        else
            n1 = 0;

        if (i < len2)
            n2 = (int)str2[i] - 48;
        else
            n2 = 0;
        sum = n1 + n2 + prev;

        result.push_front(sum % 10);
        prev = sum / 10;
    }
    if (prev > 0)
    {
        result.push_front(prev);
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
    }
    cout << '\n';

    /* 결과 뒤집어서 출력 */

    return 0;
}