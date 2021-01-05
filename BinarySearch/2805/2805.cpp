#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> length;

long long find_max_length(int N, int M)
{
    long long left = 1;
    long long right = length[N - 1];
    long long mid;
    long long sum;

    while (left <= right)
    {
        mid = (left + right) / 2;
        sum = 0;
        for (int i = 0; i < N; i++)
        {
            if (mid < length[i])
                sum += (length[i] - mid);
        }
        if (sum >= M)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return right;
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M; // N = 나무의 개수, M = 필요한 나무 길이(최소로 필요한 길이)
    cin >> N >> M;

    length = vector<int>(N);
    for (int i = 0; i < N; i++)
    {
        cin >> length[i];
    }
    sort(length.begin(), length.end());

    cout << find_max_length(N, M) << '\n';
    return 0;
}