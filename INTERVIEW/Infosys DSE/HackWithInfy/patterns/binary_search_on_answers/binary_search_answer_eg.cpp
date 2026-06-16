/*
Problem: Martian Solar Panels
You are building a solar grid on Mars. The grid consists of N solar panels in a straight row. You are given an integer array bloomDay where bloomDay[i] is the exact day that the i-th panel will be fully charged and operational.

To power the colony, you need to form exactly M functional arrays. A functional array consists of exactly K adjacent (consecutive) panels that are all fully charged.

Find the minimum number of days you need to wait so you can power the colony. If it is impossible to form M arrays of K consecutive panels, return -1.

Constraints:
1 <= N <= 10^5
1 <= M, K <= 10^5
1 <= bloomDay[i] <= 10^9
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution{
  public:
  void solution(){
    vector<int>arr={};
    int k_threshold;
    int m_functional;

    // INITIAL CONTITION CHECK: I Forgot
    long long total_panels = 1LL* m_functional * k_threshold;
    if(arr.size() < total_panels){
      cout<<"-1";
      return;
    }

    int start = 1,end = 0;
    for(auto &element:arr){
      end = max(end,element);
    }

    int best_day = -1;

    while(start <= end){
      int mid = start + (end - start)/2;
      if(is_valid(mid,k_threshold,m_functional,arr)){
        best_day = mid;
        end = mid-1;
      }else{
        start = mid+1;
      }
    }
  }
  private:
  bool is_valid(int mid, int k_threshold, int m_functional, vector<int>&arr){
    int count_arr = 0;
    int streak = 0;
    for(int i=0; i<arr.size(); i++){
      if(arr[i] <= mid){
        streak++;
        if(streak >= k_threshold){
          count_arr++;
          streak=0;
        }
      }else{
        // Reset Streak
        streak = 0;
      }
    }
    return count_arr >= m_functional;
  }
};

int main(){
  Solution sol = Solution();
  cout<<"\n";
  sol.solution();
  cout<<"\n";
}