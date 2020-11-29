#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrix;
int paper_m1, paper_0, paper_1;

void check_paper(int row_st, int col_st, int length)
{
    int value = matrix[row_st][col_st];
    if (length == 1)
    {

        if (value == -1)
        {
            paper_m1++;
        }
        else if (value == 0)
        {
            paper_0++;
        }
        else
        {
            paper_1++;
        }
    }
    else
    {
        for (int i = row_st; i < row_st + length; i++)
        {
            for (int j = col_st; j < col_st + length; j++)
            {
                if (value != matrix[i][j])
                {
                    value = -2;
                    break;
                }
            }
            if (value == -2)
            {
                break;
            }
        }
        if (value == -2)
        {
            check_paper(row_st, col_st, length / 3);
            check_paper(row_st, col_st + length / 3, length / 3);
            check_paper(row_st, col_st + 2 * (length / 3), length / 3);
            check_paper(row_st + length / 3, col_st, length / 3);
            check_paper(row_st + length / 3, col_st + length / 3, length / 3);
            check_paper(row_st + length / 3, col_st + 2 * (length / 3), length / 3);
            check_paper(row_st + 2 * (length / 3), col_st, length / 3);
            check_paper(row_st + 2 * (length / 3), col_st + length / 3, length / 3);
            check_paper(row_st + 2 * (length / 3), col_st + 2 * (length / 3), length / 3);
        }
        else
        {
            if (value == -1)
            {
                paper_m1++;
            }
            else if (value == 0)
            {
                paper_0++;
            }
            else
            {
                paper_1++;
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
    paper_m1 = paper_0 = paper_1 = 0;
    cin >> length;
    matrix.assign(length, vector<int>(length, 0));

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            cin >> matrix[i][j];
        }
    }
    check_paper(0, 0, length);
    cout << paper_m1 << '\n'
         << paper_0 << '\n'
         << paper_1 << '\n';

    return 0;
}