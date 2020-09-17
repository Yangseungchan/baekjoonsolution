#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print_vector(vector<int> &ref)
{
    for (int i = 0; i < ref.size(); i++)
    {
        cout << ref[i] << '\n';
    }
    return;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr;
    int length;
    cin >> length;

    arr.assign(length, 0);
    for (int i = 0; i < length; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    print_vector(arr);

    return 0;
}