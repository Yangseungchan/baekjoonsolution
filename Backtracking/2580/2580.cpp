#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Seudoku
{
private:
  vector<int> number;
  vector<vector<int>> table;
  vector<int> zero_row; // 0의 가로 위치 보관
  vector<int> zero_col; // 0의 세로 위치 보관
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

  bool possible(vector<int> &ref) // check했을때 어느 하나의 숫자라도 table에서 0의 자리에 대입 가능한지의 여부를 판단하는 함수
  {
    for (int i = 1; i < 10; i++)
    {
      if (ref[i] == 0)
        return true;
    }
    return false;
  }

  void fill_blank()
  {
    vector<int> temp(10, 0);
    int start_idx = 0;
    init_number();            // number 초기화
    check_row_col(start_idx); // 가로, 세로 확인
    check_block(start_idx);   // 3x3 block 확인
    temp = number;
    for (int i = 1; i < 10; i++)
    {
      if (temp[i] == 0)
      {
        visit_blank(start_idx, i);
      }
    }
  }

  void visit_blank(int idx, int num)
  {
    vector<int> temp(10, 0);
    table[zero_row[idx]][zero_col[idx]] = num;
    idx++;
    if (idx >= zero_max)
    {
      print_table();
      exit(0);
    }
    init_number();
    check_row_col(idx);
    check_block(idx);
    temp = number;

    if (possible(temp))
    {
      for (int i = 1; i < 10; i++)
      {
        if (temp[i] == 0)
        {
          visit_blank(idx, i);
        }
      }
    }
    table[zero_row[idx - 1]][zero_col[idx - 1]] = 0;
  }

  void print_table()
  {
    for (int i = 0; i < 9; i++)
    {
      for (int j = 0; j < 9; j++)
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