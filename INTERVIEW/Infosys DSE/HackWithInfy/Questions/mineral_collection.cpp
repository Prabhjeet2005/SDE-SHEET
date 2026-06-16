/*
### ⚔️ Blind Story-Stripping Challenge 9

**Problem: The Martian Resource Harvester**
You are programming an automated resource harvester on Mars. You are given an array `minerals` of size N, where `minerals[i]` represents the height of a mineral pillar.
You must set the harvester's cutting blade to a specific integer height H. The harvester will fly across all the pillars. For every pillar that is strictly taller than H, the blade will chop off the top portion, and you will collect exactly `minerals[i] - H` units of minerals. If a pillar's height is less than or equal to H, you collect nothing from it.
The colony requires you to collect **at least** M units of minerals to survive the winter.
To minimize environmental damage, you must set the blade height H as **high as possible**. Find the **maximum** possible integer height H that still allows you to collect at least M units of minerals.
**Constraints:**
1 <= N <= 10^5
1 <= minerals[i] <= 10^9
1 <= M <= 10^{14}

**Example Input & Output:**
* `minerals = [20, 15, 10, 17]`
* `M = 7`

**Expected Output:** `15`

*/

#include<iostream>
#include<vector>
using namespace std;

class Solution{
  public:
  void solution(){
    vector<int> minerals = {20, 15, 10, 17 };
    long long M = 7;

    int start = 0,end = 0; // FIX: START: Lowest possible is ground i.e 0
    for(auto &element: minerals){
      end = max(end,element);
    }

    int max_possible_height=0;

    while(start <=end){
      int mid = start + (end - start)/2;
      if(is_valid(mid,M,minerals)){
        max_possible_height = mid;
        start = mid+1; // Preserve more environment
      }else{
        end = mid - 1;
      }
    }

    cout << "Max Possible Height: " << max_possible_height;
  }

  private:
  bool is_valid(int H, int M, vector<int>&minerals){
    long long resources_collected = 0; // FIX: data Type error

    for(int i=0; i<minerals.size(); i++){
      if(minerals[i] - H > 0){
        resources_collected += minerals[i] - H;
      }
    }
    return resources_collected >= M;
  }
};

int main(){
  Solution sol = Solution();
  cout<<"\n";
  sol.solution();
  cout<<"\n";
}