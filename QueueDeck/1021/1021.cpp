#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main(void)
{
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int deq_size, num_length, number, target_idx, oper_cnt, target_idx_indeq;
    deque<int> my_deq;
    vector<int> target;

    cin >> deq_size >> num_length;
    for (int i = 0; i < num_length; i++)
    {
        cin >> number;
        target.push_back(number);
    }
    target_idx = oper_cnt = 0;
    for (int i = 1; i <= deq_size; i++)
    {
        my_deq.push_back(i);
    }

    while (target_idx < target.size())
    {
        if (target[target_idx] == my_deq.front())
        {
            my_deq.pop_front();
            target_idx++;
        }
        else
        {
            for (int i = 0; i < my_deq.size(); i++)
            {
                if (my_deq[i] == target[target_idx])
                {
                    target_idx_indeq = i;
                    break;
                }
            }
            if (target_idx_indeq >= my_deq.size() - target_idx_indeq)
            {
                my_deq.push_front(my_deq.back());
                my_deq.pop_back();
            }
            else
            {
                my_deq.push_back(my_deq.front());
                my_deq.pop_front();
            }
            oper_cnt++;
        }
    }
    cout << oper_cnt << '\n';
    return 0;
}