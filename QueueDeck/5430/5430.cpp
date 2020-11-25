#include <iostream>
#include <string>
#include <string.h>
#include <deque>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    char *token;
    char arr_str[700000];
    string func_str;
    deque<int> my_deq;
    int index, test_case, arr_length, error_flag, r_cnt;
    cin >> test_case;

    for (int i = 0; i < test_case; i++)
    {
        cin >> func_str;
        cin >> arr_length;
        cin >> arr_str;
        r_cnt = 0;
        if (arr_length != 0)
        {
            token = strtok(arr_str, "[,]");
            if (token != NULL)
            {
                if (strcmp(token, "\n"))
                {
                    my_deq.push_back(atoi(token));
                }
            }
            while (token != NULL)
            {
                token = strtok(NULL, "[,]");
                if (token != NULL)
                {
                    if (strcmp(token, "\n"))
                    {
                        my_deq.push_back(atoi(token));
                    }
                }
            }
        }
        for (int j = 0; j < func_str.length(); j++) //입력받은 함수 명령 수행
        {
            error_flag = 0;
            if (func_str[j] == 'R') // R = 배열 뒤집기 -> 실제로 뒤집지 말고 r의 개수를 카운팅해서 논리적으로 접근 -> 홀수면 pop_back, 짝수면 pop_front
            {
                r_cnt++;
            }
            else // D = 첫번째 숫자 버리기
            {
                if (my_deq.empty())
                {
                    error_flag = -1;
                    break;
                }
                else
                {
                    if (r_cnt % 2 == 0)
                    {
                        my_deq.pop_front();
                    }
                    else
                    {
                        my_deq.pop_back();
                    }
                }
            }
        }
        if (error_flag == -1)
        {
            cout << "error\n";
        }
        else
        {
            cout << '[';
            if (!my_deq.empty())
            {
                if (r_cnt > 0 && r_cnt % 2 != 0)
                {
                    for (index = my_deq.size() - 1; index > 0; index--)
                    {
                        cout << my_deq[index] << ',';
                    }
                }
                else
                {
                    for (index = 0; index < my_deq.size() - 1; index++)
                    {
                        cout << my_deq[index] << ',';
                    }
                }
                cout << my_deq[index] << "]\n";
            }
            else
            {

                cout << "]\n";
            }
        }
        my_deq.clear();
        func_str.clear();
    }
    return 0;
}
