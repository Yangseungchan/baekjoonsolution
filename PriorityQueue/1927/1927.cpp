#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct mycmp
{
    bool operator()(const int &n1, const int &n2)
    {
        return n1 > n2;
    }
};

typedef priority_queue<int, vector<int>, mycmp> int_pq;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int_pq pq;
    // int_pq pq(mycmp(true));
    int N, input, result;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        if (input == 0)
        {
            if (pq.empty())
                result = 0;
            else
            {
                result = pq.top();
                pq.pop();
            }
            cout << result << '\n';
        }
        else
        {
            pq.push(input);
        }
    }
    return 0;
}