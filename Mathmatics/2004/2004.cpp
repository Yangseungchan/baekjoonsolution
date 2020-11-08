#include <iostream>
#include <algorithm>

using namespace std;

int find_two(int num)
{
    int count = 0;
    int tmp = num / 2;
    while (tmp > 0)
    {
        count += tmp;
        tmp /= 2;
    }
    return count;
}

int find_five(int num)
{
    int count = 0;
    int tmp = num / 5;
    while (tmp > 0)
    {
        count += tmp;
        tmp /= 5;
    }
    return count;
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int front, back, cnt_tw, cnt_fv;
    cin >> front >> back;
    cnt_tw = find_five(front) - (find_five(back) + find_five(front - back));
    cnt_fv = find_two(front) - (find_two(back) + find_two(front - back));
    cout << min(cnt_tw, cnt_fv) << '\n';

    return 0;
}