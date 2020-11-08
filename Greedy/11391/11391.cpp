#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(int n1, int n2)
{
    return (n1 < n2);
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int total_sum, length;
    vector<int> time;
    vector<int> sum;

    cin >> length;
    time.assign(length, 0);
    sum.assign(length, 0);

    for (int i = 0; i < length; i++)
    {
        cin >> time[i];
    }

    sort(time.begin(), time.end(), cmp);

    sum[0] = time[0];
    total_sum = sum[0];
    for (int i = 1; i < length; i++)
    {
        sum[i] = sum[i - 1] + time[i];
        total_sum += sum[i];
    }

    cout << total_sum << '\n';

    return 0;
}
