#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void)
{
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int num_n, num_k, temp, i;
    queue<int> my_que;
    vector<int> result;
    cin >> num_n >> num_k;

    for (int i = 1; i <= num_n; i++)
    {
        my_que.push(i);
    }

    while (!my_que.empty())
    {
        for (i = 1; i < num_k; i++)
        {
            temp = my_que.front();
            my_que.pop();
            my_que.push(temp);
        }
        temp = my_que.front();
        my_que.pop();
        result.push_back(temp);
    }

    cout << '<';
    for (i = 0; i < result.size() - 1; i++)
    {
        cout << result[i] << ", ";
    }
    cout << result[i] << ">\n";

    return 0;
}