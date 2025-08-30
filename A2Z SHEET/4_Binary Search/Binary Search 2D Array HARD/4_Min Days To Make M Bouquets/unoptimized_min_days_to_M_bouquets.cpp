#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int m = 2, k = 3;
    int mini = *min_element(arr.begin(), arr.end());
    int maxi = *max_element(arr.begin(), arr.end());
    int minDays = -1;
    for (int i = mini; i <= maxi; i++)
    {
      int bouquetCount = 0, count = 0;
      for (int j = 0; j < arr.size(); j++)
      {
        if (arr[j] <= i)
        {
          count++;
        }
        else
        {
          bouquetCount += (count / k);
          count = 0;
        }
      }
      bouquetCount += (count / k); // else not encountered

      if (bouquetCount >= m)
      {
        minDays = i;
        break;
      }
    }
    cout << "Min Days To Form Bouquets: " << minDays;
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