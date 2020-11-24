#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(void)
{
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    queue<int> que;
    int num, top;
    cin >> num;

    for (int i = 1; i <= num; i++)
    {
        que.push(i);
    }
    while (que.size() > 1)
    {
        que.pop(); // #1
        top = que.front();
        que.pop();     //#2
        que.push(top); //#3
    }

    cout << que.front() << '\n';

    return 0;
}