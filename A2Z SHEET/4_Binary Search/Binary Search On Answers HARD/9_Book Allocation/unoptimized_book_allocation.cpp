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
    if(students > size)return;
    for (int i = start; i <= end; i++)
    {
      int currentStudents = 1, currentPgSum = arr[0];

      for (int j = 1; j < size; j++)
      {
        if (arr[j] + currentPgSum > i)
        {
          currentStudents++;
          currentPgSum = arr[j];
        }
        else
        {
          currentPgSum += arr[j];
        }
      }

      if (currentStudents == students)
      {
        ans = i;
        break;
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