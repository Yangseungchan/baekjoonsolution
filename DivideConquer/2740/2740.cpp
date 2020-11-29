#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<vector<int>> mtx1;
    vector<vector<int>> mtx2;

    int num_n, num_m, num_k, tmp, i, j;

    cin >> num_n >> num_m;

    mtx1.assign(num_n, vector<int>(num_m, 0));
    for (i = 0; i < num_n; i++)
    {
        for (j = 0; j < num_m; j++)
        {
            cin >> mtx1[i][j];
        }
    }

    cin >> tmp >> num_k;
    mtx2.assign(num_m, vector<int>(num_k, 0));
    for (i = 0; i < num_m; i++)
    {
        for (j = 0; j < num_k; j++)
        {
            cin >> mtx2[i][j];
        }
    }

    for (i = 0; i < num_n; i++)
    {
        for (j = 0; j < num_k; j++)
        {
            tmp = 0;
            for (int k = 0; k < num_m; k++)
            {
                tmp += mtx1[i][k] * mtx2[k][j];
            }
            cout << tmp << ' ';
        }
        cout << endl;
    }

    return 0;
}