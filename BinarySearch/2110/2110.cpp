#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, C;

    cin >> N >> C;
    vector<int> home = vector<int>(N);

    for (int i = 0; i < N; i++)
    {
        cin >> home[i];
    }
    sort(home.begin(), home.end());

    int left = 1;                      // 최소 거리값
    int right = home[N - 1] - home[0]; // 최대 거리값
    int cnt, mid, prev, result;        // mid = 중간 거리값

    result = 1;
    while (left <= right)
    {
        cnt = 1;
        mid = (left + right) / 2;
        prev = 0;
        for (int i = 1; i < N; i++)
        {
            if (home[i] - home[prev] >= mid)
            {
                cnt++;
                prev = i;
            }
        }
        if (cnt >= C) // 개수가 더 많다 => 가능한 길이를 늘린다
        {
            result = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << result << '\n';
    return 0;
}