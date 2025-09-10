#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<vector<int>> arr = {{1, 2, 3, 4, 5},
                               {8, 9, 11, 12, 13},
                               {21, 23, 25, 27, 29}};
    set<int> set;
    for (int row = 0; row < arr.size(); row++)
    {
      for (int col = 0; col < arr[0].size(); col++)
      {
        set.insert(arr[row][col]);
      }
    }

    int counter = 0, target = (arr.size() * arr[0].size()) / 2;
    for (auto &it : set)
    {
      if(counter == target){
        cout<<"Median: "<<it;
        return;
      }
      counter++;
    }
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