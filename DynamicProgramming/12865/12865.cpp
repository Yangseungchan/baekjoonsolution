#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::vector;

class ValueDP
{
private:
    int length;
    int max_weight;
    vector<int> weight;
    vector<int> value;
    vector<vector<int>> dp;

public:
    ValueDP(int len, int max_w) : length(len), max_weight(max_w)
    {
        weight.assign(len + 1, 0);                             // index : 1~length
        value.assign(len + 1, 0);                              // index : 1~length
        dp.assign(length + 1, vector<int>(max_weight + 1, 0)); // index : [0][0] ~ [length][max_weight]
    }

    void ScanData()
    {
        for (int i = 1; i <= length; i++)
        {
            cin >> weight[i] >> value[i];
        }
    }

    void MaximumVal()
    {
        for (int n = 1; n <= length; n++) // n = 물건의 개수(번호)
        {
            for (int m = 0; m <= max_weight; m++) // m = 한계 무게
            {
                if (weight[n] > m)
                {
                    dp[n][m] = dp[n - 1][m];
                }
                else
                {
                    dp[n][m] = max(dp[n - 1][m], value[n] + dp[n - 1][m - weight[n]]);
                }
            }
        }
        cout << dp[length][max_weight] << endl;
    }
};

int main(void)
{
    int num;
    int max_weight;

    cin >> num >> max_weight;
    ValueDP vdp(num, max_weight);
    vdp.ScanData();
    vdp.MaximumVal();

    return 0;
}