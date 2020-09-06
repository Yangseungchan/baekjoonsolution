#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::vector;

class Staircase
{
private:
    vector<vector<int>> score; // score[i][0] = i-1번째 계단으로 부터 올라온 경우 , score[i][1] = i-2번째 계단으로 부터 올라온 경우
    int length;

public:
    Staircase(int len) : length(len)
    {
        score.assign(2, vector<int>(length, 0));
    }

    void ScanData()
    {
        for (int i = 0; i < length; i++)
        {
            cin >> score[0][i];
            score[1][i] = score[0][i];
        }
    }

    void FindMaxScore() // score[0][i] = i-1번째 계단으로 부터 올라온 경우 , score[1][i] = i-2번째 계단으로 부터 올라온 경우
    {
        score[0][1] += score[0][0];
        for (int i = 2; i < length; i++)
        {
            score[0][i] += score[1][i - 1];
            score[1][i] += max(score[0][i - 2], score[1][i - 2]);
        }
    }

    int &ReturnRef(int row, int col)
    {
        return score[row][col];
    }
};

int main(void)
{
    int num;
    cin >> num;

    Staircase stc(num);

    stc.ScanData();

    stc.FindMaxScore();

    cout << max(stc.ReturnRef(0, num - 1), stc.ReturnRef(1, num - 1));

    return 0;
}