#include <iostream>
#include <vector>

using namespace std;

class Seudoku
{
  private:
    vector<int> number;
    vector<vector<int>> table;
    vector<int> zero_row;
    vector<int> zero_col;
    int zero_cnt;

  public:
    Seudoku():zero_cnt(0)
    {
      number = vector<int>(10, 0);
      table.assign(9, vector<int>(9, 0));
    }

    void Scandata()
    {
      int num;
      for(int i=0; i<9; i++)
      {
        for(int j=0; j<9; j++)  
        {
          cin >> num;
          if(num == 0)
          {
            zero_row.push_back(i);
            zero_col.push_back(j);
          }
          table[i][j] = num;
        }
      }
    }

    void check_row(int row, int col)
    {
      int zero = 0;
      for(int j=0; j<9; j++)
      {
        if(table[row][j] == 0)
        {
          ++zero;
        }
        
      }
    }

    void check_col(int row, int col)
    {

    }

    void check_blcok(int row, int col)
    {

    }

};

int main(void)
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
}