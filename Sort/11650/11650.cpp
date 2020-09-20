#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct __point
{
    int xpos;
    int ypos;
} Point;

bool Compare(Point &p1, Point &p2)
{
    if (p1.xpos == p2.xpos)
    {
        if (p1.ypos < p2.ypos)
            return true;
        return false;
    }
    else if (p1.xpos < p2.xpos)
    {
        return true;
    }
    return false;
}

void print_vector(vector<Point> &ref)
{
    for (int i = 0; i < ref.size(); i++)
    {
        cout << ref[i].xpos << " " << ref[i].ypos << '\n';
    }
    return;
}

int main(void)
{
    vector<Point> arr;
    int xpos, ypos, num;
    Point temp = {0, 0};
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> temp.xpos >> temp.ypos;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end(), Compare);
    print_vector(arr);

    return 0;
}