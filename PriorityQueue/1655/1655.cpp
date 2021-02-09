#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct mycmp
{
    bool reverse;
    mycmp(bool revparm = false)
    {
        reverse = revparm;
    }
    bool operator()(const int &n1, const int &n2)
    {
        if (reverse)
        {
            return n1 > n2; // min heap
        }
        else
        {
            return n1 < n2; // max heap
        }
    }
};

typedef priority_queue<int, vector<int>, mycmp> int_pq;

// max-heap의 개수를 M, min-heap의 개수를 m이라 가정

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int_pq left_pq(mycmp(false)); // mid보다 작은 숫자들을 담는 힙
    int_pq right_pq(mycmp(true)); // mid보다 큰 숫자들을 담는 힙

    int N, input, mid;

    cin >> N;
    cin >> input;
    mid = input;
    cout << mid << '\n';
    for (int i = 2; i <= N; i++)
    {
        cin >> input;
        if (mid < input)
        {
            right_pq.push(input);
        }
        else
        {
            left_pq.push(input);
        }

        int left_size = left_pq.size();
        int right_size = right_pq.size();

        if (i % 2 == 0) // M = m -1
        {
            if (left_size != right_size - 1)
            {
                if (left_size < right_size - 1)
                {
                    left_pq.push(mid);
                    mid = right_pq.top();
                    right_pq.pop();
                }
                else
                {
                    right_pq.push(mid);
                    mid = left_pq.top();
                    left_pq.pop();
                }
            }
        }
        else // M = m
        {
            if (left_pq.size() != right_pq.size())
            {
                if (left_size < right_size)
                {
                    left_pq.push(mid);
                    mid = right_pq.top();
                    right_pq.pop();
                }
                else
                {
                    right_pq.push(mid);
                    mid = left_pq.top();
                    left_pq.pop();
                }
            }
        }
        cout << mid << '\n';
    }
    return 0;
}