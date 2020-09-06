#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::vector;

class Increase
{
private:
    vector<int> data;
    vector<int> dp;
    int length;    // 수열의 길이
    int total_max; // dp의 최종 최댓값

public:
    Increase(int len) : length(len), total_max(1)
    {
        data.assign(length, 0);
        dp.assign(length, 1);
    }

    void ScanData()
    {
        for (int i = 0; i < length; i++)
        {
            cin >> data[i];
        }
    }

    void TrackDP()
    {
        int max;
        for (int i = 1; i < length; i++)
        {
            max = 0;
            for (int j = 0; j < i; j++)
            {
                if (data[j] < data[i])
                {
                    if (max < dp[j])
                        max = dp[j];
                }
            }
            dp[i] = max + 1;
            if (dp[i] > total_max)
                total_max = dp[i];
        }
        return;
    }

    void PrintDP()
    {
        for (int i = 0; i < length; i++)
        {
            cout << dp[i] << " ";
        }
    }

    int &retMax()
    {
        return total_max;
    }
};

int main(void)
{
    int num;
    cin >> num;

    Increase sequence(num);
    sequence.ScanData();

    sequence.TrackDP();

    cout << sequence.retMax() << endl;
    //sequence.PrintDP();
    return 0;
}