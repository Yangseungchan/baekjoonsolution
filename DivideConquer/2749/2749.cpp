#include <iostream>
#include <vector>
#include <stack>

using namespace std;

long long rest_idx = 1000000;

vector<vector<long long>> matrix;

void matrix_multiplication(vector<vector<long long>> &mtx1, vector<vector<long long>> &mtx2, int length1, int length2) // 크기가 더 큰놈이 전자
{
    long long tmp = 0;
    for (int i = 0; i < length1; i++)
    {
        for (int j = 0; j < length2; j++)
        {
            for (int k = 0; k < length1; k++)
            {
                tmp = ((tmp % rest_idx) + (((mtx1[i][k] % rest_idx) * (mtx2[k][j] % rest_idx)) % rest_idx)) % rest_idx;
            }
            matrix[i][j] = tmp % rest_idx;
            tmp = 0;
        }
    }
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    stack<int> bit_stk;
    matrix.assign(2, vector<long long>(2, 0));
    vector<vector<long long>> matrix1 = {{1, 1}, {1, 0}};
    vector<vector<long long>> matrix2 = {{1, 1}, {1, 0}};
    vector<vector<long long>> fibo_mtx = {{1}, {0}};
    long long num_n, tmp;
    cin >> num_n;
    tmp = num_n - 1;

    while (tmp > 1)
    {
        bit_stk.push(tmp % 2);
        tmp /= 2;
    }

    while (!bit_stk.empty())
    {
        tmp = bit_stk.top();
        bit_stk.pop();
        if (tmp == 0)
        {
            matrix_multiplication(matrix1, matrix1, 2, 2);
            matrix1 = matrix;
        }
        else
        {
            matrix_multiplication(matrix1, matrix1, 2, 2);
            matrix1 = matrix;
            matrix_multiplication(matrix1, matrix2, 2, 2);
            matrix1 = matrix;
        }
    }

    cout << matrix1[0][0] << '\n';

    return 0;
}