#include <iostream>
#include <vector>

using namespace std;

class Seudoku
{
private:
  vector<int> number;
  vector<vector<int>> table;
  vector<int> zero_row;  // 0의 가로 위치 보관
  vector<int> zero_col;  // 0의 세로 위치 보관
  vector<int> zero_flag; // 0이 있는 곳의 좌표가 수정되었는지 표시
  int zero_cnt;

public:
  Seudoku() : zero_cnt(0)
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
          zero_cnt++;
        }
        table[i][j] = num;
      }
    }
    zero_flag.assign(zero_cnt, 0);
  }

  void init_number()
  {
    for (int i = 0; i < number.size(); i++)
    {
      number[i] = 0;
    }
  }

  void check_row(int zero_idx)
  {
    init_number();
    for (int j = 0; j < 9; j++)
    {
      number[table[zero_row[zero_idx]][j]]++;
    }
    if (number[0] == 1)
    {
      for (int j = 1; j < 10; j++)
      {
        if (number[j] == 0)
        {
          table[zero_row[zero_idx]][zero_col[zero_idx]] = j;
          zero_flag[zero_idx] = 1; // zero_flag에 변경되었음을 표시
          zero_cnt -= 1;
          break;
        }
      }
    }
    return;
  }

  void check_col(int zero_idx)
  {
    init_number();
    for (int i = 0; i < 9; i++)
    {
      number[table[i][zero_col[zero_idx]]]++;
    }
    if (number[0] == 1)
    {
      for (int j = 1; j < 10; j++)
      {
        if (number[j] == 0)
        {
          table[zero_row[zero_idx]][zero_col[zero_idx]] = j;
          zero_flag[zero_idx] = 1;
          zero_cnt -= 1;
          break;
        }
      }
    }
    return;
  }

  void check_block(int zero_idx)
  {
    int row_cnt = zero_row[zero_idx] / 3;
    int col_cnt = zero_col[zero_idx] / 3;
    init_number();

    for (int i = 3 * row_cnt; i < 3 * row_cnt + 3; i++)
    {
      for (int j = 3 * col_cnt; j < 3 * col_cnt + 3; j++)
      {
        number[table[i][j]]++;
      }
    }
    if (number[0] == 1)
    {
      for (int j = 1; j < 10; j++)
      {
        if (number[j] == 0)
        {
          table[zero_row[zero_idx]][zero_col[zero_idx]] = j;
          zero_flag[zero_idx] = 1;
          zero_cnt -= 1;
          break;
        }
      }
    }
    return;
  }

  void fill_blank()
  {
    do
    {
      for (int i = 0; i < zero_flag.size(); i++)
      {
        if (zero_flag[i] == 0)
          check_row(i);
        if (zero_flag[i] == 0)
          check_col(i);
        if (zero_flag[i] == 0)
          check_block(i);
      }
    } while (zero_cnt > 0);

    cout << "result\n";

    for (int i = 0; i < 9; i++) /* print table after searching*/
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