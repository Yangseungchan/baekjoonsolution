#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int num, temp, quotient, remnant;
    vector<int> container(10, 0); /* 자릿수 0부터 9까지 각각의 출연횟수를 담는 벡터 */
    cin >> num;
    quotient = num;
    do
    {
        remnant = quotient % 10;
        quotient = quotient / 10;
        container[remnant] += 1;
    } while (quotient != 0);

    for (int i = 9; i >= 0; i--)
    {
        if (container[i] > 0)
        {
            for (int j = 0; j < container[i]; j++)
            {
                cout << i;
            }
        }
    }
    cout << '\n';

    return 0;
}
