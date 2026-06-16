/*
### ⚔️ Blind Story-Stripping Challenge 6

**Problem: Interstellar Cargo Drop**
You are the logistics commander for a Mars colony. You have N massive cargo crates lined up on the dock. You are given an integer array `weights`, where `weights[i]` is the weight of the i-th crate.
You have a transport ship that will make trips between Earth and Mars for exactly D days. Every day, you load the ship with crates in the **exact order** they appear on the dock. You cannot change the order of the crates. You keep loading crates until the ship's weight limit is reached for that day, and then the ship takes off.
You want to rent the cheapest ship possible. Find the **minimum weight capacity** the ship must have so that you can successfully transport all N crates within exactly D days.
**Constraints:**
1 <= N <= 10^5
1 <= D <= 10^5
1 <= weights[i] <= 500
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
    int d_days;
    // start: max possible crate size, end: sum of all crates shipped in 1 day
    int start = 0,end = 0;
    for(int i=0; i<arr.size(); i++){
      start = max(start,arr[i]);
      end += arr[i];
    }
    int min_weight_ship;

    while(start <= end){
      int mid = start + (end - start)/2;
      if(is_valid(d_days,mid,arr)){
        min_weight_ship = mid;
        end = mid-1;
      }else{
        start = mid+1;
      }
    }

    cout<<"Min Weight Capacity: "<<min_weight_ship;
  }

  private:
  bool is_valid(int total_days,int curr_capacity_ship,vector<int>&arr){
    int curr_weight = 0;
    int curr_days = 1; // FIX: Atleast 1 day required

    for(int i=0; i<arr.size(); i++){
      curr_weight += arr[i];
      if(curr_weight > curr_capacity_ship){
        curr_days++;
        // FIX: Send Entire Crate on next day
        curr_weight =  arr[i] ; 
      }
    }

    return curr_days <= total_days;

  }
};

int main()
{
  cout << endl;
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}