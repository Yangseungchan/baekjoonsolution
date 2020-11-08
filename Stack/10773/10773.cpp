#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    stack<int> stk;
    int cnt, number;
    long long result;
    cin >> cnt;

    for(int i=0; i<cnt; i++)
    {
        cin >> number;
        if(number == 0)
        {
            if(stk.empty())
            {
                stk.push(number);
            }
            else
            {
                stk.pop();
            }
        }
        else
        {
            stk.push(number);
        }
    }
    result = 0;
    while(!stk.empty())
    {
        result += stk.top();
        stk.pop();
    }

    cout << result << '\n';
    return 0;
}