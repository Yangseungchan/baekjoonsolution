#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::vector;

class Division
{
private:
    vector<int> cal_num;
    int max;

public:
    Division(int num) : max(num)
    {
        cal_num.assign(num + 1, 0);
        cal_num[1] = 0;
    }

    void FindMin()
    {
        for (int i = 2; i <= max; i++)
        {
            if (i % 2 == 0 || i % 3 == 0)
            {
                if (i % 2 != 0) // 3으로만 나누어 떨어지는 경우
                {
                    cal_num[i] = min(cal_num[i / 3], cal_num[i - 1]) + 1;
                }
                else if (i % 3 != 0) // 2로만 나누어 떨어지는 경우
                {
                    cal_num[i] = min(cal_num[i / 2], cal_num[i - 1]) + 1;
                }
                else // 2,3으로 둘다 나누어 떨어지는 경우
                {
                    cal_num[i] = min(min(cal_num[i / 2], cal_num[i / 3]), cal_num[i - 1]) + 1;
                }
            }
            else // 2, 3 모두 나누어 떨어지지 않는 경우
            {
                cal_num[i] = cal_num[i - 1] + 1;
            }
        }
        return;
    }

    int &operator[](int index)
    {
        if (index <= 0 || index > max)
        {
            exit(1);
        }
        return cal_num[index];
    }
};

int main(void)
{
    int num;
    cin >> num;

    Division div(num);

    div.FindMin();

    cout << div[num] << endl;

    return 0;
}
