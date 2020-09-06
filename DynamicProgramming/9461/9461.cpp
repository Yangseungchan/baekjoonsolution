#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Padovan
{
private:
    long long padovan[101];
    int index;

public:
    Padovan() : index(3)
    {
        padovan[1] = padovan[2] = padovan[3] = 1;
    }

    long long &operator[](int idx)
    {
        if (idx < 0 || idx > 101)
        {
            exit(1);
        }
        if (index <= idx)
        {
            FindPadovan(idx);
        }
        return padovan[idx];
    }

    void FindPadovan(int idx)
    {
        for (int i = index + 1; i <= idx; i++)
        {
            padovan[i] = padovan[i - 2] + padovan[i - 3];
        }
        index = idx;
    }
};

int main(void)
{
    Padovan pdv;
    int num_case, index;

    cin >> num_case;
    vector<int> test_case(num_case);

    for (int i = 0; i < num_case; i++)
        cin >> test_case[i];

    for (int i = 0; i < num_case; i++)
    {
        cout << pdv[test_case[i]] << endl;
    }

    return 0;
}