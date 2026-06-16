/*
### ⚔️ Final Exam: Challenge 1 (The Alternating Sequence)

**Problem: The Alchemical Reactor**
You are an alchemist synthesizing energy over N days. You are given two redays of size N: `red_catalyst` and `blue_catalyst`. On the i-th day, you can choose to use a drop of the red catalyst (yielding `red_catalyst[i]` energy), a drop of the blue catalyst (yielding `blue_catalyst[i]` energy), or you can choose to rest the reactor (yielding `0` energy).

The reactor is highly volatile. You are strictly forbidden from using the same color catalyst two days in a row, as it will cause a meltdown. You may, however, alternate colors, or use a color after a rest day.

Find the maximum total energy you can synthesize.

**Constraints:**
1 <= N <= 10^5
-10^4 <= red\_catalyst[i], blue\_catalyst[i] <= 10^4

**INPUT FORMAT:**
Line 1: N
Line 2: N integers representing `red_catalyst`
Line 3: N integers representing `blue_catalyst`

**Sample Input:**

4
10 20 5 15
5 15 25 10

**Sample Output:**

65

*(Explanation: Red (10) -> Blue (15) -> Blue is forbidden, so Red (5)? No. Better path: Rest (0) -> Red (20) -> Blue (25) -> Red (15). Total = 60)*

***

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  void solution(int N, vector<int> &red, vector<int> &blue)
  {
    int rest = 0;
    // INITIALLY AT REST SO PICK NOTHING
    int pick_red = -1e9; 
    int pick_blue = -1e9; 

    for(int i=0; i<N; i++){
      int new_rest = max({rest,pick_red,pick_blue}) + 0 ; // Rest can be done whenever
      int new_pick_red = max(rest,pick_blue) + red[i] ; // Pick Red Only if Rested or Picked Blue
      int new_pick_blue = max(rest,pick_red) + blue[i] ;

      rest = new_rest;
      pick_red = new_pick_red;
      pick_blue = new_pick_blue;
    }

    cout<<max({rest,pick_red,pick_blue});
  }
};

int main()
{
  int N;
  cin>>N;
  vector<int>red,blue;
  for(int i=0; i<N; i++){
    int a;
    cin>>a;
    red.push_back(a);
  }
  for(int i=0; i<N; i++){
    int a;
    cin>>a;
    blue.push_back(a);
  }
  Solution sol = Solution();
  cout << endl;
  sol.solution(N,red,blue);
  cout << endl;
}