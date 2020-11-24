#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string cmd;
    queue<int> que;
    int cmd_num, target;
    cin >> cmd_num;

    for (int i = 0; i < cmd_num; i++)
    {
        cin >> cmd;
        if (!cmd.compare("push"))
        {
            cin >> target;
            que.push(target);
        }
        else if (!cmd.compare("pop"))
        {
            if (!que.empty())
            {
                target = que.front();
                que.pop();
            }
            else
            {
                target = -1;
            }
            cout << target << '\n';
        }
        else if (!cmd.compare("size"))
        {
            cout << que.size() << '\n';
        }
        else if (!cmd.compare("empty"))
        {
            if (que.empty())
            {
                target = 1;
            }
            else
            {
                target = 0;
            }
            cout << target << '\n';
        }
        else if (!cmd.compare("front"))
        {
            if (!que.empty())
            {
                target = que.front();
            }
            else
            {
                target = -1;
            }
            cout << target << '\n';
        }
        else if (!cmd.compare("back"))
        {
            if (!que.empty())
            {
                target = que.back();
            }
            else
            {
                target = -1;
            }
            cout << target << '\n';
        }
    }

    return 0;
}