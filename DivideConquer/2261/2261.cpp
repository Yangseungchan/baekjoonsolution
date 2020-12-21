#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> Point;

bool comp_x(Point p1, Point p2)
{
    if (p1.first < p2.first)
        return true;
    return false;
}

bool comp_y(Point p1, Point p2)
{
    if (p1.second < p2.second)
        return true;
    return false;
}

int dist(Point p1, Point p2)
{
    return (p2.first - p1.first) * (p2.first - p1.first) + (p2.second - p1.second) * (p2.second - p1.second);
}

int find_dist_new(vector<Point>::iterator it, int n)
{
    if (n == 2)
        return dist(it[0], it[1]);
    else if (n == 3)
        return min({dist(it[0], it[1]), dist(it[0], it[2]), dist(it[1], it[2])});

    int min_dist = min(find_dist_new(it, n / 2), find_dist_new(it + n / 2, n - n / 2));
    int std_line = (it[n / 2].first + it[n / 2 + 1].first) / 2;
    vector<Point> comp_point;
    for (int i = 0; i < n; i++)
    {
        int __dist = (std_line - it[i].first);
        if (__dist * __dist < min_dist)
            comp_point.push_back(it[i]);
    }
    int comp_sz = comp_point.size();
    sort(comp_point.begin(), comp_point.end(), comp_y);
    for (int i = 0; i < comp_sz; i++)
    {
        for (int j = i + 1; j < comp_sz && (comp_point[j].second - comp_point[i].second) * (comp_point[j].second - comp_point[i].second) < min_dist; j++)
        {
            min_dist = min(min_dist, dist(comp_point[i], comp_point[j]));
        }
    }
    return min_dist;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;
    vector<Point> dots(num); // first = x, second = y
    for (int i = 0; i < num; i++)
    {
        cin >> dots[i].first >> dots[i].second;
    }
    sort(dots.begin(), dots.end(), comp_x);
    cout << find_dist_new(dots.begin(), num) << '\n';
    return 0;
}