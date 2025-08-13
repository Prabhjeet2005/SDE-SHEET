#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {1, 2, 3, 5, 6, 7, 8, 9};
    int missingNumber = 0;
    int n = 9;
    int sumN = (n * (n + 1)) / 2;
    int sumArray = 0;

    for (int i = 0; i < arr.size(); i++)
    {
      sumArray += arr[i];
    }

    missingNumber = sumN - sumArray;

    cout << "Missing Number: " << missingNumber << endl;
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}