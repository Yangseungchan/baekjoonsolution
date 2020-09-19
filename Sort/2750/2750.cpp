#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void scanMember(vector<int> &ref, int length)
{
    for (int i = 0; i < length; i++)
    {
        cin >> ref[i];
    }
}

void print_vector(vector<int> &arr)
{
    int i;
    for (i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
}

void insertion_sort(vector<int> &arr)
{
    int i, j, temp;
    for (i = 1; i < arr.size(); i++)
    {
        temp = arr[i];
        for (j = i; j > 0 && arr[j - 1] > temp; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = temp;
    }
    return;
}

int main(void)
{
    int length;
    vector<int> arr;
    cin >> length;

    arr.assign(length, 0);
    scanMember(arr, length);
    insertion_sort(arr);
    print_vector(arr);

    return 0;
}
