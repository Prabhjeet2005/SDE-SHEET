/*
### ⚔️ Day 3: The Gauntlet (Story 1)

 **Problem: The Terraforming Drones**

 You are in charge of terraforming a barren stretch of land on Mars. The land is divided into N equal sectors in a straight line, indexed from 0 to N-1. Initially, the oxygen level in every sector is 0.

 You have a fleet of automated drones. You send out Q drone commands. Each command is represented by three integers: L, R, and O_2. When a drone receives a command, it flies over the land and increases the oxygen level of every single sector from index L to index R (inclusive) by exactly O_2 units.

 After all Q commands have been executed, you need to find the sector with the absolute highest oxygen level. Return that maximum oxygen level.

 **Constraints:**
 1 <= N <= 10^5
 1 <= Q <= 10^5
 0 <= L <= R < N
 1 <= O_2 <= 1000

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
    int N=arr.size();
    vector<vector<int>>queries = {};

    vector<int>difference_arr(N+1,0);
    for(int i=0; i<queries.size(); i++){
      int l = queries[i][0];
      int r = queries[i][1];
      int val = queries[i][2];

      difference_arr[l] += val;
      difference_arr[r+1] -= val;
    }

    int max_oxygen = 0;
    for(int i=1; i<difference_arr.size(); i++){
      difference_arr[i] += difference_arr[i-1];
    }

    for(auto &element:difference_arr){
      max_oxygen = max(element,max_oxygen);
    }

    cout<< "Max Possible Oxygen: "<<max_oxygen;
  }
};

int main()
{
  cout << endl;
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}