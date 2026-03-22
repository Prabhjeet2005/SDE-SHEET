/*
### ⚔️ Final Exam: Challenge 2 (The Tiered Fatigue)

**Problem: The Syndicate Courier**
You are a courier smuggling data packets across N border checkpoints. You are given an array `risk_reward`, where `risk_reward[i]` is the payout for the i-th checkpoint.

At each checkpoint, you have three options:
1. **Aggressive Smuggle:** You earn the full `risk_reward[i]` payout. However, this raises the alarm. The next checkpoint will be on high alert, meaning you are strictly forbidden from doing an Aggressive Smuggle at the very next checkpoint.

2. **Covert Smuggle:** You earn exactly floor( risk_reward[i] / 2 ) (integer division by 2). This is quiet enough that you can do it as many times in a row as you want, and it lowers the alarm enough that you can step up to an Aggressive Smuggle at the next checkpoint.

3. **Lay Low:** You earn 0 payout, but it completely clears all alarms.

Find the maximum payout you can achieve.

**Constraints:**
1 <= N <= 10^5
-10^4 <= risk_reward[i] <= 10^4

**INPUT FORMAT:**
Line 1: N
Line 2: N integers representing `risk_reward`

**Sample Input:**

5
10 40 20 30 10

**Sample Output:**

90


***
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  void solution(int N, vector<int> &arr)
  {
    int lay_low = 0;
    int aggressive = -1e9;
    int covert = -1e9;

    for(int i=0; i<N; i++){
      int new_lay_low = max({lay_low,aggressive,covert}) + 0 ; // LayLow whenever
      // Aggressive only if laylow or covert previously
      int new_aggressive = max(covert,lay_low) + arr[i] ;
      int new_covert = max({lay_low, aggressive, covert}) + floor(arr[i]/2) ;

      lay_low = new_lay_low;
      aggressive = new_aggressive ;
      covert = new_covert ;
    }
    cout<<max({lay_low,covert,aggressive});
  }
};

int main()
{
  int N;
  cin >> N;
  vector<int> arr;
  for (int i = 0; i < N; i++)
  {
    int a;
    cin >> a;
    arr.push_back(a);
  }
  Solution sol = Solution();
  cout << endl;
  sol.solution(N, arr);
  cout << endl;
}