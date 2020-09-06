#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::vector;

class MaxWine
{
private:
    vector<vector<int>> wine;
    /* 
        wine[0][i] = reach ith winecup from i-1th winecup 
        wine[1][i] = reach ith winecup from 0 to i-2th winecup
        wine[2][i] = max value between wine[0][i], wine[1][i]
     */
    int length;

public:
    MaxWine(int len) : length(len)
    {
        wine.assign(3, vector<int>(len, 0));
    }

    void ReadInput()
    {
        for (int i = 0; i < length; i++)
        {
            cin >> wine[0][i];
            wine[1][i] = wine[0][i];
        }
    }

    int SubMax(int end)
    {
        int max = wine[2][0];
        for (int i = 1; i <= end; i++)
        {
            if (max < wine[2][i])
            {
                max = wine[2][i];
            }
        }
        return max;
    }

    void FindMax() // max can be positioned at wine[length-1], wine[length-2]
    {
        wine[2][0] = wine[0][0]; // set max of 0th wine
        wine[0][1] += wine[0][0];
        wine[2][1] = max(wine[0][1], wine[1][1]); // set submax until 1st wine

        for (int i = 2; i < length; i++)
        {
            wine[0][i] += wine[1][i - 1];
            wine[1][i] += SubMax(i - 2);
            wine[2][i] = max(wine[0][i], wine[1][i]);
        }
        return;
    }

    int retMax()
    {
        int maximum = wine[0][length - 1] > wine[1][length - 1] ? wine[0][length - 1] : wine[1][length - 1];
        return max(maximum, wine[0][length - 2]);
    }

    void PrintWineTable()
    {
        cout << "**********" << endl;
        for (int i = 0; i < length; i++)
        {
            cout << wine[0][i] << " " << wine[1][i] << " " << wine[2][i] << endl;
        }
        cout << "**********" << endl;
    }
};

int main(void)
{
    int num;
    cin >> num;
    MaxWine maxw(num);
    maxw.ReadInput();

    maxw.FindMax();
    cout << maxw.retMax() << endl;

    //maxw.PrintWineTable();

    return 0;
}
