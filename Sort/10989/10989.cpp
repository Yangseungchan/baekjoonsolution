#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  vector<int> container(10001, 0);

  int i,j, length, input, max;
  cin >> length;
  max = 0;

  for(i=0; i<length; i++)
  {
    cin >> input;
    container[input] += 1;
    if(max < input)
      max = input;
  }

  for(i=1; i<=max; i++)
  {
    for(j=0; j<container[i]; j++)
    {
      cout << i << '\n';
    }
  }
  return 0;
}