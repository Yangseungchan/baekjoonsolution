#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(string &s1, string &s2)
{
    if (s1.length() == s2.length())
    /* 사전순 정렬 */
    {
        if (s1.compare(s2) < 0)
            return true;
        return false;
    }
    else
    {
        if (s1.length() < s2.length())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

void print_vector(vector<string> &ref)
{
    cout << ref[0] << '\n';
    for (int i = 1; i < ref.size(); i++)
    {
        if (ref[i].compare(ref[i - 1]) == 0)
        {
            continue;
        }
        else
        {
            cout << ref[i] << '\n';
        }
    }
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string temp;
    vector<string> str_arr;

    int num;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> temp;
        str_arr.push_back(temp);
    }

    sort(str_arr.begin(), str_arr.end(), compare);
    print_vector(str_arr);
    return 0;
}