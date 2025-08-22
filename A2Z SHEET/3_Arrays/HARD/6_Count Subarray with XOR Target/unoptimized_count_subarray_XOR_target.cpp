#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {4, 2, 2, 6, 4};
    int target = 6;
    int xorArr = 0;
    int count = 0;

    for (int i = 0; i < arr.size(); i++)
    {
      xorArr = 0;
      for (int j = i; j < arr.size(); j++)
      {
        xorArr ^= arr[j];
        if (xorArr == target)
        {
          count++;
        }
      }
    }
    cout << "Subarray Count With XOR As Target: " << count << endl;
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