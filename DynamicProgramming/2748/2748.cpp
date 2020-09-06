#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Fibonacci
{
private:
    unsigned long fibo[91];
    int index;

public:
    Fibonacci() : index(1)
    {
        fibo[0] = 0;
        fibo[1] = 1;
    }

    unsigned long &operator[](int idx)
    {
        if (idx < 0 || idx > index)
        {
            exit(1);
        }
        return fibo[idx];
    }

    void FindFibo(int idx)
    {
        for (int i = index + 1; i <= idx; i++)
        {
            fibo[i] = fibo[i - 1] + fibo[i - 2];
        }
        index = idx;
    }
};

int main(void)
{
    Fibonacci fibo;
    int num;
    cin >> num;
    fibo.FindFibo(num);

    cout << fibo[num] << endl;
    return 0;
}