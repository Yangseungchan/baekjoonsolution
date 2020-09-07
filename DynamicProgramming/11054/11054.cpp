#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::vector;

class BiotonicSeq
{
private:
    int length;
    vector<int> data;
    vector<vector<int>> dp;
    int result;

public:
    BiotonicSeq(int len) : length(len), result(0)
    {
        data.assign(len, 0);
        dp.assign(length, vector<int>(length, 1));
    }

    void ScanData()
    {
        for (int i = 0; i < length; i++)
        {
            cin >> data[i];
        }
        return;
    }

    void FindBitonic()
    {
        int total;
        int left_total, right_total;
        int left_max, right_max;
        for (int i = 0; i < length; i++) // 범위 기준 변화를 위한 반복문
        {
            left_total = right_total = 1;
            for (int left = 1; left <= i; left++) // data[i]의 좌측 배열의 LIS 계산
            {
                left_max = 0;
                for (int l = 0; l < left; l++)
                {
                    if (data[l] < data[left])
                    {
                        if (left_max < dp[i][l])
                            left_max = dp[i][l];
                    }
                }
                dp[i][left] = left_max + 1;
                if (dp[i][left] > left_total)
                    left_total = dp[i][left];
            }
            for (int right = length - 2; right >= i; right--) // data[i]의 우측 배열의 LIS 계산
            {
                right_max = 0;
                for (int r = length - 1; r > right; r--)
                {
                    if (data[r] < data[right])
                    {
                        if (right_max < dp[i][r])
                            right_max = dp[i][r];
                    }
                }
                dp[i][right] = right_max + 1;
                if (dp[i][right] > right_total)
                    right_total = dp[i][right];
            }
            if (left_total == 0 || right_total == 0) // data[i] 기준 좌측, 우측 LIS의 합 구하기
            {
                total = left_total + right_total;
            }
            else
            {
                total = left_total + right_total - 1;
            }

            if (result < total) // 최종 결과값에 반영하기
                result = total;
        }
        return;
    }

    int &RetResult()
    {
        return result;
    }
};

int main(void)
{
    int num;
    cin >> num;

    BiotonicSeq BtcSeq(num);

    BtcSeq.ScanData();
    BtcSeq.FindBitonic();

    cout << BtcSeq.RetResult() << endl;

    return 0;
}