#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    stack<bool> stk;
    string input_data;

    int cnt;
    bool result_flag;
    cin >> cnt;

    for (int i = 0; i < cnt; i++)
    {
        result_flag = true;
        cin >> input_data;
        for (int j = 0; j < input_data.length(); j++)
        {
            if (input_data[j] == '(')
            {
                stk.push(true);
            }
            else
            {
                if (stk.empty())
                {
                    result_flag = false;
                    break;
                }
                else
                {
                    stk.pop();
                }
            }
        }
        if (result_flag == false || !stk.empty())
        {
            cout << "NO" << '\n';
        }
        else
        {
            cout << "YES" << '\n';
        }
        while (!stk.empty())
        {
            stk.pop();
        }
    }

    return 0;
}