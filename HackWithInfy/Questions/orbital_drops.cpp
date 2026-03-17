/*
### ⚔️ Day 3: The Gauntlet (Story 3)

 **Problem: The Orbital Drop Pods**

 You are commanding an invasion force. You have N squads of space marines, and the i-th squad contains exactly `marines[i]` soldiers.

 You need to drop them onto a planet using standard-issue orbital drop pods. You have exactly H hours before the planetary shields activate. Every hour, you can launch exactly one drop pod.

 All drop pods must have the exact same soldier capacity, C. When a drop pod is launched, it can take soldiers from **only one squad at a time**. If a squad has more soldiers than the pod's capacity C, you will need to launch multiple pods over multiple hours to transport that entire squad. (For example, if a squad has 10 soldiers and C=3, it will take 4 hours to drop them all).

 You want to build the smallest drop pods possible to save money. Find the **minimum capacity** C the drop pods must have so that every single marine lands on the planet within H hours.

 **Constraints:**
 1 <= N <= 10^5
 N <= H <= 10^9
 1 <= marines[i] <= 10^9

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
    vector<int> marines = {};
    int H;
    int start = 1;
    long long end = 0; // START: atleast 1 soldier, END: All soldiers in 1 big pod
    for(auto &element: marines){
      end += element;
    }

    int min_possible_capacity=0;

    while(start <= end){
      int mid = start + (end - start)/2;
      if(is_valid(mid,H,marines)){
        min_possible_capacity = mid;
        end = mid - 1; // Try even smaller capacity
      }else{
        start = mid + 1;
      }
    }

  }
  private:
  bool is_valid(int C,int H, vector<int>&marines){
    int total_soldiers=0;
    long long total_hours = 0;
    for(int i=0; i<marines.size(); i++){
      total_hours += ceil((double)marines[i]/C);
    }
    return total_hours <= H;
  }
};

int main()
{
  cout << endl;
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}