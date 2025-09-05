#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {0, 3, 4, 7, 10, 9};
    int cows = 4, size = arr.size();
    sort(arr.begin(), arr.end());
    int mini = arr[0], maxi = arr[size - 1], maxDistance = maxi - mini;
    int ans = maxDistance;

    if (cows > size)
    {
      cout << "Not Possible";
      return;
    }

    for (int i = 1; i <= maxDistance; i++)
    {
      int lastCowPosition = 0, currentCowCount = 1;
      for (int j = 1; j < size; j++)
      {
        if (arr[j] - arr[lastCowPosition] >= i)
        {
          currentCowCount++;
          lastCowPosition = j;
        }
      }
      if (currentCowCount < cows)
      {
        ans = i - 1;
        break;
      }
    }
    cout << "Min Possible Max Distance: " << ans;
  }
};

int main()
{
  Solution solObj = Solution();
  cout << "\n";
  solObj.solution();
  cout << "\n";
}