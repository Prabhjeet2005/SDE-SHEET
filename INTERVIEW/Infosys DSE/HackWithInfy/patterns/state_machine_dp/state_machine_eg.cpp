/*
***

### ⚔️ Blind Story-Stripping Challenge 18

 **Problem: The Firewall Bypass**

 You are an elite hacker extracting data from a corporate server. The server has N encrypted data packets in a sequence. You are given an array `data`, where `data[i]` represents the megabytes of valuable information inside the i-th packet.

 You want to extract the maximum possible amount of data.
 Every packet, you can press **[DOWNLOAD]** or **[SKIP]**.

 **BUT (The Restriction):** The corporate firewall has an anomaly detector. If you download **THREE** packets in a row, the alarm triggers and you are locked out permanently.

 To stay undetected, you can download a maximum of 2 packets in a row before you are forced to press **[SKIP]** for at least 1 packet to reset the firewall's counter.

 Find the maximum amount of data you can safely extract.

 **Constraints:**
 1 <= N <= 10^5
 1 <= data[i] <= 10^4

**INPUT FORMAT:**

5
10 20 30 40 50


**OUTPUT FORMAT:**

120

*(Explanation: Download 10 and 20. SKIP 30 to reset the firewall. Download 40 and 50. Total = 10 + 20 + 40 + 50 = 120).*
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution{
  /*
    States created based on buttons lit up
    STATE 1: Both Button [Download] [SKIP] light up (Press any 1, Day 0)
    STATE 2: Both Button Lit up but yesterday click Download (Day 1)
    STATE 3: Only [SKIP] lit up but yesterday also click Download (Day 2)
    No further states because when clicked skip again Day 0 condition comes

    NOTE: [SKIP] can be clicked in any state
  */
  public:
  void solution(int N,vector<int>&arr){
    int streak_0 = 0; // 0 Consecutive Download 
    int streak_1 = 0; // Download in streak_0
    int streak_2 = 0; // Download in streak_2

    for(int i=0; i<arr.size(); i++){
      
      int new_streak0 = max({streak_0,streak_1,streak_2}); // 0 Consecutive Download can be from any state as SKIP anytime
      int new_streak1 = streak_0 + arr[i] ; // Download in streak_0
      int new_streak2 = streak_1 + arr[i] ; // For 2 streak Download after streak1

      streak_0 = new_streak0;
      streak_1 = new_streak1;
      streak_2 = new_streak2;
    }

    cout<< max({streak_0,streak_1,streak_2});

  }
};

int main(){
  Solution sol = Solution();
  int n;
  vector<int>arr;
  cin>>n;
  for(int i=0; i<n; i++){
    int a;
    cin>>a;
    arr.push_back(a);
  }
  cout<<"\n";
  sol.solution(n,arr);
  cout<<"\n";
}