#include <iostream>
#include <vector>

#define MAX 100000001

using namespace std;

class Teammake
{
private:
    int length;
    int differ;
    int flag_idx;
    vector<vector<int>> table;
    vector<int> flag;

public:
    Teammake(int len) : length(len), differ(MAX), flag_idx(0)
    {
        table.assign(length, vector<int>(len, 0));
        flag.assign(length, 0);
    }

    void scandata()
    {
        int num;
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < length; j++)
            {
                cin >> table[i][j];
            }
        }
    }

    void find_mate(int start)
    {
        flag[start] = 1;
        flag_idx++;
        if (flag_idx >= length / 2)
        {
            getresult();
            flag[start] = 0;
            flag_idx--;
            return;
        }
        for (int i = start + 1; i < length; i++)
        {
            if (flag[i] != 1)
                find_mate(i);
        }
        flag[start] = 0;
        flag_idx--;
        return;
    }

    void getresult()
    {
        int result;
        int sum_A = 0;
        int sum_B = 0;
        int left, right;
        for (int i = 0; i < length; i++)
        {
            for (int j = i + 1; j < length; j++)
            {
                if (flag[i] && flag[j])
                {
                    sum_A += (table[i][j] + table[j][i]);
                }
                if (!flag[i] && !flag[j])
                {
                    sum_B += (table[i][j] + table[j][i]);
                }
            }
        }
        result = abs(sum_A - sum_B);
        if (differ > result)
            differ = result;
        return;
    }

    int &getdiffer()
    {
        return differ;
    }
};

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int length;
    cin >> length;

    Teammake team(length);
    team.scandata();
    for (int i = 0; i <= length / 2; i++)
    {
        team.find_mate(i);
    }
    cout << team.getdiffer() << '\n';

    return 0;
}