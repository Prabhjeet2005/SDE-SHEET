#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {4, 1, 2, 1, 2};
    int xorArr = 0;

    for (int i = 0; i < arr.size(); i++)
    {
      xorArr ^= arr[i];
    }

    cout<<"Single Element: "<<xorArr<<endl;
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}