#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::vector;

class Stairnum
{
private:
    vector<vector<unsigned long long>> count;
    int numcnt;

public:
    Stairnum(int num) : numcnt(num)
    {
        count.assign(numcnt, vector<unsigned long long>(10, 0));
        count[0][0] = 0;
        for (int i = 1; i <= 9; i++)
        {
            count[0][i] = 1;
        }
    }

    void CalCount()
    {
        for (int i = 1; i <= numcnt - 1; i++)
        {
            count[i][0] = count[i - 1][1] % 1000000000;
            for (int j = 1; j <= 8; j++)
            {
                count[i][j] = (count[i - 1][j - 1] + count[i - 1][j + 1]) % 1000000000;
            }
            count[i][9] = count[i - 1][8] % 1000000000;
        }
        return;
    }

    long long retResult()
    {
        unsigned long long sum = 0;
        for (int j = 0; j <= 9; j++)
        {
            sum += count[numcnt - 1][j] % 1000000000;
        }
        return sum;
    }
};

int main(void)
{
    int num;
    cin >> num;

    Stairnum stnum(num);
    stnum.CalCount();

    cout << stnum.retResult() % 1000000000 << endl;
    return 0;
}