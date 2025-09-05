#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {25, 46, 28, 49, 24};
    int students = 4;
    int start = *max_element(arr.begin(), arr.end()), end = accumulate(arr.begin(), arr.end(), 0);
    int size = arr.size(), ans = -1;
    if (students > size)
      return;
    while(start <= end)
    {
      int currentStudents = 1, currentPgSum = arr[0];
      int mid = start + (end - start)/2;
      for (int j = 1; j < size; j++)
      {
        if (arr[j] + currentPgSum > mid)
        {
          currentStudents++;
          currentPgSum = arr[j];
        }
        else
        {
          currentPgSum += arr[j];
        }
      }

      if (currentStudents > students)
      {
        start = mid+1;
      }else{
        ans = mid;
        end = mid-1;
      }
    }

    cout << "Book Allocation: " << ans;
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