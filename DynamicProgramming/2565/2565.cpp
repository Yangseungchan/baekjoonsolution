#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::max_element;
using std::swap;
using std::vector;

class ElecLine
{
private:
    vector<int> PosA;
    vector<int> PosB;
    vector<int> dp;
    int length;
    int total_max;

public:
    ElecLine(int len) : length(len), total_max(0)
    {
        PosA.assign(len, 0);
        PosB.assign(len, 0);
        dp.assign(len, 0);
    }

    void ScanData()
    {
        for (int i = 0; i < length; i++)
        {
            cin >> PosA[i] >> PosB[i];
        }
    }

    void SortData()
    {
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < length - 1 - i; j++)
            {
                if (PosA[j] > PosA[j + 1])
                {
                    swap(PosA[j], PosA[j + 1]);
                    swap(PosB[j], PosB[j + 1]);
                }
            }
        }
    }

    void PrintData()
    {
        for (int i = 0; i < length; i++)
        {
            cout << PosA[i] << ", " << PosB[i] << endl;
        }
    }

    void FindIncLine()
    {
        int max;
        dp[0] = 1;
        for (int i = 1; i <= length - 1; i++) // 기준점 : PosA[i], PosB[i]
        {
            max = 0;
            for (int j = 0; j < i; j++) // 기준점 이전 전깃줄들 탐색
            {
                if (PosA[j] < PosA[i] && PosB[j] < PosB[i]) // 증가하는 수열 조건
                {
                    // dp[j] = j번째까지의 전깃줄이 주어졌을때 교차하지않게 놓을 수 있는 최대개수(LIS를 충족할 수 있는 전깃줄의 개수)
                    if (max < dp[j]) //dp[i]번째 값을 구하기 위해, i번째 이전 전깃줄로 만들 수 있는 최대개수(max) 찾기
                    {
                        max = dp[j];
                    }
                }
            }
            dp[i] = max + 1;
        }
        total_max = *max_element(dp.begin(), dp.end());
    }

    int RetResult()
    {
        return total_max;
    }
};

int main(void)
{
    int num;
    cin >> num;

    ElecLine elc(num);

    elc.ScanData();
    elc.SortData();
    //elc.PrintData();
    elc.FindIncLine();

    cout << num - elc.RetResult() << endl;
    return 0;
}