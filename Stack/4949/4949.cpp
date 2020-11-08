#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool check_end(string str)
{
    if (str[0] == '.' && str.length() == 1)
    {
        return true;
    }
    return false;
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    string sentence;
    stack<int> stk;
    bool flag;

    getline(cin, sentence);
    while (!check_end(sentence))
    {
        flag = true;
        for (int i = 0; i < sentence.length(); i++)
        {
            if (sentence[i] == '(')
            {
                stk.push(1);
            }
            else if (sentence[i] == ')')
            {
                if (!stk.empty())
                {
                    if (stk.top() == 1)
                    {
                        stk.pop();
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            else if (sentence[i] == '[')
            {
                stk.push(2);
            }
            else if (sentence[i] == ']')
            {
                if (!stk.empty())
                {
                    if (stk.top() == 2)
                    {
                        stk.pop();
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                else
                {
                    flag = false;
                    break;
                }
            }
        }
        if (!stk.empty()) /* 주어진 문장을 모두 확인했을때 stk이 비어있지 않은 경우 */
        {
            flag = false;
            while (!stk.empty()) /* 다음 문장으로 넘어가기 전 stack 비우기 */
            {
                stk.pop();
            }
        }
        if (!flag) /* flag = false 인 경우 */
        {
            cout << "no\n";
        }
        else
        {
            cout << "yes\n";
        }
        getline(cin, sentence);
    }

    return 0;
}