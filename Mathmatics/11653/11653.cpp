#include <iostream>
#include <vector>

using namespace std;

class Division
{
private:
    int length;
    vector<int> count;

public:
    Division(int num)
    {
        length = num + 1;
        count.assign(length, 0);
    }

    void find_quotient(int num)
    {
        for (int i = 2; i <= num; i++)
        {
            if (num % i == 0)
            {
                count[i] += 1;
                find_quotient(num / i);
                return;
            }
        }
        return;
    }

    void print_result()
    {
        for (int i = 2; i < length; i++)
        {
            if (count[i] > 0)
            {
                for (int j = 0; j < count[i]; j++)
                {
                    cout << i << '\n';
                }
            }
        }
    }
};

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int num;
    cin >> num;
    Division div(num);
    div.find_quotient(num);
    div.print_result();
    return 0;
}