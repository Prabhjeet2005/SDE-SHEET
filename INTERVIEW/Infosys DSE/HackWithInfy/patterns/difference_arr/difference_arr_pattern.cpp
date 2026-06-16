#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  void solution()
  {
    int n = 6; // 6 Sized Array
    // {L,R,Value Increment}
    vector<vector<int>> queries = {{1, 3, 10}};

    vector<int> difference_arr(n + 1, 0);
    /*
      ans to achieve = [0,10,10,10,0,0]
     */

    for (int i = 0; i < queries.size(); i++)
    {
      int l = queries[i][0];
      int r = queries[i][1];
      int value = queries[i][2];

      difference_arr[l] += value;
      difference_arr[r+1] -= value;
    }
    // diff = [0,10,0,0,-10,0,0]  -> Source at L, Drain at R+1
    // APPLYING prefix_sum on difference_Arr [0,10,10,10,0,0,0]
    for(int i=1; i<n; i++){
      difference_arr[i] = difference_arr[i] + difference_arr[i-1];
    }

    for(auto &element:difference_arr){
      cout<<element<<" ";
    }
  }
};

int main()
{
  cout << endl;
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}