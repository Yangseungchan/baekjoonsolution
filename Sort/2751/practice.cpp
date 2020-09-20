#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    vector<pair<int, string>> v;

    v.push_back(pair<int, string>(90, "박한올"));
    v.push_back(pair<int, string>(50, "didtmdcks"));
    v.push_back(pair<int, string>(60, "dasd"));

    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].second << ' ';
    }
    return 0;
}