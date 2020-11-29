#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

vector<vector<int>> matrix;

void make_quad_tree(int row_st, int col_st, int length)
{
    int all_flag;
    if (length == 1)
    {
        if (matrix[row_st][col_st] == 0)
        {
            cout << '0';
        }
        else
        {
            cout << '1';
        }
    }
    else
    {
        all_flag = matrix[row_st][col_st];
        for (int i = row_st; i < row_st + length; i++)
        {
            for (int j = col_st; j < col_st + length; j++)
            {
                if (matrix[i][j] != all_flag)
                {
                    all_flag = -1;
                    break;
                }
            }
            if (all_flag == -1)
            {
                break;
            }
        }
        if (all_flag == -1)
        {
            cout << '(';
            make_quad_tree(row_st, col_st, length / 2);
            make_quad_tree(row_st, col_st + length / 2, length / 2);
            make_quad_tree(row_st + length / 2, col_st, length / 2);
            make_quad_tree(row_st + length / 2, col_st + length / 2, length / 2);
            cout << ')';
        }
        else
        {
            if (all_flag == 1)
            {
                cout << '1';
            }
            else
            {
                cout << '0';
            }
        }
    }
    return;
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int length;
    string input;
    cin >> length;

    matrix.assign(length, vector<int>(length, 0));

    for (int i = 0; i < length; i++)
    {
        cin >> input;
        for (int j = 0; j < length; j++)
        {
            if (input.at(j) == '0')
            {
                matrix[i][j] = 0;
            }
            else if (input.at(j) == '1')
            {
                matrix[i][j] = 1;
            }
        }
        input.clear();
    }
    make_quad_tree(0, 0, length);
    cout << endl;

    return 0;
}