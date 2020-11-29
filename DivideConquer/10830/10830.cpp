#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<long long>> matrix;

void matrix_multiplication(vector<vector<long long>> &mtx1, vector<vector<long long>> &mtx2, int length)
{
    int i, j;
    long long tmp;
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < length; j++)
        {
            tmp = 0;
            for (int k = 0; k < length; k++)
            {
                tmp = ((tmp % 1000) + ((mtx1[i][k] % 1000) * (mtx2[k][j] % 1000) % 1000)) % 1000;
            }
            matrix[i][j] = tmp % 1000;
        }
    }
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long num_n, num_b, temp;
    int i, j, num;
    stack<int> bit;
    vector<vector<long long>> input_mtx, temp_mtx;

    cin >> num_n >> num_b;

    matrix.assign(num_n, vector<long long>(num_n, 0));
    input_mtx.assign(num_n, vector<long long>(num_n, 0));
    temp_mtx.assign(num_n, vector<long long>(num_n, 0));

    for (i = 0; i < num_n; i++)
    {
        for (j = 0; j < num_n; j++)
        {
            cin >> num;
            input_mtx[i][j] = num % 1000;
        }
    }
    temp_mtx = input_mtx;
    temp = num_b;
    if (temp != 1)
    {
        while (temp > 1)
        {
            bit.push(temp % 2);
            temp /= 2;
        }
        bit.push(1);
        bit.pop();

        while (!bit.empty())
        {
            temp = bit.top();
            bit.pop();
            if (temp == 1)
            {
                matrix_multiplication(temp_mtx, temp_mtx, num_n);
                temp_mtx = matrix;
                matrix_multiplication(temp_mtx, input_mtx, num_n);
            }
            else
            {
                matrix_multiplication(temp_mtx, temp_mtx, num_n);
            }
            temp_mtx = matrix;
        }
    }
    else
    {
        matrix = input_mtx;
    }

    for (i = 0; i < num_n; i++)
    {
        for (j = 0; j < num_n; j++)
        {
            cout << matrix[i][j];
            if (j != num_n - 1)
            {
                cout << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}