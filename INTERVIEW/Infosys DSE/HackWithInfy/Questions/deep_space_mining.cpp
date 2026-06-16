/*
***

### ⚔️ Blind Story-Stripping Challenge 19 (The Deep Space Run)

 **Problem: The Deep Space Mining Guild**

 You are captaining a harvesting ship flying past a dense belt of N asteroids. You are given an array `minerals`, where `minerals[i]` represents the tons of refined titanium inside the i-th asteroid.

 As you approach each asteroid, you can either hit the **[MINE]** button or the **[FLY_PAST]** button.

 **BUT (The Restriction):** Firing the mining laser generates a massive thermal signature. The moment you press **[MINE]**, your ship's systems lock down into a strict **2-Asteroid Cooling Cycle**. You are physically forced to press **[FLY_PAST]** for the next 2 consecutive asteroids before your laser is allowed to fire again.

 Find the absolute maximum tons of titanium you can harvest from the belt.

 **Constraints:**
 1 <= N <= 10^5
 1 <= minerals[i] <= 10^4

**INPUT FORMAT:**

6
10 20 15 30 5 40


**OUTPUT FORMAT:**

60

*(Explanation: You press [FLY_PAST] on the 10. You press [MINE] on the 20. The laser overheats, forcing you to [FLY_PAST] the 15 and the 30. Your system is now clear. You press [FLY_PAST] on the 5. Finally, you press [MINE] on the 40. Total = 20 + 40 = 60).*

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  /*
    States created based on buttons lit up
    STATE 1: Both Button [Mine] [fly_past] light up (Press any 1, Day 0)
    STATE 2: Only Fly_past (Day 1)
    STATE 3: Only Fly_past (Day 2)
    No further states because when clicked skip again Day 0 condition comes

    NOTE: [Fly_past] can be clicked in any state
  */
public:
  void solution(int N, vector<int> &arr)
  {
    long long ready = 0; // Mine Click
    long long lock1 = 0; // 1 Cooldown
    long long lock2 = 0; // 2 Cooldown

    // new_state = [Yesterday's Menu] + [Today's Button]

    for(int i=0; i<N; i++){
      // new_ready: Origin + Reward
      // Origin -> either lock2 or already on Ready click Fly_Past
      long long new_ready = max(ready,lock2) + 0; 
      long long new_lock1 = ready + arr[i]; // origin -> ready + reward->arr[i] Mined titanium
      long long new_lock2 = lock1 + 0; // Origin->lock1 + reward->Just Cooldown

      ready = new_ready;
      lock1 = new_lock1;
      lock2 = new_lock2;
    }

    cout<<max({ready,lock1,lock2});
  }
};

int main()
{
  Solution sol = Solution();
  int n;
  vector<int> arr;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    arr.push_back(a);
  }
  cout << "\n";
  sol.solution(n, arr);
  cout << "\n";
}
