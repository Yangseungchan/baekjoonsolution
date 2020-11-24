#include <iostream>
#include <deque>
#include <utility>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.first <= p2.first)
    {
        return true;
    }
    return false;
}

int main(void)
{
    pair<int, int> temp_pair;
    int print_count, numofdocs, pos, target_pos, test_case, prty, max_prty;
    cin >> test_case;

    deque<pair<int, int>> prque; // (priority, index)

    for (int i = 0; i < test_case; i++)
    {
        cin >> numofdocs >> target_pos;
        for (int j = 0; j < numofdocs; j++)
        {
            cin >> prty;
            temp_pair = make_pair(prty, j);
            prque.push_back(temp_pair);
        }
        print_count = 0;
        do
        {
            prty = prque.front().first;
            max_prty = (max_element(prque.begin(), prque.end(), compare))->first;
            if (max_prty > prty)
            {
                prque.push_back(prque.front());
                prque.pop_front();
                pos = -1;
            }
            else
            {
                ++print_count;
                pos = prque.front().second;
                prque.pop_front();
            }

        } while (target_pos != pos);
        cout << print_count << '\n';
        while (!prque.empty())
        {
            prque.pop_front();
        }
    }

    return 0;
}