#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::vector;

class MinPaint
{
private:
    vector<int> red;
    vector<int> blue;
    vector<int> green;
    int length;
    int index;

public:
    MinPaint(int len) : length(len), index(1)
    {
        red.assign(len + 1, 0); // idx = 1 ~ 100까지 사용
        blue.assign(len + 1, 0);
        green.assign(len + 1, 0);
    }

    void ScanCost()
    {
        cin >> red[index] >> blue[index] >> green[index++];
        //100개를 입력받는다면 index는 최종적으로 101이 된다.
    }

    int FindMin()
    {
        for (int i = 2; i <= index - 1; i++)
        {
            red[i] += min(blue[i - 1], green[i - 1]);
            blue[i] += min(red[i - 1], green[i - 1]);
            green[i] += min(red[i - 1], blue[i - 1]);
        }
        return min(green[index - 1], min(red[index - 1], blue[index - 1])); // index = 101이므로 결과값 100인 index-1을 리턴
    }
};

int main(void)
{
    int length;
    cin >> length;

    MinPaint MinP(length);
    for (int i = 0; i < length; i++)
        MinP.ScanCost();

    cout << MinP.FindMin() << endl;
    return 0;
}