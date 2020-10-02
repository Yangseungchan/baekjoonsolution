#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define MAX 100000001
#define MIN -100000001

using namespace std;

class Calculator
{
private:
    vector<int> expression;
    int length;
    int plus;     // expression에서 1로 표시
    int minus;    // expression에서 2로 표시
    int multiply; // expression에서 3으로 표시
    int divide;   // expression에서 4로 표시
    int maximum;
    int minimum;

public:
    Calculator(int len) : length(len), plus(0), minus(0), multiply(0), divide(0), maximum(MIN), minimum(MAX)
    {
        expression.assign(2 * length - 1, 0);
    }

    void scanmember()
    {
        int target;
        for (int i = 0; i < length; i++)
        {
            cin >> target;
            expression[i * 2] = target;
        }
        cin >> plus >> minus >> multiply >> divide;
    }

    void findexp(int idx)
    {
        if (idx > length - 2)
        {
            getresult();
            return;
        }
        int pos = 2 * idx + 1;
        if (plus_check())
        {
            plus--;
            expression[pos] = 1;
            findexp(idx + 1);
            plus++;
        }
        if (minus_check())
        {
            minus--;
            expression[pos] = 2;
            findexp(idx + 1);
            minus++;
        }
        if (multi_check())
        {
            multiply--;
            expression[pos] = 3;
            findexp(idx + 1);
            multiply++;
        }
        if (divide_check())
        {
            divide--;
            expression[pos] = 4;
            findexp(idx + 1);
            divide++;
        }
        return;
    }

    void getresult()
    {
        int result, target1, target2, oper_pos;
        vector<int> temp = expression;
        for (int i = 0; i < length - 1; i++)
        {
            target1 = i * 2;
            target2 = (i + 1) * 2;
            oper_pos = i * 2 + 1;
            switch (temp[oper_pos])
            {
            case 1: // 덧셈
                result = temp[target1] + temp[target2];
                break;
            case 2: // 뺄셈
                result = temp[target1] - temp[target2];
                break;
            case 3: // 곱셈
                result = temp[target1] * temp[target2];
                break;
            case 4: // 나눗셈
                result = abs(temp[target1]) / abs(temp[target2]);
                if (temp[target1] > 0)
                {
                    if (temp[target2] < 0)
                        result *= -1;
                }
                if (temp[target1] < 0)
                {
                    if (temp[target2] > 0)
                        result *= -1;
                }
                break;
            }
            temp[target2] = result;
        }
        result = temp[target2];
        if (result > maximum)
            maximum = result;
        if (result < minimum)
            minimum = result;
        return;
    }

    bool plus_check()
    {
        return plus > 0 ? true : false;
    }

    bool minus_check()
    {
        return minus > 0 ? true : false;
    }

    bool multi_check()
    {
        return multiply > 0 ? true : false;
    }

    bool divide_check()
    {
        return divide > 0 ? true : false;
    }

    void print_result()
    {
        cout << maximum << '\n';
        cout << minimum << '\n';
    }
};

int main(void)
{
    int num;
    cin >> num;
    Calculator calculate(num);
    calculate.scanmember();
    calculate.findexp(0);
    calculate.print_result();

    return 0;
}