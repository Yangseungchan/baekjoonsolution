#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int index(int i)
{
  return i + 4000;
}

void print_vector(vector<int> &ref)
{
  for (int i = 0; i < ref.size(); i++)
  {
    cout << ref[i] << " ";
  }
  cout << endl;
}

int average(int sum, int count)
{
  double avg_d = static_cast<double>(sum) / static_cast<double>(count);
  return round(avg_d);
}

int middle_value(vector<int> &container, int length, int min, int max)
{
  int count = (length / 2) + 1;
  for (int i = index(min); i <= index(max); i++)
  {
    if (container[i] == 0)
      continue;
    count -= container[i];
    if (count <= 0)
    {
      return i - 4000;
    }
  }
  return -1;
}

int most_frequent(vector<int> &container, int container_min, int container_max)
{
  int min;
  int max = 0;
  int max_idx;
  vector<int> arr;
  for (int i = index(container_min); i <= index(container_max); i++)
  {
    if (container[i] > max)
    {
      arr.clear();
      arr.push_back(i); // arr에는 index함수에 의해서 변환된 index(물리적으로 저장되는 인덱스)가 저장
      max = container[i];
      max_idx = i;
    }
    else if (container[i] == max)
    {
      arr.push_back(i);
    }
  }
  if (arr.size() > 1)
  {
    sort(arr.begin(), arr.end());
    return arr[1] - 4000;
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
  for (int i = 0; i < length; i++)
  {
    cin >> num;
    sum += num;
    container[index(num)] += 1;
    if (min > num)
      min = num;
    if (max < num)
      max = num;
  }

  cout << average(sum, length) << '\n';                      // average
  cout << middle_value(container, length, min, max) << '\n'; // middle value
  cout << most_frequent(container, min, max) << '\n';        // most frequent value
  cout << max - min << '\n';                                 // range

  return 0;
}
