#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#define LIMIT_MIN -100001
#define LIMIT_MAX 100001

using namespace std;

typedef struct _point
{
    int x, y;
    _point() {}
    _point(int n1, int n2) : x(n1), y(n2) {}
    bool operator<(const _point &p) const
    {
        if (y == p.y)
        {
            return x < p.x;
        }
        else
        {
            return y < p.y;
        }
    }

} Point;

int dist(Point p1, Point p2) // return distance x distance from p1 to p2
{
    return (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y);
}

bool cmpx(Point p1, Point p2)
{
    return p1.x < p2.x;
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int number;
    cin >> number;

    vector<Point> pos(number);
    for (int i = 0; i < number; i++)
    {
        cin >> pos[i].x >> pos[i].y;
    }
    sort(pos.begin(), pos.end(), cmpx);

    int ans = dist(pos[0], pos[1]);
    int start = 0;
    set<Point> candidate = {pos[0], pos[1]};
    // candidate에 담기는 것 : i=n일때 최대 0부터 n-1까지의 pos들
    for (int i = 2; i < number; i++)
    {
        Point now = pos[i];
        while (start < i)
        {
            auto p = pos[start];
            int x = p.x - now.x;
            if (x * x > ans)
            {
                candidate.erase(p);
                start++;
            }
            else
            {
                break;
            }
        }
        int d = (int)(sqrt((double)ans) + 1);
        auto low_point = Point(LIMIT_MIN, now.y - d);
        auto upper_point = Point(LIMIT_MAX, now.y + d);
        auto lower = lower_bound(candidate.begin(), candidate.end(), low_point);
        auto upper = upper_bound(candidate.begin(), candidate.end(), upper_point);
        for (auto it = lower; it != upper; it++)
        {
            int d = dist(now, *it);
            if (ans > d)
            {
                ans = d;
            }
        }
        candidate.insert(now);
    }

    cout << ans << '\n';

    return 0;
}