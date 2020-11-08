#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    stack<int> stk;
    string tmp;

    int cmd_num, target;
    cin >> cmd_num;
    cin.get();

    //cout << "cmd_num : " << cmd_num << endl;
    for(int i=0; i<cmd_num; i++)
    {
        cin >> tmp;   
        if(tmp.compare("push") == 0)
        {
            cin >> target;
            stk.push(target);
        }
        else if(tmp.compare("pop") == 0)
        {
            if(stk.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << stk.top() << '\n';
                stk.pop();
            }
        }
        else if(tmp.compare("size") == 0)
        {
            cout << stk.size() << '\n';
        }
        else if(tmp.compare("empty")==0)
        {
            cout << stk.empty() << '\n';
        }
        else if(tmp.compare("top") == 0)
        {
            if(stk.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << stk.top() << '\n';
            }
            
        }
    }


    return 0;
}