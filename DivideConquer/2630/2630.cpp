#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int blue_paper;
int white_paper;

void find_color_paper(vector<vector<int>> mtx, int row_st, int col_st, int length)
{
    int paper_flag;
    if (length == 1)
    {
        if (mtx[row_st][col_st] == 1)
        {
            ++blue_paper;
        }
        else
        {
            ++white_paper;
        }
        return;
    }
    else
    {
        paper_flag = mtx[row_st][col_st];
        for (int i = row_st; i < row_st + length; i++)
        {
            for (int j = col_st; j < col_st + length; j++)
            {
                if (mtx[i][j] != paper_flag)
                {
                    paper_flag = -1;
                    break;
                }
            }
            if (paper_flag == -1)
            {
                break;
            }
        }
        if (paper_flag == -1)
        {
            find_color_paper(mtx, row_st, col_st, length / 2);
            find_color_paper(mtx, row_st, col_st + length / 2, length / 2);
            find_color_paper(mtx, row_st + length / 2, col_st, length / 2);
            find_color_paper(mtx, row_st + length / 2, col_st + length / 2, length / 2);
        }
        else
        {
            if (paper_flag == 1)
            {
                ++blue_paper;
            }
            else
            {
                ++white_paper;
            }
            return;
        }
    }
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<vector<int>> matrix;
    int length;
    blue_paper = white_paper = 0;

    cin >> length;
    matrix.assign(length, vector<int>(length, 0));
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            cin >> matrix[i][j];
        }
    }
    find_color_paper(matrix, 0, 0, length);

    cout << white_paper << '\n';
    cout << blue_paper << '\n';

    return 0;
}