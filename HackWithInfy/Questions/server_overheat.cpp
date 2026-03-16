/*
### ⚔️ Blind Story-Stripping Challenge 2
**Problem: The Overheated Server Farm**
You are the lead DevOps engineer for a massive cloud company. You manage a server farm with N servers arranged in a massive row, indexed from 0 to N-1. Initially, the CPU temperature of every single server is exactly 0 degrees.
The system receives a batch of Q compute tasks. Each task is defined by three integers: L, R, and T. When a task executes, it utilizes every server from index L to index R (inclusive), which increases the temperature of all those servers by exactly T degrees.
The servers have a critical failure threshold of K degrees. If a server's final temperature after all Q tasks have finished is **strictly greater** than K degrees, that server will melt down and crash.
Your goal is to return the total number of servers that will crash.
**Constraints:**
1 <= N <= 10^5
1 <= Q <= 10^5
0 <= L <= R < N
1 <= T <= 50
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
    vector<int> arr = {0, 0, 0, 0, 0}; // 5 servers
    vector<vector<int>> queries = {{0, 2, 50}, {2, 4, 30}};
    int k_threshold = 70;
    int n = arr.size();
    vector<int>difference_arr(n+1,0);

    for(int i=0; i<queries.size(); i++){
      int l = queries[i][0];
      int r = queries[i][1];
      int val = queries[i][2];

      difference_arr[l] += val; 
      difference_arr[r+1] -= val; // DRAIN
    }

    // 1. Build Diff -> 2. Prefix Sum Diff -> 3. Apply to Original

    for(int i=1; i<n; i++){
      difference_arr[i] += difference_arr[i-1];
    }

    int servers_melt = 0;
    for(int i=0; i<n; i++){
      int final_temp = arr[i] + difference_arr[i];
      if(final_temp > k_threshold){
        servers_melt++;
      }
    }

    cout<<"Servers Melt: "<<servers_melt;

  }
};

int main()
{
  cout << endl;
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}