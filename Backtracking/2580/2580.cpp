#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Seudoku
{
private:
  vector<int> number;
  vector<vector<int>> table;
  vector<int> zero_row;  // 0의 가로 위치 보관
  vector<int> zero_col;  // 0의 세로 위치 보관
  stack<int> num_stk;
  int zero_max;

public:
  Seudoku() : zero_max(0)
  {
    number = vector<int>(10, 0);        /* index from 0 to 9 */
    table.assign(9, vector<int>(9, 0)); /* index from 0 to 8 */
  }

  void Scandata()
  {
    int num;
    for (int i = 0; i < 9; i++)
    {
      for (int j = 0; j < 9; j++)
      {
        cin >> num;
        if (num == 0)
        {
          zero_row.push_back(i);
          zero_col.push_back(j);
          zero_max++;
        }
        table[i][j] = num;
      }
    }
  }

  void init_number()
  {
    for (int i = 0; i < number.size(); i++)
    {
      number[i] = 0;
    }
  }

  void check_row_col(int zero_idx)
  {
    for (int j = 0; j < 9; j++)
    {
      number[table[zero_row[zero_idx]][j]]++;
      number[table[j][zero_col[zero_idx]]]++;
    }
    return;
  }

  void check_block(int zero_idx)
  {
    int row_cnt = zero_row[zero_idx] / 3;
    int col_cnt = zero_col[zero_idx] / 3;

    for (int i = 3 * row_cnt; i < 3 * row_cnt + 3; i++)
    {
      for (int j = 3 * col_cnt; j < 3 * col_cnt + 3; j++)
      {
        number[table[i][j]]++;
      }
    }
    return;
  }

  bool possible() // checking possibity of insertion
  {
    for(int i=1; i<10; i++)
    {
      if(number[i] == 0)
        return true;
    }
    return false;
  }

  void fill_blank()
  {
    for(int i=0; i<zero_max; i++)
    {
      visit_blank(i);
    }
  }

  void print_table()
  {
    for(int i=0; i<9; i++)
    {
      for(int j=0; j<9; j++)
      {
        cout << table[i][j] << " ";
      }
      cout << '\n';
    }
  }
};

int main(void)
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  Seudoku sdku;
  sdku.Scandata();
  sdku.fill_blank();

  return 0;
}