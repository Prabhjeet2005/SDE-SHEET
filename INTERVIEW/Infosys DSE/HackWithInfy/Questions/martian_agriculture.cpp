/*
### ⚔️ Blind Story-Stripping Challenge 4

**Problem: Martian Agriculture**
You are the chief botanist of the first Mars colony. You manage a massive row of N bio-domes, indexed from 0 to N-1. Because the terraforming just started, the initial humidity inside every bio-dome is exactly 0.
The colony's central AI controls the water supply and executes Q watering commands. Each command specifies three values: L, R, and H. When executed, the AI releases vapor that increases the humidity of every bio-dome from index L to index R (inclusive) by exactly H units.
The Martian potatoes are extremely sensitive. They will only grow if their final humidity after all Q commands is **exactly equal** to a target value, K. If the humidity is even one unit higher or lower, the crops die.
Return the total number of bio-domes that will successfully grow potatoes.
**Constraints:**
1 <= N <= 10^5
1 <= Q <= 10^5
0 <= L <= R < N
1 <= H <= 100
1 <= K <= 10^7
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {};
    vector<vector<int>>queries;
    int k_threshold;
    int n = arr.size();
    vector<int>difference_arr(n+1,0);

    for(int i=0; i<queries.size(); i++){
      int l = queries[i][0];
      int r = queries[i][1];
      int h = queries[i][2];

      difference_arr[l] += h;
      difference_arr[r+1] -= h; // DRAIN r+1
    }

    for(int i=1; i<n; i++){
      difference_arr[i] += difference_arr[i-1];
    }

    int potatoes_success = 0;
    for(int i=0; i<n; i++){
      int final_temp = difference_arr[i] + arr[i];
      if(final_temp == k_threshold){
        potatoes_success++;
      }
    }

    cout<<"Successful potatoes: "<<potatoes_success;
  }
};

int main()
{
  cout << endl;
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}