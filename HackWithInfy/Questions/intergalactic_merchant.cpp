/*
### ⚔️ Blind Story-Stripping Challenge 22 (The Custom Sort)

Are you ready to write your own Custom Comparator? Here is a classic HackWithInfy-style problem.

 **Problem: The Intergalactic Merchant**

 You are a merchant ship captain trying to maximize your profits. There are N space stations requesting emergency supplies. You are given two arrays of size N: `weight` and `value`.
 The i-th station needs `weight[i]` tons of supplies and will pay `value[i]` galactic credits for it. 

 Your cargo ship has a maximum capacity of `W` tons.

 Unlike normal goods, these emergency supplies are highly divisible (like water or fuel). This means if you don't have enough capacity to fulfill a station's entire `weight` request, you can give them a fraction of the weight, and they will pay you the exact same fraction of the `value`.

 Find the maximum total value of credits you can earn. Output the answer as a `double` (or just rely on C++ default precision for the print).

 **Constraints:**
 1 <= N <= 10^5
 1 <= W <= 10^9
 1 <= weight[i], value[i] <= 10^5

**INPUT FORMAT:**
Line 1: N (Number of stations) and W (Max Capacity)
Line 2: N integers representing `value`
Line 3: N integers representing `weight`

**Sample Input:**

3 50
60 100 120
10 20 30

**Sample Output:**

240.0
*(Explanation: Take all of item 1 (weight 10, value 60). Take all of item 2 (weight 20, value 100). Remaining capacity = 20. Take 20/30 of item 3 (value = 20/30 * 120 = 80). Total = 60 + 100 + 80 = 240).*


*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct ValueWeight
{
  int v;
  int w;
};

bool static custom_compare(ValueWeight &a,ValueWeight &b){
  // Value/Weight
  return (double)a.v/a.w > (double)b.v/b.w;
}

class Solution{
  public:
    void solution(int n,int w,vector<int>& value,vector<int>& weight)
    {
      vector<ValueWeight>arr;
      double total_val = 0;
      for(int i=0; i<n; i++){
        arr.push_back({value[i],weight[i]});
      }
      // Sort by Vlaue/Weight Ratio
      sort(arr.begin(),arr.end(),custom_compare);

      for(int i=0; i<arr.size(); i++){
        if(w == 0)break;

        if(arr[i].w <= w){
          total_val += arr[i].v; 
          w -= arr[i].w;
        }else{
          double ratio = (double)w / arr[i].w;
          total_val += (ratio * arr[i].v);
          break;
        }
      }

      cout<<"Total Profit: "<<total_val;
    }
};

int main(){
  Solution sol = Solution();
  int n,w;
  vector<int>value,weight;
  cin>>n>>w;
  for(int i=0; i<n; i++){
    int a;
    cin>>a;
    value.push_back(a);
  }
  for(int i=0; i<n; i++){
    int a;
    cin>>a;
    weight.push_back(a);
  }
  cout<<"\n";
  sol.solution(n,w,value,weight);
  cout<<"\n";
}

