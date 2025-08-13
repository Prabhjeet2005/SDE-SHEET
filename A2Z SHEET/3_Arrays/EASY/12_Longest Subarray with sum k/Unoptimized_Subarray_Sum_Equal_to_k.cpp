#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {2, 3, 5};
    int k = 5;
    int maxLength = 0;

    for (int i = 0; i < arr.size(); i++)
    {
      int currentLength = 0;
      int sum = 0;
      for (int j = i; j < arr.size(); j++)
      {
        currentLength++;
        sum += arr[j];
        if (sum == k)
        {
          maxLength = max(maxLength, currentLength);
          break;
        }
      }
    }

    cout << "Max Length of SubArray Equal To K: " << maxLength << endl;
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}