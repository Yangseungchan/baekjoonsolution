#include <iostream>
#include <vector>

using namespace std;

class EightQueen
{
  private:
    vector<int> pos;
    vector<int> flag_a;
    vector<int> flag_b;
    vector<int> flag_c;
    int length;
    int count;
    int temp;


  public:
    EightQueen(int len):length(len), count(0)
    {
      pos = vector<int>(len, 0);
      flag_a = vector<int>(len, 0); //  checking parallel line
      flag_b = vector<int>(2*len-1, 0);// checking crossline1
      flag_c = vector<int>(2*len-1, 0);// checking crossline2
      temp = length-1;
    }

    int &retcount()
    {
      return count;
    }

    void Set(int i)
    {
      for(int j=0; j<length; j++)
      {
        if(!flag_a[j] && !flag_b[i+j] && !flag_c[i-j+temp])
        {
          pos[i] = j;
          if(i==length-1)
          {
            ++count;
          }
          else{
            flag_a[j] = flag_b[i+j] = flag_c[i-j+temp] = 1;
            Set(i+1);
            flag_a[j] = flag_b[i+j] = flag_c[i-j+temp] = 0;
          }
        }
      }
    }
};

int main(void)
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int num;
  cin >> num;
  EightQueen equeen(num);
  equeen.Set(0);

  cout << equeen.retcount() << '\n';


  return 0;
}