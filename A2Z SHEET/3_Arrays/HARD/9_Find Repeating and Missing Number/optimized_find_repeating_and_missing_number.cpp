#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution
{
public:
  void solution()
  {
    vector<int> arr = {3, 1, 2, 5, 4, 6, 7, 5};
    int n = arr.size();
    int missingNumber = -1, repeatingNumber = -1;

    long long sumN = (n * (n + 1)) / 2; // Missing Number
    long long sumArr = 0;               // Repeating Number
    long long sum2Arr = 0;
    long long sum2N = (n * (n + 1) * (2 * n + 1)) / 6;
    for (int i = 0; i < n; i++)
    {
      sumArr += arr[i];
      sum2Arr += arr[i] * arr[i];
    }
    long long val1 = sumN - sumArr; // X - Y
    long long val2 = (sum2N - sum2Arr )/val1; // Find X+Y => X^2 - Y^2 = (X+Y)(X-Y) 

    missingNumber = (val1 + val2)/2;
    repeatingNumber = missingNumber - val1;

    cout << "Missing Number: " << missingNumber;
    cout << "\nRepeating Number: " << repeatingNumber;
  }
};
int main()
{
  cout << "\n";
  Solution sol = Solution();
  sol.solution();
  cout << "\n";
}