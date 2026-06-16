/*
### ⚔️ Blind Story-Stripping Challenge 21

 **Problem: The Cybernetic Grid Miner**

 You are operating a mining drone moving through a linear subterranean grid consisting of N sectors. You are given an array `ore`, where `ore[i]` represents the net value of mining the i-th sector. Note that some sectors contain hazardous gas, meaning `ore[i]` can be a negative number!

 In each sector, you can choose to extract the resources, or you can choose to skip the sector and keep moving.

 However, the drone's extraction drill is highly unstable. You cannot extract from 3 consecutive sectors. If you extract from a sector, and you also extracted from the previous sector, the drill overheats and you are physically locked out from extracting in the next sector. You must skip it to let the drill cool down.

 Find the maximum possible net value you can obtain. Note that you do not have to mine anything at all if the entire grid is hazardous.

 **Constraints:**
 1 <= N <= 10^5
 -10^4 <= ore[i] <= 10^4

**INPUT FORMAT:**

5
10 20 -5 10 20


**OUTPUT FORMAT:**

60

*/

#include<iostream>
#include<vector>
using namespace std;

class Solution{
  public:
  void solution(int N,vector<int>&arr){
    long long mine1 = -1e15; // Initially impossible to have mined
    long long mine2 = -1e15; // IMPOSSIBLE till not mine1
    long long not_mine = 0;

    for(int i=0; i<N; i++){
      long long new_mine1 = not_mine + arr[i] ;
      long long new_mine2 = mine1 + arr[i] ;
      long long new_not_mine = max({mine1,not_mine,mine2}) + 0 ;

      mine1 = new_mine1;
      mine2 = new_mine2;
      not_mine = new_not_mine;
    }

    cout<<max({mine1,mine2,not_mine});
  }
};

int main(){
  Solution sol = Solution();
  int N;
  vector<int>arr;
  cin>>N;

  for(int i=0; i<N; i++){
    int a;
    cin>>a;
    arr.push_back(a);
  }
  cout<<"\n";
  sol.solution(N,arr);
  cout<<"\n";
}


