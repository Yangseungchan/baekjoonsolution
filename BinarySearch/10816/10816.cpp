#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

#define MIN -10000001

using namespace std;

typedef pair<int, int> pii; //

vector<int> sample_card;
vector<pii> sample_pair;
vector<int> find_card;

int find_by_bsearch(int find, int n) // n = size of sample vector
{
    int start = 0;
    int end = n - 1;
    if (find < sample_pair[start].first)
        return 0;
    if (find > sample_pair[end].first)
        return 0;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (sample_pair[mid].first == find)
            return sample_pair[mid].second;
        else if (sample_pair[mid].first < find)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return 0;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, temp, count;
    cin >> N;
    sample_card = vector<int>(N);
    for (int i = 0; i < N; i++)
    {
        cin >> sample_card[i];
    }
    sort(sample_card.begin(), sample_card.end());

    temp = MIN;
    count = 0;
    for (int i = 0; i < N; i++)
    {
        if (temp == sample_card[i])
        {
            count++;
            continue;
        }
        else
        {
            if (temp != MIN)
                sample_pair.push_back(pii(temp, count));
            temp = sample_card[i];
            count = 1;
        }
    }
    sample_pair.push_back(pii(temp, count));

    cin >> M;
    find_card = vector<int>(M);
    for (int i = 0; i < M; i++)
    {
        cin >> find_card[i];
    }
    for (int i = 0; i < M; i++)
    {
        cout << find_by_bsearch(find_card[i], sample_pair.size()) << ' ';
    }
    cout << '\n';

    return 0;
}