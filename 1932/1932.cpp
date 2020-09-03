#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::vector;

class MaxTriangle
{
private:
    int length;
    vector<vector<int>> arr;

public:
    MaxTriangle(int len) : length(len)
    {
        arr.assign(length, vector<int>(length));
    }

    void ScanData()
    {
        for (int i = 0; i < length; i++)
            for (int j = 0; j <= i; j++)
                cin >> arr[i][j];

        return;
    }

    int FindMax()
    {
        arr[1][0] += arr[0][0];
        arr[1][1] += arr[0][0];
        for (int i = 2; i <= length - 1; i++)
        {
            arr[i][0] += arr[i - 1][0];
            for (int j = 1; j <= i - 1; j++)
            {
                arr[i][j] += max(arr[i - 1][j - 1], arr[i - 1][j]);
            }
            arr[i][i] += arr[i - 1][i - 1];
        }

        int maximum = arr[length - 1][0];
        for (int j = 0; j < length; j++)
        {
            if (maximum < arr[length - 1][j])
                maximum = arr[length - 1][j];
        }

        return maximum;
    }

    void PrintTriangle()
    {
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main(void)
{
    int length;
    cin >> length;

    MaxTriangle MaxT(length);
    MaxT.ScanData();
    cout << MaxT.FindMax() << endl;

    //MaxT.PrintTriangle();

    return 0;
}