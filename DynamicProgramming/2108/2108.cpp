#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int index(int i)
{
  return i+4000;
}

void print_vector(vector<int> &ref)
{
  for(int i=0; i<ref.size(); i++)
  {
    cout << ref[i] << " ";
  }
  cout << endl;
}

int average(int sum, int count)
{
  double avg_d = static_cast<double>(sum) / static_cast<double>(count);

  int avg_i = sum / count;

  if(avg_d - avg_i > 0.5)
    return (sum / count) + 1;
  return sum / count;
}

int middle_value(vector<int> container, int length)
{
  int count = (length / 2) + 1;
  for(int i=0; i<=8000; i++)
  {
    if(container[i] ==0)
      continue;
    count -= container[i];
    if(count <= 0)
    {
      return i-4000;
    }
  }
}

int most_frequent(vector<int> container)
{
  int min;
  int max = 0;
  int max_idx;
  vector<int> arr;
  for(int i=0; i<= container.size(); i++)
  {
    if(container[i] > max)
    {
      arr.clear();
      max = container[i];
      max_idx = i;
    }
    if(container[i] == max)
    {
      arr.push_back(max_idx);
    }
  }
  if(arr.size() > 1)
  {
    sort(arr.begin(), arr.end());
    print_vector(arr);
    min = arr[0];
    for(int i=0; i<arr.size(); i++)
    {
      if(min < arr[i])
      {
        return arr[i];
      }
    }
  }

  return max_idx - 4000;
}


int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int sum, min, max, num, length;
  vector<int> container(8001, 0); //index : 0 ~ 8001(-4000~4000)
  
  cin >> length;
  sum = 0;
  min = 9999;
  max = -9999;
  for(int i=0; i<length; i++)
  {
    cin >> num;
    sum += num;
    container[index(num)] += 1;
    if(min > num)
      min = num;
    if(max < num)
      max = num;
  }

  cout << average(sum , length) << endl; // average
  cout  << middle_value(container, length) << endl;// middle value 
  cout  << most_frequent(container) << endl; // most frequent value
  cout << max - min << endl; // range


  return 0;
}

