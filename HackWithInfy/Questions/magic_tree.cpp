#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
### ⚔️ Blind Story-Stripping Challenge 1
**Problem: The Magic Forest of Elves**
You are walking through a magical forest with N magical trees arranged in a straight line, numbered from 0 to N-1. You are given an array A, where each tree produces exactly A[i] magic apples per day.
The Elves of the forest are testing your intelligence. They will ask you Q questions. For each question, they give you two tree numbers, L and R. They want to know the total number of magic apples produced by all the trees from L to R (inclusive) combined.
However, there is a catch: The Elves love even numbers. If the total sum of the magic apples in that specific range is an **EVEN** number, you win exactly 1 Gold Coin for that question. If it is odd, you get 0 coins.
After all Q questions have been asked, return the total number of Gold Coins you have collected.
**Constraints:**
1 <= N <= 10^5
1 <= Q <= 10^5
0 <= L <= R < N
1 <= A[i] <= 1000
*/

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {};
    vector<vector<int>>queries={};
    int n = arr.size();
    vector<int>prefix_sum(n+1,0);
    int sum=0;
    for(int i=1; i<=n;i++){ // 1-based indexing
      sum+=arr[i-1];
      prefix_sum[i] = sum;
    }
    int gold_count = 0; // even increase by 1
    for(int i=0; i<queries.size(); i++){
      int l = queries[i][0];
      int r = queries[i][1];
      int range_sum = prefix_sum[r+1] - prefix_sum[l-1+1];
      if(range_sum%2 == 0)gold_count++;
    }
    cout<<" GOLD COUNT: "<<gold_count;
  }
};

int main()
{
  cout << endl;
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}