#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

#define pii pair<int, int>
// first = index, second = value

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int size;

    vector<int> value;
    vector<int> nge;
    stack<pii> stk;

    cin >> size;

    value = vector<int>(size);
    nge = vector<int>(size);

    for (int i = 0; i < size; i++)
    {
        cin >> value[i];
    }

    for (int i = 0; i < size - 1; i++)
    {
        while (!stk.empty())
        {
            if (stk.top().second < value[i + 1])
            {
                nge[stk.top().first] = value[i + 1];
                stk.pop();
            }
            else
            {
                break;
            }
        }
        if (value[i] < value[i + 1])
        {
            nge[i] = value[i + 1];
        }
        else
        {
            stk.push(pii(i, value[i]));
        }
    }
    nge[size - 1] = -1;

    while (!stk.empty())
    {
        pii temp = stk.top();
        stk.pop();
        nge[temp.first] = -1;
    }

    for (int i = 0; i < size; i++)
    {
        cout << nge[i] << ' ';
    }
    cout << '\n';

    return 0;
}