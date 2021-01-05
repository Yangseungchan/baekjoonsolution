#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> length;

long long find_max_length(int K, int N)
{
    long long count;
    long long start = 1;
    long long end = length[K - 1];
    long long mid;
    while (start <= end)
    {
        count = 0;
        mid = (end + start) / 2;
        for (int i = 0; i < K; i++)
        {
            count += (length[i] / mid);
        }
        if (count < N)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return end;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K, N; // K = 가지고 있는 랜선의 개수, N = 필요한 랜선의 개수
    cin >> K >> N;
    length = vector<int>(K);
    for (int i = 0; i < K; i++)
    {
        cin >> length[i];
    }
    sort(length.begin(), length.end());
    cout << find_max_length(K, N) << '\n';
    return 0;
}