#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {4, 2, 2, 6, 4};
    int target = 6, xorArr = 0, count = 0;
    unordered_map<int, int> map;
    // map[0]++;

    for (int i = 0; i < arr.size(); i++)
    {
      xorArr ^= arr[i];

      if (xorArr == target)
      {
        count++;
      }
      else if (map.find(target ^ xorArr) != map.end())
      {
        count += map[target ^ xorArr];
      }
      map[xorArr]++;
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