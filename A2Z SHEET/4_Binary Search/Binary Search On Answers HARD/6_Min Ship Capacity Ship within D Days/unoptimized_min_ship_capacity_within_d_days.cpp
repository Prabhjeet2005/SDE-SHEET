#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {5, 4, 5, 2, 3, 4, 5, 6};
    int daysTarget = 5;
    int finalMinCapacity = -1;
    int sumArr = accumulate(arr.begin(), arr.end(), 0);
    int maxi = *max_element(arr.begin(), arr.end());

    for (int capacity = maxi; capacity <= sumArr; capacity++)
    {
      int currentLoad = 0;
      int days = 1;
      for (int j = 0; j < arr.size(); j++)
      {

        if (currentLoad + arr[j] > capacity)
        {
          days++;
          currentLoad = arr[j];
        }
        else
        {
          currentLoad += arr[j];
        }
      }

      if (days <= daysTarget)
      {
        finalMinCapacity = capacity;
        break;
      }
    }

    cout << "Min Capacity Required: " << finalMinCapacity;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << endl;
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}