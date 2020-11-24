#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string cmd;
    deque<int> my_deq;
    int cmd_num, target;
    cin >> cmd_num;

    for (int i = 0; i < cmd_num; i++)
    {
        cin >> cmd;
        if (!cmd.compare(0, 2, "pu"))
        {
            if (!cmd.compare(5, 1, "f"))
            {
                cin >> target;
                my_deq.push_front(target);
            }
            else
            {
                cin >> target;
                my_deq.push_back(target);
            }
        }
        else if (!cmd.compare(0, 2, "po"))
        {
            if (!cmd.compare(4, 1, "f"))
            {
                if (my_deq.empty())
                {
                    target = -1;
                }
                else
                {
                    target = my_deq.front();
                    my_deq.pop_front();
                }
            }
            else
            {
                if (my_deq.empty())
                {
                    target = -1;
                }
                else
                {
                    target = my_deq.back();
                    my_deq.pop_back();
                }
            }
            cout << target << '\n';
        }
        else if (!cmd.compare(0, 1, "s"))
        {
            target = my_deq.size();
            cout << target << '\n';
        }
        else if (!cmd.compare(0, 1, "e"))
        {
            if (my_deq.empty())
            {
                target = 1;
            }
            else
            {
                target = 0;
            }
            cout << target << '\n';
        }
        else if (!cmd.compare(0, 1, "f"))
        {
            if (my_deq.empty())
            {
                target = -1;
            }
            else
            {
                target = my_deq.front();
            }
            cout << target << '\n';
        }
        else if (!cmd.compare(0, 1, "b"))
        {
            if (my_deq.empty())
            {
                target = -1;
            }
            else
            {
                target = my_deq.back();
            }
            cout << target << '\n';
        }
    }
    return 0;
}