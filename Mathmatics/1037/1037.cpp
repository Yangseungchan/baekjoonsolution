#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> factor;
    int num, length;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cin >> num;
        factor.push_back(num);
    }

    sort(factor.begin(), factor.end());

    cout << factor[0] * factor[factor.size() - 1] << '\n';

    return 0;
}