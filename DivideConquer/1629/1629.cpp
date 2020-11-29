#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    long long multiply, result, number, multi_cnt, rest_idx;
    cin >> number >> multi_cnt >> rest_idx;

    result = 1;
    multiply = number;
    while (multi_cnt > 0)
    {
        if (multi_cnt % 2 != 0)
        {
            result = (result % rest_idx) * (multiply % rest_idx) % rest_idx;
        }
        multiply = (multiply % rest_idx) * (multiply % rest_idx) % rest_idx;
        multi_cnt /= 2;
    }
    cout << result << '\n';
}