#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main(void)
{
    bool flag = true;
    int num, input, index_result, index_input;
    stack<int> num_stk;
    vector<int> result;
    vector<int> input_data;
    vector<char> push_pop_log;

    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> input;
        input_data.push_back(input);
    }
    result = input_data;
    sort(input_data.begin(), input_data.end());
    index_result = index_input = 0;

    while (index_input < input_data.size())
    {
        num_stk.push(input_data[index_input++]);
        push_pop_log.push_back('+');
        while (!num_stk.empty())
        {
            if (num_stk.top() == result[index_result])
            {
                num_stk.pop();
                push_pop_log.push_back('-');
                index_result++;
            }
            else
            {
                break;
            }
        }
    }
    while (!num_stk.empty())
    {
        if (num_stk.top() == result[index_result])
        {
            num_stk.pop();
            push_pop_log.push_back('-');
            index_result++;
        }
        else
        {
            flag = false;
            break;
        }
    }

    if (!flag)
    {
        cout << "NO\n";
    }
    else
    {
        for (int i = 0; i < push_pop_log.size(); i++)
        {
            cout << push_pop_log[i] << '\n';
        }
    }

    return 0;
}