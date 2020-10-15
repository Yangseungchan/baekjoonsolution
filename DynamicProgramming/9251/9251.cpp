#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class LCS
{
private:
    string str1;
    string str2;
    vector<vector<int>> dp;
    int len1;
    int len2;

public:
    LCS() {}
    void readstr()
    {
        cin >> str1;
        cin >> str2;
        len1 = str1.length();
        len2 = str2.length();
        dp.assign(len1 + 1, vector<int>(len2 + 1, 0));
    }

    void findLCS()
    {
        for (int i = 0; i <= len1; i++)
        {
            for (int j = 0; j <= len2; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
    }

    /*void findLCS2() // 2차원 배열이 아닌 1차원 배열 2개로 해결하기
    {
        int i;
        vector<int> dp1 = vector<int>(len2 + 1, 0);
        vector<int> dp2 = vector<int>(len2 + 1, 0);
        for (i = 0; i <= len1; i++)
        {
            if (i % 2 == 0)
            {
                for (int j = 0; j <= len2; j++)
                {
                    if (j == 0)
                    {
                        dp1[j] = 0;
                    }
                    else if (str1[i - 1] == str2[j - 1])
                    {
                        dp1[j] = dp2[j - 1] + 1;
                    }
                    else
                    {
                        dp1[j] = max(dp1[j - 1], dp2[j]);
                    }
                }
            }
            else
            {
                for (int j = 0; j <= len2; j++)
                {
                    if (j == 0)
                    {
                        dp2[j] = 0;
                    }
                    else if (str1[i - 1] == str2[j - 1])
                    {
                        dp2[j] = dp1[j - 1] + 1;
                    }
                    else
                    {
                        dp2[j] = max(dp2[j - 1], dp1[j]);
                    }
                }
            }
        }

        if (i % 2 == 0)
        {
            cout << dp2[len2] << '\n';
        }
        else
        {
            cout << dp1[len2] << '\n';
        }
    }
    */

    int &result()
    {
        return dp[len1][len2];
    }
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LCS lcseq;

    lcseq.readstr();
    lcseq.findLCS();
    cout << lcseq.result() << '\n';

    /*lcseq.findLCS2();*/

    return 0;
}