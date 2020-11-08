#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<pair<int, int>> fact_zero; /* first pair : 2의 배수의 개수, second pair : 5의 배수의 개수 */

    int tmp, count_tw, count_fv, num, first_pair, second_pair;
    cin >> num;

    fact_zero.push_back(pair<int, int>(0, 0)); /* 0! */
    fact_zero.push_back(pair<int, int>(1, 0)); /* 1! */
    for (int i = 2; i <= num; i++)
    {
        tmp = i;
        count_tw = fact_zero[i - 1].first;
        count_fv = fact_zero[i - 1].second;
        while (tmp % 2 == 0)
        {
            count_tw++;
            tmp /= 2;
        }
        while (tmp % 5 == 0)
        {
            count_fv++;
            tmp /= 5;
        }
        fact_zero.push_back(pair<int, int>(count_tw, count_fv));
    }
    cout << min(fact_zero[num].first, fact_zero[num].second) << '\n';
    return 0;
}