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
            cin >> score[i][0];
            score[i][1] = score[i][0];
        }
    }

    void FindMaxScore() // score[i][0] = i-1번째 계단으로 부터 올라온 경우 , score[i][1] = i-2번째 계단으로 부터 올라온 경우
    {
        score[1][0] += score[0][0];
        for (int i = 2; i < length; i++)
        {
            score[i][0] += score[i - 1][1];
            score[i][1] += max(score[i - 2][0], score[i - 2][1]);
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
    cout << "input num : ";
    cin >> num;

    Staircase stc(num);

    stc.ScanData();

    stc.FindMaxScore();

    cout << max(stc.ReturnRef(num - 1, 0), stc.ReturnRef(num - 1, 1));

    return 0;
}