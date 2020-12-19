#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#define pii pair<int, int>

using namespace std;

bool cmp(pii p1, pii p2)
{
    if (p1.first < p2.first)
    {
        return true;
    }
    return false;
}

int main(void)
{
    int length, result, start, end, temp;
    scanf("%d", &length);

    vector<pii> line(length);
    for (int i = 0; i < length; i++)
    {
        scanf("%d %d", &line[i].first, &line[i].second);
    }
    sort(line.begin(), line.end(), cmp);

    result = 0;
    start = line[0].first;
    end = line[0].second;

    for (int i = 1; i < length; i++)
    {
        if (line[i].first <= end)
        {
            end = max(line[i].second, end);
        }
        else
        {
            result += (end - start);
            start = line[i].first;
            end = line[i].second;
        }
    }
    result += (end - start);

    printf("%d\n", result);

    return 0;
}