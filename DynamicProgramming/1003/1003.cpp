#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

class FiboCount
{
  private:
    int idx;
    vector<long long> zero;
    vector<long long> one;
  public:
    FiboCount():idx(1)
    {
      zero.assign(41, 0); // size of vector, data to be initialized
      one.assign(41, 0);  
      zero[0] = one[1] = 1;
      zero[1] = one[0] = 0;
    }

    void Fibo(int index)
    {
      for(int i=idx+1; i<=index; i++)
      {
        zero[i] = zero[i-1] + zero[i-2];
        one[i] = one[i-1] + one[i-2];
      }
      idx = index;
      return; 
    }

    long long& FindZero(int index)
    {
      if(idx < index)
      {
        Fibo(index);
      }
      return zero[index];
    }

    long long &FindOne(int index)
    {
      if(idx < index)
      {
        Fibo(index);
      }
      return one[index];
    }
};

int main(void)
{
  FiboCount fibo;
  int n, numOfcase;
  cin >> numOfcase;

  vector<int> testcase(numOfcase);

  for(int i=0; i<numOfcase; i++)
  {
     cin >> testcase[i];
  }

  for(int i=0; i<numOfcase; i++)
  {
    cout << fibo.FindZero(testcase[i]) << " " << fibo.FindOne(testcase[i]) << endl;
  }
}
